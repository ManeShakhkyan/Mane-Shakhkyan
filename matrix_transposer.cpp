#include <iostream>

#define MAX_SIZE 100

void transposerMatrix(int, int, float[][MAX_SIZE]);
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

    std::cout << "Array is: \n";
    printArray(row, column, array);

    transposerMatrix(row, column, array);

    return 0;
}

void transposerMatrix(int row, int column, float array[][MAX_SIZE]) {
    float current = array[0][0];
    
    if (row == column){
        for (int i = 0; i < row; ++i) {
            for (int j = i + 1; j < column; ++j) {
                current = array[i][j];
                array[i][j] = array[j][i];
                array[j][i] = current;
            }
        }

        std::cout << "Matrix after transposition:\n";
        printArray(row, column, array);

        return;
    }

    float rotate_array[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < column; ++i) {
        for (int j = 0; j < row; ++j) {
            rotate_array[i][j] = array[j][i];           
        }
    }

    std::cout << "Matrix after transposition:\n";
    printArray(column, row, rotate_array);
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
