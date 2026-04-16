#pragma once

#include <vector>


template <typename T>
class Matrix {
    std::size_t row, col;

    std::vector<T> data;

public:
    Matrix(int r, int c) : row(r), col(c), data(r * c) {}




    T& operator[](int r, int c) {
        return data[r * row + c];
    }

    T& operator+(Matrix m2) {
        if (row != m2.row || col != m2.col) return NULL;

        Matrix m_soma(row, col);
        for (std::size_t r = 0; r < row; r++) {
            for (std::size_t c = 0; c < col; c++) {
                m_soma[r , c] = this[r , c] + m2[r , c]
            }
        }

        return m_soma;
    }
};