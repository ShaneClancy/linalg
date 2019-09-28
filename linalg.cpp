#include "linalg.h"

void default_constructor_test(void){
    printf("\nDefault Constructor Test\n");
    Matrix m1;
    m1.print();
}

void dim_constructor_test(void){
    printf("\nr x c Matrix Constructor Test\n");
    Matrix m1(3, 4);
    Matrix m2(4, 3);
    m1.print();
    m2.print();
}

void copy_constructor_test(void){
    printf("\nCopy Constructor Test\n");
    Matrix m1(3,3);
    Matrix m2 = Matrix(m1);
    m1.print();
    m2.print();
}

void transpose_test(void){
    printf("\nTranspose Test\n");
    Matrix m1(3,2);
    m1.print();
    Matrix m2(2,3);
    m2 = m1.transpose();
    m2.print();
}

void set_entry_test(void){
    printf("\nSet Entry Test\n");
    Matrix m1(3,3);
    for (int r = 0; r < m1.getRows(); r++){
        for (int c = 0; c < m1.getCols(); c++){
            float val = r+c;
            m1.setEntry(r, c, val);
        }
    }
    m1.print();
}

void addition_test(void){
    printf("\nAddition Test\n");
    Matrix m1(3,3);
    for (int r = 0; r < m1.getRows(); r++){
        for (int c = 0; c < m1.getCols(); c++){
            float val = r+c;
            m1.setEntry(r, c, val);
        }
    }
    m1.print();
    printf("\t+\n");
    m1.print();
    printf("\t=\n");
    Matrix m2 = m1.add(m1);
    m2.print();
}

void subtraction_test(void){
    printf("\nSubtraction Test\n");
    Matrix m1(3,3);
    for (int r = 0; r < m1.getRows(); r++){
        for (int c = 0; c < m1.getCols(); c++){
            float val = r+c;
            m1.setEntry(r, c, val);
        }
    }
    m1.print();
    printf("\t-\n");
    m1.print();
    printf("\t=\n");
    Matrix m2 = m1.subtract(m1);
    m2.print();
}

void multiplication_test(void){
    printf("\nMultiplication Test\n");
    Matrix m1(3,3);
    m1.setEntry(0,0, 1);
    m1.setEntry(0,1, 2);
    m1.setEntry(0,2, 3);
    m1.setEntry(1,0, 4);
    m1.setEntry(1,1, 5);
    m1.setEntry(1,2, 6);
    m1.setEntry(2,0, 7);
    m1.setEntry(2,1, 8);
    m1.setEntry(2,2, 9);
    m1.print();
    printf("\t*\n");
    m1.print();
    printf("\t=\n");
    Matrix m2 = m1.multiply(m1);
    m2.print();
}

void dims_test(void){
    Matrix m1 = Matrix(3,3);
    std::vector<int> dim = m1.dims();
    printf("\nDimensions Test of 3x3\n");
    printf("(%d, %d)\n", dim[0], dim[1]);
    Matrix m2 = Matrix(1,5);
    dim = m2.dims();
    printf("\nDimensions Test of 1x5\n");
    printf("(%d, %d)\n", dim[0], dim[1]);
}

void rref_test(void){
    printf("\nRREF Test\n");
    Matrix m1 = Matrix(3,3);
    m1.setEntry(0,0, 1);
    m1.setEntry(0,1, 2);
    m1.setEntry(0,2, 3);
    m1.setEntry(1,0, 4);
    m1.setEntry(1,1, 5);
    m1.setEntry(1,2, 6);
    m1.setEntry(2,0, 7);
    m1.setEntry(2,1, 8);
    m1.setEntry(2,2, 9);
    m1.print();
    Matrix m2 = m1.rref();
    printf("rref version:\n");
    m2.print();

}

void zero_test(void) {
    printf("\nZero Matrix Test\n");
    Matrix m1 = Matrix(3,3);
    m1.print();
    if(m1.isZero()) {
        printf("is zero matrix\n");
    }
    else {
        printf("is not zero matrix\n");
    }
    m1.setEntry(0,0,1);
    m1.setEntry(1,1,1);
    m1.setEntry(2,2,1);
    m1.print();
    if(m1.isZero()) {
        printf("is zero matrix\n");
    }
    else {
        printf("is not zero matrix\n");
    }
}

void identity_test(void) {
    printf("\nIdentity Matrix Test\n");
    Matrix m1 = Matrix();
    m1 = m1.identity(3,3);
    m1.print();
    if (m1.isIdentity()) {
        printf("is identity matrix\n");
    }
    else {
        printf("is not identity matrix\n");
    }
    m1.setEntry(1,1,0);
    m1.print();
        if (m1.isIdentity()) {
        printf("is identity matrix\n");
    }
    else {
        printf("is not identity matrix\n");
    }
}

void infnorm_test() {
    printf("\nInifnity Norm Test\n");
    Matrix m1 = Matrix();
    m1 = m1.identity(3,3);
    m1.print();
    printf("has an infnity norm of %f\n", m1.infNorm());
    m1.setEntry(0,0, 1);
    m1.setEntry(0,1, 2);
    m1.setEntry(0,2, 3);
    m1.setEntry(1,0, 4);
    m1.setEntry(1,1, 5);
    m1.setEntry(1,2, 6);
    m1.setEntry(2,0, 7);
    m1.setEntry(2,1, 8);
    m1.setEntry(2,2, 9);
    m1.print();
    printf("has an infinity norm of %f\n", m1.infNorm());
}

void scale_test() {
    printf("\nScaling Test\n");
    Matrix m1 = Matrix();
    m1 = m1.identity(3,3);
    m1.print();
    m1 = m1.scaleAll(3);
    m1.print();
    m1 = m1.scaleRow(0, 3);
    m1.print();
    m1 = m1.scaleCol(0, 3);
    m1.print();
}

int main(int argc, char ** agrv){
    default_constructor_test();
    dim_constructor_test();
    copy_constructor_test();
    transpose_test();
    set_entry_test();
    addition_test();
    subtraction_test();
    multiplication_test();
    dims_test();
    rref_test();
    zero_test();
    identity_test();
    infnorm_test();
    scale_test();
}