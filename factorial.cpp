#include <iostream>

int main() {
    int number = 0;
    int factorial = 1;

    do {
        std::cout << "Enter a non-negative integer: ";
        std::cin >> number;
    } while( number < 0);
    
    for(int i = number; i > 0; --i) {
        factorial *= i;
    }

    std::cout << "Factorial of " << number << " is: " << factorial << "\n";

    return 0;
}
