#include <iostream>
#include "byte-order.h"


int main(int argc, char** argv) {
  const uint32_t v = 134480385;
  std::cout << std::hex << v << std::endl;
  std::cout << htole(v) << std::endl;
  std::cout << htobe(v) << std::endl;

  return 0;
}
