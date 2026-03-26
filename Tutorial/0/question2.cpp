#include <iostream>

int main() {
  float weight, height;

  do {
    std::cout << "Enter your weight: ";
    std::cin >> weight;
  } while (weight < 1);

  do {
    std::cout << "Enter your height: ";
    std::cin >> height;
  } while (height < 1);

  float bmi = weight / (height * height);

  if (bmi > 29.9)
    std::cout << "Obese" << std::endl;
  else if (bmi > 24.9)
    std::cout << "Overweight" << std::endl;
  else if (bmi > 18.4)
    std::cout << "Normal" << std::endl;
  else
    std::cout << "Underweight" << std::endl;

  return 0;
}
