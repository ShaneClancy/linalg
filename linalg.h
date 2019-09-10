#include <stdio.h>
#include <vector>
#include <string>

class Matrix {
    private:
        int rows;
        int cols;
    public:
        std::vector<std::vector<float>> matrix;
        Matrix(void);
        Matrix(const int &, const int &);
        Matrix(const Matrix &);
        int getRows(void);
        int getCols(void);
        void setEntry(const int &, const int &, float);
        float getEntry(const int &, const int &);
        std::vector<int> dims(void);
        void print(void);
        Matrix transpose(void);
        Matrix add(const Matrix &);
        Matrix subtract(const Matrix &);
        Matrix multiply(const Matrix &);
        bool operator==(const Matrix &);
        Matrix rref();
};

Matrix::Matrix(void) {
    this->rows = 0;
    this->cols = 0;
}

Matrix::Matrix(const int &x, const int &y) {
    this->rows = x;
    this->cols = y;
    std::vector<float> rowSize = std::vector<float>(rows);
    for (int i = 0; i < y; i++){
        this->matrix.push_back(rowSize);
    }
}

Matrix::Matrix(const Matrix &other) {
    this->rows = other.rows;
    this->cols = other.cols;
}

int Matrix::getRows() {
    return this->rows;
}

int Matrix::getCols() {
    return this->cols;
}

void Matrix::setEntry(const int &row, const int &col, float entry) {
    if (row <= this->getRows() && col <= this->getCols()) {
        this->matrix[row][col] = entry;
    }
    else {
        printf("Not a valid row, col in this matrix\n");
    }
}

float Matrix::getEntry(const int &row, const int &col) {
    if (row <= this->getRows() && col <= this->getCols()) {
        return this->matrix[row][col];
    }
    else {
        printf("Out of bounds of this matrix\n");
        return 0.0;
    }
}

std::vector<int> Matrix::dims() {
    std::vector<int> ret;
    ret.push_back(this->getRows());
    ret.push_back(this->getCols());
    return ret;
}

void Matrix::print(void) {
    printf("[");
    for (int x = 0; x < this->getRows(); x++) {
        for (int y = 0; y < this->getCols(); y++) {
            printf("%5.2f ", this->getEntry(x,y));
        }
        if (x != this->getRows() - 1) { 
            printf("\n");
        }
    }
    printf("]\n");
}

Matrix Matrix::transpose() {
    const int & newRows = this->cols;
    const int & newCols = this->rows;
    Matrix newMatrix(newRows, newCols);
    for (int r = 0; r < newRows; r++){
        for (int c = 0; c < newCols; c++){
            newMatrix.matrix[r][c] = this->matrix[c][r];
        }
    }
    return newMatrix;
}

Matrix Matrix::add(const Matrix &other) {
    if (this->getRows() != other.rows || this->getCols() != other.cols) {
        printf("Matrices dont have same dimensions\n");
        return *this;
    }
    Matrix newMatrix(other.rows, other.cols);
    for (int r = 0; r < newMatrix.getRows(); r++) {
        for (int c = 0; c < newMatrix.getCols(); c++) {
            float val = this->getEntry(r,c) + other.matrix[r][c];
            newMatrix.setEntry(r,c, val);
        }
    }
    return newMatrix;
}

Matrix Matrix::subtract(const Matrix &other) {
    if (this->getRows() != other.rows || this->getCols() != other.cols) {
        printf("Matrices dont have the same dimensions\n");
        return *this;
    }
    Matrix newMatrix(other.rows, other.cols);
    for (int r = 0; r < newMatrix.getRows(); r++) {
        for (int c = 0; c < newMatrix.getCols(); c++) {
            float val = this->getEntry(r,c) - other.matrix[r][c];
            newMatrix.setEntry(r,c, val);
        }
    }
    return newMatrix;
}

Matrix Matrix::multiply(const Matrix &other) { 
    if (this->getRows() != other.cols) {
        printf("Invalid multiplication dimensions\n");
    }
    Matrix newMatrix(other.cols, other.rows);
    for (int riter = 0; riter < other.rows; riter++){
        for (int r = 0; r < this->getRows(); r++){
            float val = 0;
            for (int c = 0; c < this->getCols(); c++){
                val += this->getEntry(riter,c) * other.matrix[c][r];
            }
            newMatrix.setEntry(riter, r, val);
        }
    }
    return newMatrix;
}

bool Matrix::operator==(const Matrix &other) {
    if (this->getRows() != other.rows || this->getCols() != other.cols) {
        return false;
    }
    for (int r = 0; r < other.rows; r++) {
        for (int c = 0; c < other.cols; c++) {
            if (this->getEntry(r,c) != other.matrix[r][c]) {
                return false;
            }
        }
    }
    return true;
}

Matrix Matrix::rref() {
    int lead = 0;
    int i = 0;
    for (int r = 0; r < this->getRows(); r++) {
        if (this->getCols() <= lead) {
            return *this;
        }
        i = r;
        while (this->matrix[i][lead] == 0) {
            i = i + 1;
            if (this->getRows() == i) {
                i = r;
                lead = lead + 1;
                if (this->getCols() == lead) {
                    return *this;
                }
            }
        }
        this->matrix[i].swap(this->matrix[r]);
        if (this->matrix[r][lead] != 0) {
            float divisor = this->matrix[r][lead];
            for (int y = 0; y < this->getCols(); y++) {
                this->matrix[r][y] = this->matrix[r][y] / divisor;
            }
        }
        for (i = 0; i < this->getRows(); i++) {
            if (i != r) {
                float multiplier = this->matrix[i][lead];
                for (int y = 0; y < this->getCols(); y++) {
                    this->matrix[i][y] = this->matrix[i][y] - (multiplier * this->matrix[r][y]);
                }
            }
        }
        lead = lead + 1;
    }
    return *this;
}

