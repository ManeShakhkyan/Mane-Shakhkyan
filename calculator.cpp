#include <iostream>

int main() {
    double num1 = 0;
    double num2 = 0;
    char operation = '+';

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
    std::cout << "Enter the operator (+,-,*,/): ";
    std::cin >> operation;

    switch(operation) {
        case '+':
            std::cout << num1 << "+" << num2 << "=" << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << num1 << "-" << num2 << "=" << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << num1 << "*" << num2 << "=" << num1 * num2 << "\n";
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Cannot divide by zero!\n";
            }
            else{
                std::cout << num1 << "/" << num2 << "=" << num1 / num2 << "\n";
            }
            break;
        default:
            std::cout << "Invalid operator!\n";
    }

    return 0;
}

