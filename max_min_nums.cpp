#include <iostream>

#define MIN(a,b) (a < b ? a : b)
#define MAX(a,b) (a > b ? a : b)

int main () {
    int size = 0;
    
    while ( size <= 0){
        std::cout << "Enter the size of array (positive integer): ";
        std::cin >> size;
    }

    float array[size] = {0};

    std::cout << "array[0] = ";
    std::cin >> array[0];
    
    float min = array[0];
    float max = array[0];
    
    for (int i = 1; i < size; ++i) {
        std::cout << "array[" << i << "] = ";
        std::cin >>  array[i];
        
        min = MIN(min, array[i]);
        max = MAX(max, array[i]);
    }
 
    std::cout << "Minimum number of the array is: " << min << "\n";
    std::cout << "Maximum number of the arrat is: " << max << "\n";

    return 0;
}
