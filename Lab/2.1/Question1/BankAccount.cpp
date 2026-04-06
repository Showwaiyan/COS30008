#include "BankAccount.h"
#include <iostream>
#include <string>

int BankAccount::accountNumberGenerated = 0;

BankAccount::BankAccount() noexcept : balance(0) {
  this->accountNumber = std::to_string(accountNumberGenerated++);
}

std::ostream &operator<<(std::ostream &aOStream, BankAccount aBankAccount) {
  aOStream << "Bank Number: ";
  aOStream << aBankAccount.accountNumber << std::endl;
  aOStream << "Total Balance: ";
  aOStream << aBankAccount.balance << std::endl;

  return aOStream;
}

double BankAccount::operator+(double aDeposite) {
  if (aDeposite < 0)
    std::cerr << "Depositve value must be non-zero and positive";
  this->balance += aDeposite;
  return this->balance;
}

bool BankAccount::operator>(BankAccount aOtherAccount) {
  return this->balance > aOtherAccount.balance;
}

bool BankAccount::operator<(BankAccount aOtherAccount) {
  return this->balance < aOtherAccount.balance;
}

bool BankAccount::operator==(BankAccount aOtherAccount) { 
  return this->accountNumber == aOtherAccount.accountNumber;
}
