#pragma once
#include <string>

class Product {
private:
  std::string fId;
  std::string fDesc;

public:
  Product();
  Product(const std::string &aId, const std::string &aDesc);
  const std::string getProductId() const;
};
