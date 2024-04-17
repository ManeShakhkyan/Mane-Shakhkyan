#include <iostream>

int main () {
    int n = 0;
    
    while ( n <= 0){
        std::cout << "Enter the limit for Fibonacci numbers (positive integer): ";
        std::cin >> n;
    }

    int f_arr[n] = {1, 1};
    
    std::cout << f_arr[0] << "\n";

    if ( n >= 2){
        std::cout << f_arr[0] << " " << f_arr[1] << "\n";
    }
    
    for (int i = 2; i < n; ++i) {
        f_arr[i] = f_arr[i - 2] + f_arr[i - 1];
    
        for (int j = 0; j <= i; ++j) {       
               std::cout << f_arr[j] << " "; 
        }

        std::cout << "\n";
    }

    return 0;
}
