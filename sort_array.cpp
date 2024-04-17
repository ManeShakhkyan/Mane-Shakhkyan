#include <iostream>

void inputArray(int size, double array[]){
    for (int i = 0; i < size; ++i) {
        std::cout << "array[" << i << "] = ";
        std::cin >> array[i];
    }
} 

void printArray(int size, double array[]){
    for ( int i = 0; i < size; ++i){
        std::cout << array[i] << ", ";
    }

    std::cout << "\n";
}

void sortArray(int size, double array[]){
    for(int i=0; i < size; ++i){
        for(int j=i+1; j< size; ++j){
            if (array[j] < array[i]){
                array[j] = array[j] + array[i];
                array[i] = array[j] - array[i];
                array[j] = array[j] - array[i];
            }
        }
    }
}

int main () {
    int size = 0;
    
    while (size <= 0){
        std::cout << "Enter the size of array (positive integer): ";
        std::cin >> size;
    }

    double array[size] = {0};

    inputArray(size, array);

    std::cout << "Inputted array is: ";
    printArray(size, array);

    sortArray(size, array);

    std::cout << "Sorted array is: ";
    printArray(size, array);
    
    return 0;
}
