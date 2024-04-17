#include <iostream>

int main() {
    int num1 = 30;
    int num2 = 20;
     
    std::cout << num1<< " " << num2 << "\n";

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    std::cout << num1<< " " << num2 << "\n";
    return 0;

}