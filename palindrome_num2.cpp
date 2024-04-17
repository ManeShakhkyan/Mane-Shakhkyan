#include <iostream>

int main() {
    int number = 0;
    int reversed_num = 0;
    
    std::cout << "Enter the number please: ";
    std::cin >> number;

    int temp = number;

    while (temp != 0) {
        reversed_num = reversed_num * 10 + temp % 10;
        temp /= 10;
    }

    if( reversed_num == number ){
        std::cout << number << " is paliindrome!\n";
    } else {
        std::cout << number << " isn't paliindrome!\n";
    }
    return 0;   
}

