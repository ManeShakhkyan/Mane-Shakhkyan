#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
    private:
        float** matrix;
        int row;
        int column;

        bool allocate(int row, int column);
        void deallocate();

    public:

        //Constructors
        Matrix();
        Matrix(int row, int column);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other);
        
        //Destructors
        ~Matrix();

        //Get functions
        const float getElement(int row, int column);
        const int getRow();
        const int getColumn();
        
        void printMatrix();

        //Set functions
        bool setDimensions(int row, int column);


        //Operators
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other);
        Matrix operator+(const Matrix& other);
        Matrix operator-(const Matrix& other);        
        Matrix operator*(const Matrix& other);
        Matrix operator/(const Matrix& other);
        Matrix& operator++();
        Matrix operator++(int);
        Matrix& operator--();
        Matrix operator--(int);
        bool operator==(const Matrix& other);
        bool operator!=(const Matrix& other);
        bool operator<=(const Matrix& other);
        bool operator>=(const Matrix& other);
        bool operator<(const Matrix& other);
        bool operator>(const Matrix& other);
        float* operator[](int index);

};

#endif
