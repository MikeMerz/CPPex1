// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#define ERROR_INVALID_SIZE "ERROR:Invalid size of Matrix"

#define ERROE_MEMORY "ERROR:Not enough Memory"

#define ERROR_INVALID_INDEX_OP "ERROR:Invalid Matrix dims operation"

#define ERROR_INVALID_MULTI "ERROR:Invalid Mult operation"

#define ERROR_INVALID_INDEX "ERROR:Invalid Index"

#include <ostream>
#include <fstream>
#include <iostream>

/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
    int rows , cols;
} MatrixDims;
/**
 * Matrix object
 */
class Matrix
{
public:
    /**
 * Constructs Matrix rows x cols
 * @param rows : rows of the matrix to be constructed.
 * @param cols : cols of the matrix to be constructed.
 */
    Matrix(int rows , int cols);

    /**
 * Constructs 1X1 Matrix
 */
    Matrix();

    /**
 * Constructs matrix from another Matrix m
 * @param m :copied Matrix
 */
    Matrix(Matrix const & m);

    /**
 * Destructor
 */
    ~Matrix();

    /**
 * Returns the amount of rows as int
 * @return num of the Rows
 */
    int getRows() const;

    /**
 * returns the amount of cols as int
 * @return num of the Cols
 */
    int getCols() const;

    /**
 * Transforms a matrix into a col vector
 * @return Matrix as col vector
 */
    Matrix & vectorize();

    /**
 * Prints matrix elements, no return value.
 */
    void plainPrint() const;

    /**
 * Assign the matrix to a new var
 * @param m:Matrix to copy
 * @return copied Matrix
 */
    Matrix & operator=(const Matrix & m);

    /**
 * Matrix multiplication
 * @param b : Matrix  to mult
 * @return New Added Matrix
 */
    const Matrix operator*(const Matrix & b) const;

/**
 * Scalar multiplication on the right
 * @param num : scalar
 * @return new matrix after mult
 */
    Matrix operator*(float num) const;

    /**
 * Scalar multiplication on the left
 * @param num : scalar
 * @return new matrix after mult
 */
    friend Matrix operator*(float num , const Matrix & b);

    /**
 * Brackets indexing
 * @param i : index
 * @return return the i’th element
 */
    float & operator[](int i);

    /**
 * Parenthesis indexing
 * @param i : row index
 * @param j :col index
 * @return the i,j element in the matrix
 */
    float & operator()(int i , int j);

    /**
 * Matrix addition
 * @param b : Matrix  to add
 * @return New Added Matrix
 */
    Matrix operator+(const Matrix & b) const;

    /**
 * Matrix addition accumulation
 * @param b : Matrix  to add
 * @return New Added Matrix
 */
    Matrix & operator+=(const Matrix & b);

    /**
* Parenthesis indexing
* @param i : row index
* @param j :col index
* @return the i,j element in the matrix
*/
    float & operator()(int i , int j) const;

    /**
* Brackets indexing
* @param i : index
* @return return the i’th element
*/
    float & operator[](int i) const;

    /**
 * Input stream
 * @param in : File Inforamtion
 * @param matrix : Matrix to fill into
 * @return Matrix filled
 */
    friend std::istream & operator>>(std::istream & in , const Matrix & matrix);

    /**
 * Output stream
 * @param out : out Strean
 * @param b :matrix to output
 * @return Output stream
 */
    friend std::ostream & operator<<(std::ostream & out , const Matrix & b);

private:
    MatrixDims dims;
    float *curMatrix;

};


#endif //MATRIX_H
