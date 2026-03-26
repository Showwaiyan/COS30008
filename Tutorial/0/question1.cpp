#include <iostream>
#include <ostream>

int main() {
  float grade, test_score;
  do {
    std::cout << "Enter Grade Point: ";
    std::cin >> grade;
  } while (grade < 1.0 || grade > 4.0);

  do {
    std::cout << "Enter Admission test score: ";
    std::cin >> test_score;
  } while (test_score < 0 || test_score > 100);

  if ((grade >= 3.0 && test_score >= 60) || (grade < 3.0 && test_score >= 80)) {
    std::cout << "Accept" << std::endl;
  } else
    std::cout << "Reject" << std ::endl;

  return 0;
}
