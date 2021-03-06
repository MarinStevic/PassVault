#ifndef CERT_H_
#define CERT_H_
unsigned char example_crt_DER[] = {
  0x30, 0x82, 0x02, 0x18, 0x30, 0x82, 0x01, 0x81, 0x02, 0x01, 0x02, 0x30,
  0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b,
  0x05, 0x00, 0x30, 0x54, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04,
  0x06, 0x13, 0x02, 0x44, 0x45, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55,
  0x04, 0x08, 0x0c, 0x02, 0x42, 0x45, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03,
  0x55, 0x04, 0x07, 0x0c, 0x06, 0x42, 0x65, 0x72, 0x6c, 0x69, 0x6e, 0x31,
  0x12, 0x30, 0x10, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x09, 0x4d, 0x79,
  0x43, 0x6f, 0x6d, 0x70, 0x61, 0x6e, 0x79, 0x31, 0x13, 0x30, 0x11, 0x06,
  0x03, 0x55, 0x04, 0x03, 0x0c, 0x0a, 0x6d, 0x79, 0x63, 0x61, 0x2e, 0x6c,
  0x6f, 0x63, 0x61, 0x6c, 0x30, 0x1e, 0x17, 0x0d, 0x32, 0x31, 0x30, 0x33,
  0x30, 0x33, 0x32, 0x32, 0x33, 0x37, 0x31, 0x39, 0x5a, 0x17, 0x0d, 0x33,
  0x31, 0x30, 0x33, 0x30, 0x31, 0x32, 0x32, 0x33, 0x37, 0x31, 0x39, 0x5a,
  0x30, 0x55, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
  0x02, 0x44, 0x45, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x08,
  0x0c, 0x02, 0x42, 0x45, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x03, 0x55, 0x04,
  0x07, 0x0c, 0x06, 0x42, 0x65, 0x72, 0x6c, 0x69, 0x6e, 0x31, 0x12, 0x30,
  0x10, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x09, 0x4d, 0x79, 0x43, 0x6f,
  0x6d, 0x70, 0x61, 0x6e, 0x79, 0x31, 0x14, 0x30, 0x12, 0x06, 0x03, 0x55,
  0x04, 0x03, 0x0c, 0x0b, 0x65, 0x73, 0x70, 0x33, 0x32, 0x2e, 0x6c, 0x6f,
  0x63, 0x61, 0x6c, 0x30, 0x81, 0x9f, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86,
  0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x81, 0x8d,
  0x00, 0x30, 0x81, 0x89, 0x02, 0x81, 0x81, 0x00, 0xdd, 0xfd, 0xc1, 0x90,
  0x7f, 0x6c, 0xf7, 0x25, 0x4b, 0xa7, 0x0a, 0xc7, 0x33, 0x56, 0xb8, 0x85,
  0xa3, 0x44, 0xa4, 0x99, 0x33, 0xe2, 0x3c, 0x89, 0xe6, 0xb2, 0xec, 0x74,
  0x06, 0x51, 0x7f, 0xa6, 0x62, 0x4f, 0x48, 0xb5, 0x30, 0x13, 0xb9, 0xb2,
  0x8f, 0x14, 0x87, 0x99, 0xb4, 0xf9, 0xb1, 0x42, 0xcd, 0xeb, 0x27, 0x17,
  0xb4, 0x9a, 0xde, 0xb4, 0x0f, 0x33, 0xef, 0x3d, 0x1b, 0xd8, 0xec, 0x14,
  0xf6, 0x1c, 0x00, 0xdc, 0x2e, 0xcc, 0xd7, 0xcc, 0x2c, 0x22, 0x02, 0xba,
  0xac, 0x3b, 0xc1, 0x99, 0x1b, 0x2a, 0x03, 0x2b, 0x1f, 0xba, 0x9e, 0x44,
  0xdd, 0xad, 0x17, 0xf5, 0x43, 0x82, 0x2f, 0x65, 0x7c, 0x47, 0x46, 0x11,
  0x21, 0x1f, 0xe3, 0x31, 0x8f, 0x2b, 0xc9, 0x6b, 0xde, 0x1c, 0xc7, 0xfe,
  0x69, 0x86, 0xf4, 0x77, 0x44, 0x0f, 0x36, 0x0d, 0x2f, 0x13, 0x22, 0x86,
  0xb3, 0x6e, 0x64, 0xad, 0x02, 0x03, 0x01, 0x00, 0x01, 0x30, 0x0d, 0x06,
  0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00,
  0x03, 0x81, 0x81, 0x00, 0x93, 0x5f, 0xae, 0x42, 0x6d, 0xd5, 0xb5, 0x4b,
  0x70, 0x45, 0x58, 0x56, 0xac, 0xb9, 0xc3, 0xe0, 0x8f, 0x01, 0x66, 0x9b,
  0x10, 0x8c, 0x61, 0xd7, 0xf4, 0xed, 0x33, 0x9a, 0x24, 0xb4, 0xd2, 0x57,
  0x66, 0xc6, 0x77, 0x42, 0xc9, 0x4b, 0xd2, 0x13, 0x4e, 0xfe, 0x18, 0x37,
  0x93, 0xab, 0xd9, 0xfd, 0x3e, 0x02, 0xe8, 0x03, 0xfa, 0x16, 0x4c, 0xcd,
  0x77, 0xfc, 0x90, 0x0f, 0x19, 0x51, 0xfa, 0xc9, 0xf6, 0xb3, 0xc7, 0x26,
  0x6f, 0x7b, 0xa1, 0x2a, 0x42, 0xe8, 0x91, 0x3d, 0x76, 0x21, 0x87, 0xaa,
  0xe3, 0x5b, 0x38, 0x6c, 0x28, 0x36, 0x80, 0x43, 0xcd, 0xd7, 0xd6, 0xcf,
  0x06, 0x36, 0xfa, 0xa1, 0x5b, 0xef, 0x53, 0xfd, 0xc4, 0x0d, 0xf2, 0xa4,
  0x32, 0xea, 0xb4, 0xd9, 0x8d, 0x35, 0x86, 0xcf, 0x58, 0x0d, 0xf4, 0x4f,
  0x20, 0xfc, 0x6e, 0x5f, 0x32, 0xd0, 0x33, 0x19, 0xb4, 0xf7, 0x95, 0xea
};
unsigned int example_crt_DER_len = 540;
#endif
