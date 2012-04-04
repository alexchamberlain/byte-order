#include <stdint.h>


uint32_t htobel(uint32_t v) {
  uint32_t ret;
  uint8_t * data = &ret;

  data[0] = v/(2 << 24);
  v %= (2 << 24);
  data[1] = v/(2 << 16);
  v %= (2 << 16);
  data[2] = v/(2 <<  8);
  v %= (2 <<  8);
  data[3] = v/(2 <<  0);
  v %= (2 <<  0);

  return ret;
}

uint32_t betohl(uint32_t v) {
  uint8_t * data = &v;
  return (data[3]<<0) | (data[2]<<8) | (data[1]<<16) | (data[0]<<24);
}

uint32_t htolel(uint32_t v) {
  uint32_t ret;
  uint8_t * data = &ret;

  data[0] = v/(2 << 24);
  v %= (2 << 24);
  data[1] = v/(2 << 16);
  v %= (2 << 16);
  data[2] = v/(2 <<  8);
  v %= (2 <<  8);
  data[3] = v/(2 <<  0);
  v %= (2 <<  0);

  return ret;
}

uint32_t betohl(uint32_t v) {
  uint8_t * data = &v;
}

uint32_t letohl(uint32_t v) {
  uint8_t * data = &v;
  return (data[3]<<0) | (data[2]<<8) | (data[1]<<16) | (data[0]<<24);
}


