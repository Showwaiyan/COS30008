
// COS30008, Tutorial 6, 2025

#pragma once

#include "ArraySorter.h"

#include <cstddef>
#include <cstdlib>
#include <ctime>

template <typename T, typename Order = std::greater<T>>
class FisherAndYatesSorter : public ArraySorter<T> {
private:
  Order fOrderFtn;

  void shuffle() noexcept {
    FisherAndYatesSorter<T>& Array = *this;
    size_t n = this->size();
    while (n>1) {
      size_t k = std::rand() % n;
      n--;
      this->swap(Array[n],Array[k]);
    }
  }

  bool isSorted() noexcept {
    FisherAndYatesSorter<T>& Array = *this;
    for (size_t i = 0; i < Array.size()-1; i++) {
      if (!fOrderFtn(Array[i+1], Array[i])) {
        return false;
      }
    }
    return true;
  }

public:
  FisherAndYatesSorter(const T aArray[] = nullptr, size_t aSize = 0) noexcept
      : ArraySorter<T>(aArray, aSize), fOrderFtn() {
    std::srand( static_cast<unsigned int>( std::time( NULL ) ) );
  }

  void sort(bool aDoLog = false,
            std::ostream &aOStream = std::cout) noexcept override {
    ArraySorter<T>::sort();
    FisherAndYatesSorter<T>& Array = *this;
    while (true) {
      if (aDoLog) {
        aOStream << Array << std::endl;
      }
      if (isSorted()) {
        break;
      }
      shuffle();
    }
  }
};
