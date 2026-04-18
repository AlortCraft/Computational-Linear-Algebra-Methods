


template <typename T>
T& Matrix<T>::operator[](std::size_t r, std::size_t c) {
    return data[r * col + c];
}

template <typename T>
const T& Matrix<T>::operator[](std::size_t r, std::size_t c) const {
    return data[r * col + c];
}


template <typename T>
// Soma entre matrizes
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (row != other.row || col != other.col) {
        throw std::invalid_argument("Dimensões das Matrizes são diferentes.");
    }

    Matrix<T> result(row, col);

    for (std::size_t i = 0; i < (row * col); ++i) {
        result.data[i] = this->data[i] + other.data[i];
    }

    return result;
}



template <typename T>
// Subtração entre Matrizes
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
    if (row != other.row || col != other.col) {
        throw std::invalid_argument("Dimensões das Matrizes são diferentes.");
    }

    Matrix<T> result(row, col);

    for (std::size_t i = 0; i < (row * col); ++i) {
        result.data[i] = this->data[i] - other.data[i];
    }

    return result;
}



template <typename T>
// Multiplicação por Escalar
Matrix<T> Matrix<T>::operator*(const T scaler) {
    Matrix<T> result(this->row, this->col);

    for (std::size_t i = 0; i < (row * col); ++i) {
        result.data[i] = this->data[i] * scaler;
    }

    return result;
}



template <typename T>
//Multiplicação entre Matrizes
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) {
    if (this->col != other.row) {
        throw std::invalid_argument("Número de colunas da primeira não bate com o número de linhas da segunda.");
    }

    Matrix<T> result(this->row, other.col);
    for(std::size_t c2 = 0; c2 < other.col; c2++) {
        for(std::size_t r1 = 0; r1 < this->row; r1++) {
            result[r1, c2] = 0;
            for(std::size_t c1 = 0; c1 < this->col; c1++) {
                result[r1, c2] = result[r1, c2] + ((*this)[r1, c1] * other[c1, c2]);
            }
        }
    }
    return result;
}