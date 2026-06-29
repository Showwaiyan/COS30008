
// COS30008, Tutorial 6, 2025

#pragma once

#include <cassert>
#include <cstdint>
#include <iostream>

template <typename T> 
class ArraySorter {
public:
  ArraySorter(const T aArray[] = nullptr, size_t aSize = 0) noexcept
      : fSize(aSize), fSwapCount(0) {
    fElements = new T[fSize];
    for (size_t i = 0; i<size(); i++) {
      fElements[i] = aArray[i];
    }
  }

  virtual ~ArraySorter() noexcept {
    delete[] fElements;
  }

  size_t size() const noexcept {
    return fSize;
  }
  size_t swapCount() const noexcept {
    return fSwapCount;
  }

  void swap(T &aLeft, T &aRight) noexcept {
    T temp = aLeft; 
    aLeft = aRight;
    aRight = temp;
    fSwapCount++;
  }

  T &operator[](size_t aIndex) const noexcept {
    return const_cast<T&>(fElements[aIndex]);
  }

  virtual void sort(bool aDoLog = false,
                    std::ostream &aOStream = std::cout) noexcept {
    fSwapCount = 0;
  }

  friend std::ostream &operator<<(std::ostream &aOStream,
                                  const ArraySorter &aSorter) {
    aOStream << "[";
    for (size_t i = 0; i < aSorter.fSize; ++i) {
      aOStream << aSorter[i];
      if (i < aSorter.fSize - 1) {
        aOStream << ", ";
      }
    }
    aOStream << "]";
    return aOStream;
  }

private:
  T *fElements;
  size_t fSize;
  size_t fSwapCount;
};
