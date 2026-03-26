#include <iostream>
void printIntArray(int aArray[], size_t aSize) {
  std::cout << "[";

  for (int i = 0; i < aSize; i++) {
    std::cout << aArray[i] << ((i != aSize - 1) ? "," : "");
  }

  std::cout << "]" << std::endl;
}
