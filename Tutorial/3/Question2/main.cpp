#include <iostream>
int main(int argc, char *argv[]) {
  // a
  auto fWelcom = []() { std::cout << "Welcome!" << std::endl; };
  fWelcom();

  // b
  auto fAddTwo = [](int a, int b) -> int { return a + b; };
  std::cout << fAddTwo(1, 2) << std::endl;

  // c
  std::string msg = "Hello World!";
  auto fdisplay = [msg](int count) {
    while (count-- > 0) {
      std::cout << msg << std::endl;
    }
  };

  fdisplay(5);
  return 0;
}
