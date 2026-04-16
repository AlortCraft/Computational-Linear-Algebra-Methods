#include <iostream>

#include "matrix.hpp"





int main() {
    Matrix<int> M1(2, 2);
    Matrix<int> M2(2, 2);

    M1[0, 0] = 1;
    M1[0, 1] = 1;
    M1[1, 0] = 1;
    M1[1, 1] = 1;

    M2[0, 0] = 1;
    M2[0, 1] = 2;
    M2[1, 0] = 3;
    M2[1, 1] = 4;

    Matrix<int> m_result(2, 2);

    // Soma de Matrizes
    m_result = M1 + M2;
    for (int r = 0; r < 2; r++) {
        for(int c = 0; c < 2; c++) {
            std::cout << m_result[r, c] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Subtração de Matrizes
    m_result = M1 - M2;
    for (int r = 0; r < 2; r++) {
        for(int c = 0; c < 2; c++) {
            std::cout << m_result[r, c] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Multiplicação por Escalar
    m_result = M1 * 5;
    for (int r = 0; r < 2; r++) {
        for(int c = 0; c < 2; c++) {
            std::cout << m_result[r, c] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Multiplicação entre matrizes
    m_result = (M1 * 2) * m_result;
    for (int r = 0; r < 2; r++) {
        for(int c = 0; c < 2; c++) {
            std::cout << m_result[r, c] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}