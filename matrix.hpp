#pragma once

#include <vector>


// Declarando a classe Matrix:
class Matrix {
private:
    int row, col; // numero de linhas e de colunas

    std::vector<double> data;
    // Definimos a matriz como um único vetor, pois é mais rápido
    // e os elementos ficam contínuos na memoria

public:
    Matrix(int r, int col);

    ~Matrix();


    double get(int r, int c);
    void set(int r, int c, double value);

    Matrix operator+(const Matrix& m2); // soma
    Matrix operator-(const Matrix& m2); // subtracao

    Matrix operator*(const Matrix& m2); // multiplicacao
    Matrix operator*(double escalar); // multiplicacao por escalar

};