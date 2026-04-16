#pragma once

#include <vector>


template <typename T>
class Matrix {
    std::size_t row, col;

    std::vector<T> data;

public:
    Matrix(int r, int c) : row(r), col(c), data(r * c) {}

    T& operator[](int r, int c) {
        return data[r * col + c];
    }

    // Soma entre matrizes
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (row != other.row || col != other.col) {
            throw std::invalid_argument("Dimensões das Matrizes são diferentes.");
        }

        Matrix<T> result(row, col);

        for (std::size_t i = 0; i < (row + col); ++i) {
            result.data[i] = this->data[i] + other.data[i];
        }

        return result;
    }

    // Subtração entre Matrizes
    Matrix<T> operator-(const Matrix<T>& other) const {
        if (row != other.row || col != other.col) {
            throw std::invalid_argument("Dimensões das Matrizes são diferentes.");
        }

        Matrix<T> result(row, col);

        for (std::size_t i = 0; i < (row + col); ++i) {
            result.data[i] = this->data[i] - other.data[i];
        }

        return result;
    }



    // Multiplicação por Escalar
    Matrix<T> operator*(const T escalar) {
        Matrix<T> result(row, col);

        for (std::size_t i = 0; i < (row + col); ++i) {
            result.data[i] = this->data[i] * escalar;
        }

        return result;
    }
};