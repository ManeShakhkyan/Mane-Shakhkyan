#include <iostream>

int main () {
    int rows = 0;

    while (rows <= 0){
        std::cout << "Enter the count of rows(positive integer): ";
        std::cin >> rows;
    }

    std::cout << "-------------------------\n";

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j <= i; ++j){
            std::cout << "* ";
        }
        
        std::cout << "\n";
    }

    std::cout << "-------------------------\n";
    
    for (int i = 0; i < rows; ++i) {
        for (int j = rows - i - 1; j > 0; --j) {
            std::cout << "  ";
        }

        for ( int k = 0; k <= i; ++k) {
            std::cout << "* ";
        }
    
        std::cout << "\n";
    }

    std::cout << "-------------------------\n";

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < rows - i - 1; ++j) {
            std::cout << " ";
        }        
        
        for (int k = 0; k <= i; ++k){
                std::cout << "* ";
        }

        std::cout << "\n";
    }

    return 0;
}
