#include <iostream>
#include "Matrix.hpp"

//Private functions

bool Matrix::allocate(int row, int column){
    if (row < 0 || column < 0){
        return false;
    }

    deallocate();

    this->row = row;
    this->column = column;

    matrix = new float* [row];

    for(int i = 0; i < row; ++i){
        matrix[i] = new float[column];
    }

    return true;
}

void Matrix::deallocate(){
    if(matrix == nullptr){
        return;
    }

    for (int i = 0; i < row; ++i){
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;
    row = 0;
    column = 0;
}

//Constructors

Matrix::Matrix() : matrix(nullptr), row(0), column(0){}

Matrix::Matrix(int row, int column) : matrix(nullptr), row(0), column(0){
    allocate(row, column);
}

Matrix::Matrix(const Matrix& other) : matrix(nullptr), row(0), column(0) {
    allocate(other.row, other.column);
    
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& other) : matrix(nullptr), row(0), column(0){
    row = other.row;
    column = other.column;
    matrix = other.matrix;

    other.row = 0;
    other.column = 0;
    other.matrix = nullptr;    
}

//Destructor

Matrix::~Matrix(){
    deallocate();
}

//Get functions
const float Matrix::getElement(int row, int column) {
    if( row >= this->row || column >= this->column || row < 0 || column < 0){
        std::cout << "Index is uncrorrect!\n";
        return 0;
    }

    return matrix[row][column];
}

const int Matrix::getRow() {
    return row;
}

const int Matrix::getColumn() {
    return column;
}

void Matrix::printMatrix() {
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

//Set function

bool Matrix::setDimensions(int row, int column){
    return allocate(row, column);
}

//Operators

Matrix& Matrix::operator=(const Matrix& other){
    if(this == &other){
        return *this;
    }

    deallocate();
    allocate(other.row, other.column);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            matrix[i][j] = other.matrix[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator=(Matrix&& other) {
    if (this == &other) {
        return *this;
    }

    deallocate();

    row = other.row;
    column = other.column;
    matrix = other.matrix;

    other.row = 0;
    other.column = 0;
    other.matrix = nullptr;

    return *this;
}

Matrix Matrix::operator+(const Matrix& other){
    if(row != other.row || column != other.column){
        std::cout << "Matrix dimensions must match for addition!\n";
        return Matrix(0, 0);
    }

    Matrix result(row, column);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other){
    if(row != other.row || column != other.column){
        std::cout << "Matrix dimensions must match for subtraction!\n";
        return Matrix(0, 0);
    }

    Matrix result(row, column);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) {
    if (column != other.row) {
        std::cout << "Matrix dimensions must match for multiplication!\n";
        return Matrix(0, 0);
    }
    Matrix result(row, other.column);
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < other.column; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < column; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}
Matrix Matrix::operator/(const Matrix& other) {
    if (row != other.row || column != other.column) {
        std::cout << "Matrix dimensions must match for division.\n";
        return Matrix(0, 0);
    }

    Matrix result(row, column);
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (other.matrix[i][j] == 0) {
                std::cout << "Division by zero in matrix element.\n";
                return Matrix(0, 0);
            }
            result.matrix[i][j] = matrix[i][j] / other.matrix[i][j];
        }
    }
    
    return result;
}

Matrix& Matrix::operator++() {
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            ++matrix[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp(*this);
    ++(*this);
    return temp;
}

Matrix& Matrix::operator--() {
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            --matrix[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix temp(*this);
    --(*this);
    return temp;
}

bool Matrix::operator==(const Matrix& other){
    if(row != other.row || column != other.column){
        return false;
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            if(matrix[i][j] != other.matrix[i][j]){
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& other){
    return !(*this == other);
}

bool Matrix::operator<(const Matrix& other){
    if(row != other.row || column != other.column){
        return false;
    }

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < column; ++j){
            if(matrix[i][j] >= other.matrix[i][j]){
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator<=(const Matrix& other){
    return *this < other || *this == other;
}

bool Matrix::operator>(const Matrix& other){
    return !(*this <= other);
}

bool Matrix::operator>=(const Matrix& other){
    return !(*this < other);
}

float* Matrix::operator[](int index){
    if(index < 0 || index >= row){
        std::cout << "Index id uncorrect! \n";
        return nullptr;
    } 

    return matrix[index];
}
