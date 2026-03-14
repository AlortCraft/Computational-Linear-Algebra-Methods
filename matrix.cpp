#include <iostream>
#include "matrix.hpp"

// Elementos da classe Matrix
Matrix::Matrix(int r, int c) : row(r), col(c) {
    data.push_back(r*c);
};

double Matrix::get(int r, int c){
    return data[col * r + c];
}

void Matrix::set(int r, int c, double value) {
    data[col * r + c] = value;
}

Matrix Matrix::operator+(const Matrix& m2) {
    
}