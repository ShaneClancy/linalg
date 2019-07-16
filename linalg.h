#include <stdio.h>

class Matrix {
    private:
        float ** matrix;
        int rows;
        int cols;
    public:
        Matrix();
        Matrix(const int &, const int &);
        Matrix(const Matrix &);
        int getRows() const;
        int getCols() const;
        void setEntry(int, int, float);
        float getEntry(const int &, const int &) const;
        Matrix transpose();
        Matrix add(Matrix other);
        void print() const;
        ~Matrix();
};

Matrix::Matrix(const int &rows,const int &cols){
    this->rows = rows;
    this->cols = cols;
    this->matrix = new float *[rows];
    for (int r = 0; r < rows; r++){
        this->matrix[r] = new float[cols];
    }
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            this->matrix[r][c] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &other){
    this->rows = other.rows;
    this->cols = other.cols;
    this->matrix = new float *[rows];
    for (int r = 0; r < rows; r++){
        this->matrix[r] = new float[cols];
    }
    for (int r = 0; r < this->rows; r++){
        for (int c = 0; c < this->cols; c++){
            this->matrix[r][c] = other.getEntry(r,c);
        }
    }
}

Matrix::Matrix(){
    this->rows = 1;
    this->cols = 1;
    this->matrix = new float *[rows];
    for (int r = 0; r < rows; r++){
        this->matrix[r] = new float[cols];
    }
    this->matrix[0][0] = 0;
}

void Matrix::print() const {
    printf("[ ");
    for (int r = 0; r < this->rows; r++){
        for (int c = 0; c < this->cols; c++){
            printf("%.3f ", this->matrix[r][c]);
        }
        if (r != this->rows - 1){ 
            printf("\n  ");
        }
    }
    printf("]\n");
}

int Matrix::getRows() const {
    return this->rows;
}

int Matrix::getCols() const {
    return this->cols;
}

void Matrix::setEntry(int i, int j, float val){
    if (i < 0 || i >= rows || j < 0 || j >= cols){
        printf("Invalid Entry");
        return;
    }
    this->matrix[i][j] = val;
}

float Matrix::getEntry(const int & i, const int & j) const {
    if (i < 0 || i >= rows || j < 0 || j >= cols){
        printf("Invalid Entry");
        return 0;
    }
    return this->matrix[i][j];
}

Matrix Matrix::transpose(){
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

Matrix Matrix::add(Matrix other){
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()){
        printf("Matrices dont have same dimensions");
        return other;
    }
    Matrix newMatrix(other.getRows(), other.getCols());
    for (int r = 0; r < newMatrix.getRows(); r++){
        for (int c = 0; c < newMatrix.getCols(); c++){
            float val = this->getEntry(r,c) + other.getEntry(r,c);
            newMatrix.setEntry(r,c, val);
        }
    }
    return newMatrix;
}

Matrix::~Matrix(){
    if (this->matrix == NULL){
        return;
    }
    for (int r = 0; r < this->rows; r++){
        delete [] this->matrix[r];
        this->matrix[r] = NULL;
    }
    delete [] this->matrix;
    this->matrix = NULL;
}