#include <iostream>
class JobBid {
private:
  int bidNumber;
  double quotedPrice;

public:
  friend std::ostream &operator<<(std::ostream &aOut, const JobBid &obj);
  friend std::istream &operator>>(std::istream &aIn, JobBid &obj);

  bool operator<(const JobBid obj) {
    return this->quotedPrice < obj.quotedPrice;
  }
};

std::ostream &operator<<(std::ostream &aOut, const JobBid &obj) {
  aOut << "Bid Number: ";
  aOut << obj.bidNumber << std::endl;
  aOut << "Quoted Price: ";
  aOut << obj.quotedPrice << std::endl;
  return aOut;
}

std::istream &operator>>(std::istream &aIn, JobBid &obj) {
  if (&aIn == &std::cin) {
    std::cout << "Enter bid: ";
  }
  aIn >> obj.bidNumber;
  if (&aIn == &std::cin) {
    std::cout << "Enter Quoted: ";
  }
  aIn >> obj.quotedPrice;
  return aIn;
}

int main(int argc, char *argv[]) {
  JobBid j1, j2;
  std::cin >> j1;
  std::cin >> j2;

  if (j1 < j2) {
    std::cout << j1;
  } else {
    std::cout << j2;
  }

  return 0;
}
