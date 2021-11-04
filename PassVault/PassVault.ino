// Include keyboard layouts
#include "key_layout.h"

#include "mbedtls/md.h"

#include <Adafruit_NeoPixel.h>

#include <WiFi.h>

#include <HTTPSServer.hpp>
#include <SSLCert.hpp>
#include <HTTPRequest.hpp>
#include <HTTPResponse.hpp>

#include "hidkeyboard.h"

#include <ArduinoJson.h>

HIDkeyboard dev;

using namespace httpsserver;

SSLCert * cert;
HTTPSServer * secureServer;

void handleEcho(HTTPRequest* req, HTTPResponse* res);

// Replace with your network credentials
const char* ssid = "PassVault";
const char* password = "123456789";

// Secret added to the input data
const char* secret = "Change me!";

Adafruit_NeoPixel pixels(1, 36, NEO_GRB + NEO_KHZ800);

void setup() {
  WiFi.softAP(ssid, password);  // ssid, password, channel, ssidVisibility, maxClients

  cert = new SSLCert();

  int createCertResult = createSelfSignedCert(
                           *cert,
                           KEYSIZE_2048,
                           "CN=myesp.local,O=acme,C=HR");

  if (createCertResult != 0) {
    light(255, 0, 0);
    return;
  }

  secureServer = new HTTPSServer(cert);

  ResourceNode* nodeEchoPost = new ResourceNode("/", "POST", &handleEcho);

  secureServer->registerNode(nodeEchoPost);
  secureServer->start();

  while (!secureServer->isRunning()) {}

  dev.begin();

  pinMode(0, INPUT);

  pixels.begin();
  pixels.setBrightness(16);
  light(0, 255, 0);
}

void loop() {
  secureServer->loop();
  delay(1);
}

void handleEcho(HTTPRequest* req, HTTPResponse* res) {
  res->setHeader("Content-Type", "text/plain");

  byte buffer[1024];
  char payload[1024];
  byte shaResult[64];

  while (!(req->requestComplete())) {
    size_t s = req->readBytes(buffer, 1024);
    res->write(buffer, s);

    mbedtls_md_context_t ctx;
    mbedtls_md_type_t md_type = MBEDTLS_MD_SHA512;

    StaticJsonDocument<1024> doc;

    DeserializationError error = deserializeJson(doc, buffer);

    if (!error) {
      if (doc.containsKey("hostname") &&
          doc.containsKey("account") &&
          doc.containsKey("pin") &&
          doc.containsKey("length") &&
          doc.containsKey("iteration") &&
          doc.containsKey("button") &&
          doc.containsKey("layout")) {

        const char* hostname = doc["hostname"];
        const char* account = doc["account"];
        const char* pin = doc["pin"];
        int len = doc["length"];
        const char* iteration = doc["iteration"];
        int button = doc["button"];
        const char* layout = doc["layout"];

        strcpy(payload, hostname);
        strcat(payload, account);
        strcat(payload, pin);
        strcat(payload, iteration);
        strcat(payload, secret);

        const size_t payloadLength = strlen(payload);

        mbedtls_md_init(&ctx);
        mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(md_type), 0);
        mbedtls_md_starts(&ctx);
        mbedtls_md_update(&ctx, (const unsigned char*)payload, payloadLength);
        mbedtls_md_finish(&ctx, shaResult);
        mbedtls_md_free(&ctx);

        if (button) {
          light(0, 0, 255);
        }
        else {
          light(255, 0, 0);
        }

        unsigned long int start = millis();
        while (button) {
          if (millis() - start > 20000) {
            light(0, 255, 0);
            return;
          }
          if (digitalRead(0) == LOW) {
            light(255, 0, 0);
            break;
          }
        }

        int c = 0;
        for (int i = 0; i < len; i++) {
          byte p = 0;
          if (i % 4 == 0) {
            p = (int)shaResult[c * 3] >> 2;
          } else if (i % 4 == 1) {
            p = (int)shaResult[c * 3] & B11;
            p = p << 4;
            p = p | ((int)shaResult[c * 3 + 1] >> 4);
          } else if (i % 4 == 2) {
            p = (int)shaResult[c * 3 + 1] << 2;
            p = p & B00111111;
            p = p | ((int)shaResult[c * 3 + 2] >> 6);
          } else if (i % 4 == 3) {
            p = (int)shaResult[c * 3 + 2];
            p = p & B00111111;
            c++;
          }
          for (int j = 0; j < * (&keyLayout + 1) - keyLayout; j++) {
            if (!strcmp(keyLayout[j].locale, layout)) {
              dev.sendChar(keyLayout[j].charSet[(int)p]);
            }
          }
          delay(25);
        }
      }
      else {
        return;
      }
    }
    light(0, 255, 0);
  }
}

void light(int red, int green, int blue) {
  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.show();
}
