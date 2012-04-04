#include <stdint.h>


uint32_t htobel(uint32_t v) {

}

uint32_t betohl(uint32_t v) {
  uint8_t * data = &v;
  return (data[3]<<0) | (data[2]<<8) | (data[1]<<16) | (data[0]<<24);
}

uint32_t htolel(uint32_t v) {

}

uint32_t letohl(uint32_t v) {
  uint8_t * data = &v;
  return (data[3]<<0) | (data[2]<<8) | (data[1]<<16) | (data[0]<<24);
}


