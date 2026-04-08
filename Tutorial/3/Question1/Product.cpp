#include "Product.h"

Product::Product() : fId(""), fDesc("") {}

Product::Product(const std::string &aId, const std::string &aDesc)
    : fId(aId), fDesc(aDesc) {}

const std::string Product::getProductId() const { return fId; }
