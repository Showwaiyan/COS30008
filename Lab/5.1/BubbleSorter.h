
// COS30008, Tutorial 6, 2025

#pragma once

#include "ArraySorter.h"
#include <cstddef>

template <typename T, typename Order = std::greater<T>>
class BubbleSorter : public ArraySorter<T> {
private:
  Order fOrderFtn;

public:
  BubbleSorter(const T aArray[] = nullptr, size_t aSize = 0) noexcept
      : ArraySorter<T>(aArray, aSize), fOrderFtn() {}

  void sort(bool aDoLog = false,
            std::ostream &aOStream = std::cout) noexcept override {
    BubbleSorter &Array = *this;
    ArraySorter<T>::sort();
    // this->sort();
    for (size_t i = 0; i < this->size(); i++) {
      for (size_t j = 0; j < this->size() - i - 1; j++) {
        if (fOrderFtn(Array[j + 1], Array[j])) {
          this->swap(Array[j + 1], Array[j]);
        }
      }
      if (aDoLog) {
        aOStream << Array << std::endl;
      }
    }
  }
};
