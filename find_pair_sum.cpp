#include <iostream>
//#include <iomanip>

void findPairSum (double target, int size, double array[]) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) { 
//            std::cout << array[i] << "+" << array[j] <<  "=";
//            std::cout << std::setprecision(20) << array[i] + array[j] << "\n";
            if ( array[i] + array[j] == target){
                std::cout << "(" << array[i] << ", " << array[j] << ")\n";

            }
        }
    }
}

int inputSize() {
    int size = 0;

    std::cout << "Enter the size of the array (positive integer): ";
    std::cin >> size;
    
    while (std::cin.fail() || size <= 0){
        std::cout << "Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cin >> size;
    }

    return size;
}

double inputDouble() {
    double value = 0;

    std::cin >> value;
    
    while (std::cin.fail()){
        std::cout << "Please enter a valid double value: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cin >> value;
    }

    return value;
}

void inputArray(int size, double array[]){
    for (int i = 0; i < size; ++i) {
        std::cout << "array[" << i << "] = ";
        array[i] = inputDouble();
    }
} 

int main () {
    int size = inputSize();
    
    double array[size];
    inputArray(size, array);
    
    std::cout << "Enter the target: ";
    double target = inputDouble();

    findPairSum(target, size, array);
    
    return 0;
}
