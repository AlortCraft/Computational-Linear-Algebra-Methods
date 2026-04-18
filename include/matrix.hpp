#pragma once

#include <vector>


template <typename T>
class Matrix {
    std::size_t row, col;

    std::vector<T> data;

public:
    Matrix(int r, int c) : row(r), col(c), data(r * c) {}

    T& operator[](std::size_t r, std::size_t c);

    // Versão APENAS para leitura (Obrigatório para usar com 'const Matrix& other')
    const T& operator[](std::size_t r, std::size_t c) const;

    
    // Soma entre matrizes
    Matrix<T> operator+(const Matrix<T>& other) const;

    // Subtração entre Matrizes
    Matrix<T> operator-(const Matrix<T>& other) const;

    // Multiplicação por Escalar
    Matrix<T> operator*(const T scaler);


    //Multiplicação entre Matrizes
    Matrix<T> operator*(const Matrix<T>& other);


    
};


#include "matrix.tpp"