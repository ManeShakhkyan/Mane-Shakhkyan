#include <iostream>
#include "Matrix.hpp"

int main() {
    Matrix m1(3, 3);
    Matrix m2(3, 3);

    //Initialize matrices
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            m1[i][j] = i + j;
            m2[i][j] = i - j;
        }
    }

    std::cout << "Matrix m1:\n";
    m1.printMatrix();

    std::cout << "\nMatrix m2:\n";
    m2.printMatrix();

    std::cout << "\nMatrix m1 is" << (m1 == m2 ? " " : "n't ") << "equal to Matrix m2!\n"; 
    Matrix m3 = m1 + m2;
    std::cout << "\nMatrix m3 = (m1 + m2):\n";
    m3.printMatrix();

    Matrix m4 = m1 * m2;
    std::cout << "\nMatrix m4 = (m1 * m2):\n";
    m4.printMatrix();

    ++m1;
    std::cout << "\nMatrix m1 after ++m1:\n";
    m1.printMatrix();

    --m2;
    std::cout << "\nMatrix m2 after ++m2:\n";
    m2.printMatrix();  

    return 0;
}