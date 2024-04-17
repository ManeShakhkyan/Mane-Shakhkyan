#include <iostream>

int main () {
    int number = 0;
    int divisor = 1;
    int first_digit = 0;
    int last_digit = 0;
    
    std::cout << "Enter the number please: ";
    std::cin >> number;

    if (number < 0) {
        number = -number;
    }

    while ( number / divisor >= 10){
        divisor *= 10;
    }

    while( divisor > 0 ) {
        last_digit = number % 10;
        first_digit = number / divisor;

        if ( last_digit != first_digit) { 
            std::cout <<"Number isn't palindrome!\n"; 
            return 0;
        }
        
        number %= divisor;
        number /= 10;
        divisor /= 100;
    }

    std::cout << "Number is paliindrome!\n";

    return 0;
}
