#include "linalg.h"

int main(int argc, char ** agrv){

    printf("Default Constructor Test\n");
    Matrix m1;
    m1.print();

    printf("r x c Matrix Constructor Test\n");
    Matrix m2(3, 4);
    m2.print();

    printf("Copy Constructor Test\n");
    Matrix m3(m2);
    m3.print();

    printf("Transpose Test\n");
    Matrix m4 = m2.transpose();
    m4.print();

    printf("Set Entry Test\n");
    Matrix m5(3,3);
    for (int r = 0; r < m5.getRows(); r++){
        for (int c = 0; c < m5.getCols(); c++){
            float val = r+c;
            m5.setEntry(r, c, val);
        }
    }
    m5.print();
    printf("Addition Test\n");
    Matrix m6(m5);
    m5.print();
    printf("\t+\n");
    m6.print();
    printf("\t=\n");
    Matrix m7 = m6.add(m5);
    m7.print();
}