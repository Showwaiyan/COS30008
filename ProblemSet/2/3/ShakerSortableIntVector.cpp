#include "ShakerSortableIntVector.h"
#include <cstddef>

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
    : SortableIntVector(aArrayOfIntegers, aNumberOfElements)
{
}

void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{
  for (size_t i = 1; i < size(); i++) {
    for (size_t j = i-1; j < size() - i; j++) {
      if (aOrderFunction(get(j), get(j + 1))) {
        swap(j, j + 1);
      }
    }

    for (size_t j = size()-1; j > i-1; j--) {
      if (aOrderFunction(get(j-1), get(j))) {
        swap(j, j - 1);
      }
    }
  }
}
