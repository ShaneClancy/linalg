#include <stdio.h>
#include <time.h>

class Matrix {
    private:
        float ** matrix;
        int rows;
        int cols;
    public:
        Matrix(void);
        Matrix(const int &, const int &);
        Matrix(const Matrix &);
        int getRows(void) const;
        int getCols(void) const;
        void setEntry(int, int, float);
        float getEntry(const int &, const int &) const;
        int * dims(void);
        Matrix transpose(void);
        Matrix add(Matrix other);
        Matrix subtract(Matrix other);
        Matrix multiply(Matrix other);
        void print(void) const;
        bool operator==(const Matrix & other);
        ~Matrix(void);
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

Matrix::Matrix(void){
    this->rows = 1;
    this->cols = 1;
    this->matrix = new float *[rows];
    for (int r = 0; r < rows; r++){
        this->matrix[r] = new float[cols];
    }
    this->matrix[0][0] = 0;
}

void Matrix::print(void) const {
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

int Matrix::getRows(void) const {
    return this->rows;
}

int Matrix::getCols(void) const {
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
        printf("Invalid Entry\n");
        return 0;
    }
    return this->matrix[i][j];
}

int * Matrix::dims(void){
    int * arr = new int[2];
    arr[0] = this->getRows();
    arr[1] = this->getCols();
    return arr;
}

Matrix Matrix::transpose(void){
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

Matrix Matrix::subtract(Matrix other){
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()){
        printf("Matrices dont have same dimensions\n");
        return other;
    }
    Matrix newMatrix(other.getRows(), other.getCols());
    for (int r = 0; r < newMatrix.getRows(); r++){
        for (int c = 0; c < newMatrix.getCols(); c++){
            float val = this->getEntry(r,c) - other.getEntry(r,c);
            newMatrix.setEntry(r,c, val);
        }
    }
    return newMatrix;
}

Matrix Matrix::multiply(Matrix other){
    if (this->getRows() != other.getCols()){
        printf("Invalid multiplication dimensions\n");
    }
    Matrix newMatrix(this->getCols(), other.getRows());
    for (int riter = 0; riter < other.getRows(); riter++){
        for (int r = 0; r < this->getRows(); r++){
            float val = 0;
            for (int c = 0; c < this->getCols(); c++){
                val += this->getEntry(riter,c) * other.getEntry(c,r);
            }
            newMatrix.setEntry(riter, r, val);
        }
    }
    return newMatrix;

}

bool Matrix::operator==(const Matrix & other){
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()){
        return false;
    }
    for (int r = 0; r <  this->getRows(); r++){
        for (int c = 0; c < this->getCols(); c++){
            if (this->getEntry(r,c) != other.getEntry(r,c)){
                return false;
            }
        }
    }
    return true;
}

Matrix::~Matrix(void){
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