#include "ProductIndexer.h"
#include <cassert>

ProductIndexer::ProductIndexer(const Product aList[], size_t aSize)
    : fList(aList), fSize(aSize) {};

const std::string ProductIndexer::operator[](size_t aIndex) const {
  assert(aIndex < fSize);
  return fList[aIndex].getProductId();
}

const std::string ProductIndexer::operator[](const std::string &aKey) {
  assert(aKey.length() == 2);
  int lIndex = aKey[1] - '0';
  assert(lIndex < fSize);
  return fList[lIndex].getProductId();
}
