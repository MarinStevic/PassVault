/*
 * To add support for your keyboard layout you need to
 * add the layout locale and then what key generates
 * the same character as the US layout.
 * 
 * For example when adding the HR layout the '/' symbol
 * on the US layout corresponds with the '&' symbol on the
 * HR layout.
 */
struct KeyLayout {
  char locale[3];
  char charSet[65];
};

KeyLayout keyLayout[] = {
    {"US", "ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrst0123456789/+-*?=!#$%&()_"},
    {"HR", "ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrst0123456789&=/+_)!#$%^*(?"}
  };
