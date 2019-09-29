# linalg
## By Shane Clancy
Linear Algebra Header File in C++.

The goal of this project is to create a useable linear algebra library that includes useful computations for mathematical purposes as well as machine learning. There are many different ways that this library can be utilized to the advantage of some, as the goal of this implementation is meant for speed, as the same ideas exist in other programming languages that are easier to write.

Here are a list of functionalities of this header file and how they are used:

 - Matrix(void)
    - Creates empty matrix of size zero.
 - Matrix(int, int)
    - Creates matrix of size paramater1 by parameter2
 - Matrix(Matrix)
    - Creates a matrix from another matrix (copy constructor)
 - getRows(void)
    - returns amount of rows in Matrix
 - getCols(void)
    - returns amount of cols in Matrix
 - setEntry(int, int, float)
    - sets an entry in a Matrix's value, with bounds checking
 - getEntry(int, int)
    - gets an entry in a Matrix's value, with bounds checking
 - identity(int, int)
    - creates an identity matrix of size parameter1 by parameter2
 - dims(void)
    - returns vector list of dimensions of the matrix
 - print(void)
    - nicely formatted printout of current Matrix object
 - transpose(void)
    - transposes a Matrix of n x m -> m x n
 - add(Matrix)
    - adds second Matrix to current Matrix
    - these Matrices must be of the same size, otherwise the function will return the current Matrix.
 - subtract(Matrix)
    - subtracts a second Matrix from current Matrix
    - these Matrices must be of the same size, otherwise the function will return the current Matrix.
 - multiply(Matrix)
    - multiplies two Matrices together, with the current Matrix being the left Matrix and the other Matrix being the right Matrix.
    - If the rows of left Matrix dont match the columns of the right Matrix, the first Matrix will be returned.
 - scaleAll(float)
    - scales each entry in a matrix by a constant.
 - scaleRow(int, float)
    - scales a row in a matrix by a constant.
 - scaleCol(int, float)
    - scales a col in a matrix by a constant.
 - rref()
    - Row reduces a matrix and returns it.
 - isZero()
    - test to see if a matrix of any size is a zero matrix.
 - isIdentity()
    - test to see if a matrix is an identity matrix.
 - infNorm()
    - calculates infinity norm of a matrix.
 - operator==(Matrix)
    - Compares two Matrices by each of their entries.
