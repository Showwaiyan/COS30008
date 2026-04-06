#pragma once

#include <ostream>
#include <string>
class BankAccount {
  // Fields
  public:
    std::string accountNumber;
    double balance;

  protected:
    static int accountNumberGenerated;

  // Methods
  public:
    BankAccount() noexcept;
    friend std::ostream& operator<<(std::ostream& aOStream, BankAccount aBankAccount); // need to show bank account information
    double operator+(double aDeposite);
    bool operator>(BankAccount aOtherAccount);
    bool operator<(BankAccount aOtherAccount);
    bool operator==(BankAccount aOtherAccount);
};
