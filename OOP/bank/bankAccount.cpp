#include <iostream>
#include <cstring>
#include "bankAccount.hpp"

unsigned int BankAccount::accountCount = 0;
float BankAccount::totalBalanceAMD = 0.0;
float BankAccount::totalBalanceEUR = 0.0;
float BankAccount::totalBalanceUSD = 0.0;
float BankAccount::totalBalanceRUB = 0.0;

//Check validations

bool BankAccount::isValidPassId(const char* passId) {
    if (!((passId[0] >= 'A' && passId[0] <= 'Z') && (passId[1] >= 'A' && passId[1] <= 'Z'))) {
        return false;
    }

    for (int i = 2; i < ID_NUMS_COUNT; ++i) {
        if (passId[i] < '0' || passId[i] > '9') {
            return false;
        }
    }

    return true;
}



bool BankAccount::isValidAccountNum(int accountNum[ACC_NUMS_COUNT]){
    for(int i = 0; i < ACC_NUMS_COUNT; ++i){
        if (accountNum[i] < 0 || accountNum[i] > 9){
            return false;
        }
    }

    return true;
}

bool BankAccount::isValidSurName(const char* SurName){
    for (int i = 0; SurName[i] != '\0'; ++i) {
        if (!((SurName[i] >= 'A' && SurName[i] <= 'Z') || (SurName[i] >= 'a' && SurName[i] <= 'z'))) {
            return false;
        }
    }
    return true;
}


bool BankAccount::isValidBalance(float balance){
    if(balance < 0){
        return false;
    }

    return true;
}

//Constructors

BankAccount::BankAccount(){
    name = nullptr;
    surname = nullptr;
    passId = nullptr;
    balanceAMD = 0.0;
    balanceEUR = 0.0;
    balanceUSD = 0.0;
    balanceRUB = 0.0;
    for(int i = 0; i < ACC_NUMS_COUNT; ++i){
        accountNum[i] = 0;
    }
    ++accountCount;
}

BankAccount::BankAccount(const char* name, const char* surname, const char* passId, int accountNumParam[ACC_NUMS_COUNT], float balanceAMD, float balanceEUR, float balanceUSD, float balanceRUB) :
             name(nullptr), surname(nullptr), passId(nullptr), balanceAMD(0.0), balanceEUR(0.0), balanceUSD(0.0), balanceRUB(0.0) { 
    if (isValidSurName(name)) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    if (isValidSurName(surname)) {
        this->surname = new char[strlen(surname) + 1];
        strcpy(this->surname, surname);
    }

    if (isValidPassId(passId)) {
        this->passId = new char[strlen(passId) + 1];
        strcpy(this->passId, passId);
    }
        
    this->balanceAMD = isValidBalance(balanceAMD) ? balanceAMD : 0.0;
    totalBalanceAMD += balanceAMD;

    this->balanceEUR = isValidBalance(balanceEUR) ? balanceEUR : 0.0;
    totalBalanceEUR += balanceEUR;

    this->balanceUSD = isValidBalance(balanceUSD) ? balanceUSD : 0.0;
    totalBalanceUSD += balanceUSD;

    this->balanceRUB = isValidBalance(balanceRUB) ? balanceRUB : 0.0;
    totalBalanceRUB += balanceRUB;
        
    if(isValidAccountNum(accountNumParam)){
        for(int i = 0; i < ACC_NUMS_COUNT; ++i){
            this->accountNum[i] = accountNumParam[i];
        }
    }

    ++accountCount;
    }

// Destructor

BankAccount::~BankAccount() {
    --accountCount;
    totalBalanceAMD -= balanceAMD;
    totalBalanceEUR -= balanceEUR;
    totalBalanceRUB -= balanceRUB;
    totalBalanceUSD -= balanceUSD;

    if (name) {
       delete[] name;
    }
            
    if (surname) {
        delete[] surname;
    }

    if (passId){
        delete[] passId;
    }
}

// Get functions

const char* BankAccount::getName() {
    return name ? name : "No name";
}

const char* BankAccount::getSurname() {
    return surname ? surname : "No surname";
}

const char* BankAccount::getPassId() {
    return passId ? passId : "No passId";
}

float BankAccount::getBalanceAMD() {
    return balanceAMD;
}

float BankAccount::getBalanceEUR() {
    return balanceEUR;
}

float BankAccount::getBalanceUSD() {
    return balanceUSD;
}

float BankAccount::getBalanceRUB() {
    return balanceRUB;
}

void BankAccount::getBalance() {
    std::cout << "AMD: " << balanceAMD << " ֏\n";
    std::cout << "EUR: " << balanceEUR << " €\n";
    std::cout << "USD: " << balanceUSD << " $\n";
    std::cout << "RUB: " << balanceRUB << " ₽\n";
}

float BankAccount::getTotalBalanceAMD() {
    return totalBalanceAMD;
}
        
float BankAccount::getTotalBalanceEUR() {
    return totalBalanceEUR;
}
        
float BankAccount::getTotalBalanceUSD() {
    return totalBalanceUSD;
}
        
float BankAccount::getTotalBalanceRUB() {
    return totalBalanceRUB;
}

void BankAccount::getTotalBalance() {
    std::cout << "Total AMD: " << totalBalanceAMD << " ֏\n";
    std::cout << "Total EUR: " << totalBalanceEUR << " €\n";
    std::cout << "Total USD: " << totalBalanceUSD << " $\n";
    std::cout << "Total RUB: " << totalBalanceRUB << " ₽\n";
}
        
int* BankAccount::getAccountNum() {
    return accountNum;
}

void BankAccount::getAllInfo(){
    std::cout << "Name : " << getName() << "\n";
    std::cout << "Surname : " << getSurname() << "\n";
    std::cout << "Passport ID : " << getPassId() << "\n";
    std::cout << "Account Numbers : ";
    for(int i = 0; i < ACC_NUMS_COUNT; ++i){
        std::cout << accountNum[i];
    }
    std::cout << "\nBalances :\n";
    getBalance();
}
        
unsigned int BankAccount::getAccountCount() {
    return accountCount;
}

// Set functions

bool BankAccount::setPassId(const char* passId) {
    if(!isValidPassId(passId)){
        return false;
    }
    
    if(this->passId){
        delete[] this->passId;
    }

    this->passId = new char[strlen(passId) + 1];
    std::strcpy(this->passId, passId);

    return true;
}

bool BankAccount::setBalanceAMD(float balance) {
    if(!isValidBalance(balance)){
        return false;
    }

    totalBalanceAMD -= this->balanceAMD;
    this->balanceAMD = balance; 
    totalBalanceAMD += this->balanceAMD;

    return true;
}

bool BankAccount::setBalanceEUR(float balance) {
    if(!isValidBalance(balance)){
        return false;
    }
    
    totalBalanceEUR -= this->balanceEUR;
    this->balanceEUR = balance;
    totalBalanceEUR += this->balanceEUR;
    
    return true;
}

bool BankAccount::setBalanceUSD(float balance) {
    if(!isValidBalance(balance)){
        return false;
    }
    
    totalBalanceUSD -= this->balanceUSD;
    this->balanceUSD = balance;
    totalBalanceUSD += totalBalanceUSD;
    
    return true;
}

bool BankAccount::setBalanceRUB(float balance) {
    if(!isValidBalance(balance)){
        return false;
    }
    
    totalBalanceRUB -= this->balanceRUB;
    this->balanceRUB = balance;
    totalBalanceRUB += this->balanceRUB;
    
    return true;
}
