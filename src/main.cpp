#include <iostream>

#include "matrix.hpp"





int main() {
    Matrix<double> M1(2, 2);
    Matrix<double> M2(2, 2);

    M1[0, 0] = 1;
    M1[0, 1] = 1;
    M1[1, 0] = 1;
    M1[1, 1] = 1;

    M2[0, 0] = 1;
    M2[0, 1] = 1;
    M2[1, 0] = 1;
    M2[1, 1] = 1;

    return 0;
}