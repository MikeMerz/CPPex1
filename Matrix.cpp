//
// Created by mikemerzl on 17/12/2019.
//
#include <iostream>
#include "Matrix.h"

#define ERROR_INVALID_INPUT "ERROR:Invalid input"

/**
 * Constructs Matrix rows x cols
 * @param rows : rows of the matrix to be constructed.
 * @param cols : cols of the matrix to be constructed.
 */
Matrix::Matrix(int rows , int cols) : dims{rows , cols}
{
    if (rows < 1 || cols < 1)
    {
        std::cerr << ERROR_INVALID_SIZE;
        exit(1);
    }
    curMatrix = new(std::nothrow) float[rows * cols];
    if (curMatrix == nullptr)
    {
        std::cerr << ERROE_MEMORY;
        exit(1);
    }
    for (int i = 0; i < rows; ++ i)
    {
        for (int j = 0; j < cols; ++ j)
        {
            curMatrix[i * cols + j] = 0;
        }
    }
}

/**
 * Constructs 1X1 Matrix
 */
Matrix::Matrix() : dims{1 , 1}
{
    curMatrix = new(std::nothrow) float[1];
    if (curMatrix == nullptr)
    {
        std::cerr << ERROE_MEMORY;
        exit(1);
    }
    curMatrix[0] = 0;
}

/**
 * Constructs matrix from another Matrix m
 * @param m :copied Matrix
 */
Matrix::Matrix(Matrix const & m) : dims{m.getRows() , m.getCols()}
{
    curMatrix = new(std::nothrow) float[m.getRows() * m.getCols()];
    if (curMatrix == nullptr)
    {
        std::cerr << ERROE_MEMORY;
        exit(1);
    }
    for (int i = 0; i < m.getRows(); ++ i)
    {
        for (int j = 0; j < m.getCols(); ++ j)
        {
            curMatrix[(i * m.getCols()) + j] = m(i , j);
        }
    }

}

/**
 * Returns the amount of rows as int
 * @return num of the Rows
 */
int Matrix::getRows() const
{
    return dims.rows;
}

/**
 * returns the amount of cols as int
 * @return num of the Cols
 */
int Matrix::getCols() const
{
    return dims.cols;
}

/**
 * Transforms a matrix into a col vector
 * @return Matrix as col vector
 */
Matrix & Matrix::vectorize()
{
    dims.rows = dims.rows * dims.cols;
    dims.cols = 1;
    return *this;
}

/**
 * Assign the matrix to a new var
 * @param m:Matrix to copy
 * @return copied Matrix
 */
Matrix & Matrix::operator=(const Matrix & m)
{
    if (this != &m)
    {
        dims.rows = m.dims.rows;
        dims.cols = m.dims.cols;
        delete[] curMatrix;
        curMatrix = nullptr;
        curMatrix = new(std::nothrow) float[m.getRows() * m.getCols()];
        if (curMatrix == nullptr)
        {
            std::cerr << ERROE_MEMORY;
            exit(1);
        }
        for (int i = 0; i < m.getRows() * m.getCols(); ++ i)
        {
            curMatrix[i] = m[i];
        }
    }
    return *this;
}

/**
 * Matrix addition
 * @param b : Matrix  to add
 * @return New Added Matrix
 */
Matrix Matrix::operator+(const Matrix & b) const
{
    if (getRows() != b.getRows() || getCols() != b.getCols())
    {
        std::cerr << ERROR_INVALID_INDEX_OP << std::endl;
        exit(1);
    }
    Matrix returnMat = Matrix(getRows() , getCols());
    for (int i = 0; i < getRows() * getCols(); ++ i)
    {
        returnMat.curMatrix[i] = curMatrix[i] + b[i];
    }
    return returnMat;
}

/**
 * Matrix addition accumulation
 * @param b : Matrix  to add
 * @return New Added Matrix
 */
Matrix & Matrix::operator+=(const Matrix & b)
{
    for (int i = 0; i < getCols() * getRows(); ++ i)
    {
        curMatrix[i] += b[i];
    }
    return *this;
}

/**
 * Matrix multiplication
 * @param b : Matrix  to mult
 * @return New Added Matrix
 */
const Matrix Matrix::operator*(const Matrix & b) const
{

    if (getCols() != b.getRows())
    {
        std::cerr << ERROR_INVALID_MULTI << std::endl;
        exit(1);
    }
    Matrix returnMat(getRows() , b.getCols());
    for (int i = 0; i < getRows(); ++ i)
    {
        for (int j = 0; j < b.getCols(); ++ j)
        {
            float sum = 0;
            for (int k = 0; k < getCols(); ++ k)
            {
                sum += b(k , j) * (*this)(i , k);
            }
            returnMat(i , j) = sum;
        }
    }
    return returnMat;
}

/**
 * Scalar multiplication on the right
 * @param num : scalar
 * @return new matrix after mult
 */
Matrix Matrix::operator*(float num) const
{
    Matrix returnMat = Matrix(*this);
    for (int i = 0; i < returnMat.getRows() * returnMat.getCols(); ++ i)
    {
        returnMat.curMatrix[i] *= num;
    }
    return returnMat;
}

/**
 * Scalar multiplication on the left
 * @param num : scalar
 * @return new matrix after mult
 */
Matrix operator*(float num , const Matrix & b)
{
    Matrix returnMat = Matrix(b);
    for (int i = 0; i < b.getRows() * b.getCols(); ++ i)
    {
        returnMat.curMatrix[i] *= num;
    }
    return returnMat;
}

/**
 * Parenthesis indexing
 * @param i : row index
 * @param j :col index
 * @return the i,j element in the matrix
 */
float & Matrix::operator()(int i , int j) const
{
    if (i < 0 || j < 0 || i > getRows() || j > getCols())
    {
        std::cerr << ERROR_INVALID_INDEX << std::endl;
        exit(1);
    }
    return curMatrix[(i * getCols()) + j];
}

/**
 * Parenthesis indexing
 * @param i : row index
 * @param j :col index
 * @return the i,j element in the matrix
 */
float & Matrix::operator()(int i , int j)
{
    if (i < 0 || j < 0 || i >= getRows() || j >= getCols())
    {
        std::cerr << ERROR_INVALID_INDEX << std::endl;
        exit(1);
    }
    return curMatrix[(i * getCols()) + j];
}

/**
 * Brackets indexing
 * @param i : index
 * @return return the i’th element
 */
float & Matrix::operator[](int i) const
{
    if (i < 0 || i >= getRows() * getCols())
    {
        std::cerr << ERROR_INVALID_INDEX << std::endl;
        exit(1);
    }
    return curMatrix[i];
}

/**
 * Brackets indexing
 * @param i : index
 * @return return the i’th element
 */
float & Matrix::operator[](int i)
{
    if (i < 0 || i >= getRows() * getCols())
    {
        std::cerr << ERROR_INVALID_INDEX << std::endl;
        exit(1);
    }
    return curMatrix[i];
}

/**
 * Prints matrix elements, no return value.
 */
void Matrix::plainPrint() const
{
    for (int i = 0; i < getRows(); ++ i)
    {
        for (int j = 0; j < getCols(); ++ j)
        {
            std::cout << (*this)(i , j) << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Destructor
 */
Matrix::~Matrix()
{
    delete[] curMatrix;
}

/**
 * Input stream
 * @param in : File Inforamtion
 * @param matrix : Matrix to fill into
 * @return Matrix filled
 */
std::istream & operator>>(std::istream & in , const Matrix & matrix)
{
    if (in)
    {
        size_t size = matrix.getCols() * matrix.getRows() * sizeof(float);
        in.read((char *) matrix.curMatrix , size);
    }
    if (! in.good())
    {
        std::cerr << ERROR_INVALID_INPUT << std::endl;
        exit(1);
    }
    return in;

}

/**
 * Output stream
 * @param out : out Strean
 * @param b :matrix to output
 * @return Output stream
 */
std::ostream & operator<<(std::ostream & out , const Matrix & b)
{

    for (int i = 0; i < b.getRows(); ++ i)
    {
        for (int j = 0; j < b.getCols(); ++ j)
        {
            if (b(i , j) <= 0.1f)
            {
                out << "  ";
            }
            else
            {
                out << "**";
            }

        }
        out << std::endl;
    }
    return out;
}


