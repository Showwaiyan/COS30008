#pragma once
#include "Product.h"

class ProductIndexer {
private:
  const Product *fList;
  size_t fSize;

public:
  ProductIndexer(const Product aList[], size_t aSize);
  const std::string operator[](size_t aIndex) const;
  const std::string operator[](const std::string &aKey);
};

