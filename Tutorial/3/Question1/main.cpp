#include <iostream>
#include "Product.h"
#include "ProductIndexer.h"

int main() {
  Product lProducts[] = {
    Product("P1", "Product 1"),
    Product("P2", "Product 2"),
    Product("P3", "Product 3"),
    Product("P4", "Product 4"),
    Product("P5", "Product 5"),
    Product("P6", "Product 6"),
    Product("P7", "Product 7"),
    Product("P8", "Product 8"),
    Product("P9", "Product 9"),
    Product("P0", "Product 0")
  };

  ProductIndexer indexer(lProducts, 10);

  std::cout << "Testing ProductIndexer by index:" << std::endl;
  for (size_t i = 0; i < 10; i++) {
    std::cout << "Product[" << i << "]: " << indexer[i] << std::endl;
  }

  std::cout << "\nTesting ProductIndexer by key:" << std::endl;
  for (size_t i = 0; i < 10; i++) {
    std::string key = "P" + std::to_string(i);
    std::cout << "Product['" << key << "']: " << indexer[key] << std::endl;
  }

  return 0;
}
