#include <iostream>

int main () {
    int count = 0;
    float max_num = 0;
    float current_num = 0;

    std::cout << "How many numbers will you enter? ";
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        std::cout << "Enter the number N" << i + 1 << ": ";
        std::cin >> current_num;
        
        if (current_num > max_num || i == 0) {
            max_num = current_num;
        }
    }

    std::cout << "Maximum number entered is "<< max_num << "!\n";

    return 0;
}