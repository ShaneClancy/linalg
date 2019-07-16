#include "linalg.h"

int main(int argc, char ** agrv){

    printf("\nDefault Constructor Test\n");
    Matrix m1;
    m1.print();

    printf("\nr x c Matrix Constructor Test\n");
    Matrix m2(3, 4);
    m2.print();

    printf("\nCopy Constructor Test\n");
    Matrix m3(m2);
    m3.print();

    printf("\nTranspose Test\n");
    Matrix m4 = m2.transpose();
    m4.print();

    printf("\nSet Entry Test\n");
    Matrix m5(3,3);
    for (int r = 0; r < m5.getRows(); r++){
        for (int c = 0; c < m5.getCols(); c++){
            float val = r+c;
            m5.setEntry(r, c, val);
        }
    }
    m5.print();

    printf("\nAddition Test\n");
    Matrix m6(m5);
    m5.print();
    printf("\t+\n");
    m6.print();
    printf("\t=\n");
    Matrix m7 = m6.add(m5);
    m7.print();

    printf("\nSubtraction Test\n");
    m5.print();
    printf("\t-\n");
    m6.print();
    printf("\t=\n");
    Matrix m8 = m6.subtract(m5);
    m8.print();

    printf("\nMultiplication Test\n");
    Matrix m9(3,3);
    Matrix m10(3,3);
    m9.setEntry(0,0, 1);
    m9.setEntry(0,1, 2);
    m9.setEntry(0,2, 3);
    m9.setEntry(1,0, 4);
    m9.setEntry(1,1, 5);
    m9.setEntry(1,2, 6);
    m9.setEntry(2,0, 7);
    m9.setEntry(2,1, 8);
    m9.setEntry(2,2, 9);
    m10.setEntry(0,0, 1);
    m10.setEntry(0,1, 2);
    m10.setEntry(0,2, 3);
    m10.setEntry(1,0, 4);
    m10.setEntry(1,1, 5);
    m10.setEntry(1,2, 6);
    m10.setEntry(2,0, 7);
    m10.setEntry(2,1, 8);
    m10.setEntry(2,2, 9);
    m9.print();
    printf("\t*\n");
    m10.print();
    printf("\t=\n");
    Matrix m11 = m9.multiply(m10);
    m11.print();
}