#include <iostream>
#include "bankAccount.hpp"

int main() {
    int accountNum1[ACC_NUMS_COUNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7};
    int accountNum2[ACC_NUMS_COUNT] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7};

    BankAccount account1("Tom", "Cruise", "AB1234567", accountNum1, 1000, 2000, 3000, 4000);
    BankAccount account2("Johnny", "Depp", "AV9876543", accountNum2, 500, 1000, 1500, 2000);

    std::cout << "Account 1 Information:" << "\n";
    account1.getAllInfo();

    std::cout << "\nAccount 2 Information:" << "\n";
    account2.getAllInfo();

    std::cout << "\nTotal Balances:" << "\n";
    BankAccount::getTotalBalance();

    std::cout << "\nModified Balances:" << "\n";
    std::cout << "Account 1:" << "\n";
    account1.setBalanceAMD(account1.getBalanceAMD() + 500);
    account1.getBalance();
    
    std::cout << "Account 2:" << "\n";
    account2.setBalanceEUR(account2.getBalanceEUR() + 200);
    account2.getBalance();

    std::cout << "\nTotal Balances:" << "\n";
    BankAccount::getTotalBalance();

    return 0;
}
