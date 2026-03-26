#include <iostream>

int main () {
  unsigned int input = -1;
  unsigned int largest = 0;

  do {
    std::cout << "Enter positive integer: ";

    if (!(std::cin >> input)) {
      std::cout << "Please write only positive interger"<< std::endl;
      continue;
    }
    
    if (input > largest) largest = input;

  }while (input != 0);

  std::cout << "Largest number: " << largest << std::endl;
  return 0;
}
