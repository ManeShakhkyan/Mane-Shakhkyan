#include <iostream>

#define MAX_SIZE 100

void matrixSum(int, int, float[][MAX_SIZE], float[][MAX_SIZE]);
void printArray(int, int, float[][MAX_SIZE]);
void inputArray(int, int, float[][MAX_SIZE]);
int inputPositiveInteger();
float inputFloat();

int main() {
    std::cout << "Enter the number of rows: ";
    int row = inputPositiveInteger();

    std::cout << "Enter the number of columns: ";
    int column = inputPositiveInteger();

    if (row > MAX_SIZE || column > MAX_SIZE) {
        std::cout << "Size exceeds maximum limit of " << MAX_SIZE << "x" << MAX_SIZE << "\n";
        return 1;
    }

    float array1[MAX_SIZE][MAX_SIZE];
    float array2[MAX_SIZE][MAX_SIZE];

    std::cout << "Enter elements of first matrix:\n";
    inputArray(row, column, array1);

    std::cout << "The first matrix is:\n";
    printArray(row, column, array1);

    std::cout << "Enter elements of second matrix:\n";
    inputArray(row, column, array2);

    std::cout << "The second matrix is:\n";
    printArray(row, column, array2);

    matrixSum(row, column, array1, array2);

    return 0;
}


void matrixSum(int row, int column, float array1[][MAX_SIZE], float array2[][MAX_SIZE]) {
    float sumArray[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            sumArray[i][j] = array1[i][j] + array2[i][j];
        }
    }

    std::cout << "Sum of matrices:\n";
    printArray(row, column, sumArray);
}

void printArray(int row, int column, float array[][MAX_SIZE]) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
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
