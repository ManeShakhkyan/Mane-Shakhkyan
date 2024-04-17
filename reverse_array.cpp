#include <iostream>

void reverseCharArray(int size, char array[]) {
    char current = array[0];

    for (int i = 0; i < size / 2; ++i) {
        current = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = current;
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

void inputArray(int size, char array[]) {
    std::cout << "Enter " << size << " characters: ";
   
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

void printArray(int size, char array[]) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << "\n";
}

int main() {
    int size = inputSize() + 1;

    char array[size];

    inputArray(size, array);

    std::cout << "Original array: ";
    printArray(size, array);

    reverseCharArray(size, array);

    std::cout << "Reversed array: ";
    printArray(size, array);
//    std::cout << array<< "\n";
    return 0;
}
