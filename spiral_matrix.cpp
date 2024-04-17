#include <iostream>

#define MAX_SIZE 100

void spiralPrint(int, int, float[][MAX_SIZE]);
void printArray(int, int, float[][MAX_SIZE]);
void inputArray(int, int, float[][MAX_SIZE]);
int inputPositiveInteger();
float inputFloat();

int main() {
    int row = 0; 
    int column = 0;

    std::cout << "Enter the number of rows: ";
    row = inputPositiveInteger();

    std::cout << "Enter the number of columns: ";
    column = inputPositiveInteger();

    if (row > MAX_SIZE || column > MAX_SIZE) {
        std::cout << "Size exceeds maximum limit of " << MAX_SIZE << "x" << MAX_SIZE << "\n";
        return 1;
    }

    float array[MAX_SIZE][MAX_SIZE];
    inputArray(row, column, array);

    printArray(row, column, array);

    spiralPrint(row, column, array);

    return 0;
}

void spiralPrint(int row, int column, float array[][MAX_SIZE]) {
    static int step = 0;

    if (row <= 0 || column <= 0) {
        std::cout << "\n";
        return;
    }

    if (step == 0) {
        std::cout << "Matrix elements printed in spiral order:\n";
    }

    if(step < row ){
        for (int i = step; i < column; ++i) {
          std::cout << array[step][i] << " ";
        }
    }
    
    if (step < column){
        for (int i = step + 1; i < row; ++i) {
            std::cout << array[i][column - 1] << " ";
        }
    }

    if (step < row - 1) {
        for (int i = column - 2; i >= step; --i) {
            std::cout << array[row - 1][i] << " ";
        }
    }

    if (step < column - 1) {
        for (int i = row - 2; i > step; --i) {
            std::cout << array[i][step] << " ";
        }
    }

    ++step;
    spiralPrint(row - 1, column - 1, array);
}

void inputArray(int row, int column, float array[][MAX_SIZE]) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            std::cout << "array[" << i << "][" << j << "] = ";
            array[i][j] = inputFloat();
        }
    }
    std::cout << "\n";
}

void printArray(int row, int column, float array[][MAX_SIZE]) {
    
    std::cout << "Array is: \n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

int inputPositiveInteger() {
    int num = 0;

    std::cin >> num;

    while (std::cin.fail() || num <= 0){
        std::cout << "Please enter a positive integer: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cin >> num;
    }

    return num;
}

float inputFloat() {
    float value = 0;

    std::cin >> value;

    while (std::cin.fail()){
        std::cout << "Please enter a valid float value: ";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cin >> value;
    }

    return value;
}

