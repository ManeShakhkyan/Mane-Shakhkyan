#include <iostream>

int main() {
    int number = 0;
    int reversed_num = 0;
    
    std::cout << "Enter the number please: ";
    std::cin >> number;

    while (number != 0) {
        reversed_num = reversed_num * 10 + number % 10;
        number /= 10;
    }

    std::cout << "Reversed num is: " << reversed_num << "\n";

    return 0;
}

