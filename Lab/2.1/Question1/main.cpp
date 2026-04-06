#include "BankAccount.h"
#include <iostream>

int main() {
    BankAccount account1;
    BankAccount account2;

    account1.operator+(100.0);
    account2.operator+(50.0);

    std::cout << "=== Bank Account Test ===" << std::endl;
    std::cout << "Account 1:" << std::endl;
    std::cout << account1 << std::endl;
    std::cout << "Account 2:" << std::endl;
    std::cout << account2 << std::endl;

    std::cout << "\n=== Comparison Test ===" << std::endl;
    if (account1 > account2) {
        std::cout << "Account 1 has greater balance than Account 2" << std::endl;
    }
    if (account2 < account1) {
        std::cout << "Account 2 has less balance than Account 1" << std::endl;
    }

    std::cout << "\n=== Equality Test ===" << std::endl;
    if (account1 == account2) {
        std::cout << "Account 1 and Account 2 have the same account number" << std::endl;
    } else {
        std::cout << "Account 1 and Account 2 have different account numbers" << std::endl;
    }

    return 0;
}
