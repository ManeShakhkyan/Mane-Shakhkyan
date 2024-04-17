#include <iostream>

int main() {
    int number = 0;

    std::cout << "Enter the number: ";
    std::cin >> number;

    if ( number % 2 == 0 ){
        std::cout << number << " is an even number!\n";
    } else {
        std::cout << number << " is an odd number!\n";
    }

    return 0;
}