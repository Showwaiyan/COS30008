#include <iostream>
#include <ostream>
#include <string>
class Meal {
public:
  std::string name; int calorie; Meal(std::string aName, int aCalorie) : name(aName), calorie(aCalorie) {}; friend std::istream &operator>>(std::istream &, Meal); friend std::ostream &operator>>(std::ostream &, Meal);
};

std::istream &operator>>(std::istream &aIn, Meal obj) {
  std::cout << "Enter Meal's Name: ";
  aIn >> obj.name;

  std::cout << "Enter Calorie: ";
  aIn >> obj.calorie;

  return aIn;
}

std::ostream &operator>>(std::ostream &aOut, Meal obj) {
  aOut << "Name: " << obj.name << std::endl;
  aOut << "Calorie: " << obj.calorie << std::endl;

  return aOut;
}

int main(int argc, char *argv[]) { 


}
