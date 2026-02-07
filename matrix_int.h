/**
 * @file matrix_int.h
 * @brief The header file containing matrix structs, typedefs, and function prototypes for integer matrices.  Note, this does not include double size integers.
 * @author Aaron Fleisher
 * @date 2026-02-06
 */

#ifndef MATRIX_INT_H
#define MATRIX_INT_H

#include "myMatrix.h"

/**
 * @brief The matrix type holds the dimensions of the matrix (i columns x j rows) as well as a pointer to an array that holds the matrix information.  The array has one dimension in order to maintain a contiguous block of memory for all the elements of the array.  A "2-dimensional", or double pointer, a[i][j] does not guarantee fast memory usage.  The 
 * @var i - size_t.  This denotes the number of rows in the matrix
 * @var j - size_t.  This denotes the number of columns in the matrix
 * @var array - a pointer to a place in memory in the heap that will hold the values in the array
 * @var struct of properties
 * @todo bitpack the boolean properties
 * @todo when the matrix is identity, symmetric, diagonal, etc... it can have a more compact representation.
 */
typedef struct Matrix_int_s {
    size_t i; // Row
    size_t j; // Column
    int *array;
    struct {
        /**
         * @note not all eigenvectors exist in the real numbers.  Some only exist in the complex numbers.  This is basically a double.
         */
        complex *eigenvector;
        int dot_product;
        float eigenvalue;
        int determinant;
        /**
         * @todo change make these 16 booleans into bitpacked int.
         */
        bool is_binary; /** << If the matrix is binary it can be represented though bitpacking */
        bool is_column;  
        bool is_row;
        bool is_singleton;
        bool is_square;
        bool is_UpperTriangular;
        bool is_LowerTriangular;
        bool is_diagonal;
        bool is_identity;
        bool is_null;
        bool is_symmetric;
        bool is_orthoganal;
        bool is_singular;
        bool is_idempotent;
        bool is_involutory;
        bool is_nilpotent;
        bool is_stochastic;
    } properties;
} matrix_int_t;



/*************************** MATRIX WIDE OPERATIONS ************************/

/**
 * @brief Allocates a place in the heap for the matrix of dimensions i, columns, by j, rows 
 * @param i The number of rows, i.e. vectors
 * @param j The number of columns, i.e. items in each vector
 * @return A pointer to a matrix stuct
 */
matrix_int_t* 
initializeMatrix_int(const int i, const int j);

/**
 * @brief The matrix_int_t type has two arrays that need to be cleaned up before freeing the memory for the entire struct.
 * @param m The matrix that will be freed.
 */
void
freeMatrix_int(matrix_int_t *m);

/**
 * @brief This function copies an array into the array of the matrix struct.  The array must be the length of the full size (i * j) of the matrix;
 * @param m matrix_int_t. The matrix struct
 * @param array integer list. The list of integer values to be added into the matrix
 * @param array_length size_t. This ensures that the function won't try to copy beyond the size of the array.  It also lets the function be sure that the array fits the matrix size.
 */
void
copyArrayToMatrix_int(matrix_int_t *m, const int *array, const size_t array_length);

/**
 * @brief Prints the matrix to stdout in the appropriate dimensions
 * @param m matrix_int_t.  The matrix struct holding the array and all metadata
 */
void
printMatrix_int(matrix_int_t *m);

/**
 * @brief This generates an identity matrix of size, dim x dim.
 * @param dim the number of rows and columns in the matrix.  All identity matrices are square.  So, the function requires only one number to define the size of the matrix.
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
generateIdentityMatrix_int(const int dim);

/**
 * @brief Creates a new integer matrix in the heap using the contents of another matrix
 * @param m matrix_int_t The matrix to copy
 * @return matrix_int_t matrix in the heap
 */
matrix_int_t*
createCopy_int(matrix_int_t *m);

/**
 * @brief This generates an random matrix of size, i x j, with values lower_bound <= x <= upper_bound
 * @param i integer the number of rows in the matrix.
 * @param j integer the number of columns in the matrix.
 * @param lower_bound integer All values in the matrix are greater than or equal to this lower bound.
 * @param upper_bound integer All values in the matrix are less than or equal to this upper bound. 
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
generateRandomMatrix_int(const int i, const int j, const int lower_bound, const int upper_bound);


/******************************* INTERNAL MATRIX OPERATIONS **********************/

/**
 * @brief This function finds the value of the matrix at any given dimension.
 * @param m The matrix
 * @param i The row index, using C style indexing (starting at 0)
 * @param j The column index, using C style indexing (starting at 0)
 * @return Value at that column x row
 */
int
m_at_int(matrix_int_t *m, const int i, const int j);

/**
 * @brief Returns a specific column from the matrix.  The column numbers use C-style indexing.  The index begins at 0, and continues to m->j -1.  For some constant c, select all i such that M[i][c].  Return an array of integers allocated in the heap with those values.  Do not forget to free this array after use.
 * @param m matrix_int_t The matrix to select from
 * @param column_number int The index of the column to select.  This index is C style.  In other words, it begins at 0 and goes up to m->j -1.    This number must be less that m->j.
 * @return Integer array with all values from the column.
 */
int*
m_selectColumn_int(matrix_int_t *m, const int column_number);

/**
 * @brief  This function returns an integer array containing all values from a designated row.  The integer array is allocated on the heap. Do not forget to free this array after use.
 * @param m matrix_int_t The matrix from which the row will be selected
 * @param row_number int The row number.  This row number must be less than 
 * @return An integer array allocated upon the heap
 */
int*
m_selectRow_int(matrix_int_t *m, const int row_number);

/**
 * @brief This function performs scalar matrix addition.  It modifies the matrix passed to the function
 * @param m matrix_int_t The matrix
 * @param scalar const int The 
 */
void
m_ScalarAdd_int(matrix_int_t *m, const int scalar);

/**
 * @brief This function performs matrix addition, M1 + M2.  The result will be a new matrix struct allocated upon the heap.
 * @param m1 The first matrix
 * @param m2 The second matrix
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
m_MatrixAdd_int(matrix_int_t *m1, matrix_int_t *m2);
/**
 * @brief This function performs scalar matrix subtraction.  It modifies the matrix passed to the function
 * @param m matrix_int_t The matrix
 * @param scalar const int The scalar used for subtraction 
 */
void
m_ScalarSubtract_int(matrix_int_t *m, const int scalar);

/**
 * @brief This function performs matrix subtraction, M1 + M2.  The result will be a new matrix struct allocated upon the heap.
 * @param m1 The first matrix
 * @param m2 The second matrix
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
m_MatrixSubtract_int(matrix_int_t *m1, matrix_int_t *m2);

/**
 * @brief This checks if the values of two matrices, M1 and M2, are equal.
 * @param m1 The first matrix
 * @param m2 The second matrix
 * @return boolean. True if matrices are equal, false otherwise
 */
bool
m_isEqual_int(matrix_int_t *m1, matrix_int_t *m2);

/**
 * @brief This function performs scalar matrix multiplication.  It modifies the matrix passed to the function
 * @param m matrix_int_t The matrix
 * @param scalar const int The scalar used for multiplication 
 */
void
m_ScalarMultiply_int(matrix_int_t *m, const int scalar);

/**
 * @brief This function performs matrix multiplication, M1 x M2.  The result will be a new matrix struct allocated upon the heap.
 * @param m1 The first matrix
 * @param m2 The second matrix
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
m_MatrixMultiply_int(matrix_int_t *m1, matrix_int_t *m2);


/**
 * @brief Finds the dot product of two integer arrays of equal size
 * @param a1 integer array
 * @param a2 integer array
 * @param length length of both arrays
 * @return An integer value
 */
int
m_dotProduct_int(int *a1, int *a2, const size_t length);

/**
 * @brief
 * @param
 * @return
 */
float
m_eigenValue_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
complex*
m_eigenVector_int(matrix_int_t *m);

/**
 * @brief Creates a new array in memory containing the transpose of the matrix. 
 * @param m Pointer to matrix_int_t object. 
 * @return A new array in memory.
 */
int*
m_transpose_int(matrix_int_t *m);

/**
 * @brief Returns the value (a scalar) of the determinant of a matrix.  Only square matrices have determinants. 
 * @param  m Pointer to matrix_int_t object.
 * @return integer value
 */
int
m_determinant_int(matrix_int_t *m);

/**
 * @brief Determines if a matrix is nilpotent.  In other words, whether that 
 * @param m Pointer to matrix_int_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 */
unsigned int
m_nilPotentDegree_int(matrix_int_t *m);


/*************************** MATRIX CHARACTERIZATIONS ************************** */

/**
 * @brief Find whether all values in the matrix are binary (i.e. 0 or 1)
 * @param m Pointer to the matrix_int_t struct.  It includes the number of rows, the number of columns, and the array of values required by the function
 * @return boolean.  True if the matrix only includes binary values.  False if the matrix includes non binary values.
 */
bool
m_isBinary_int(matrix_int_t *m);

/**
 * @brief Find if this is a column matrix.  The row value should equal 1.
 * @param m Pointer to the matrix_int_t struct. 
 * @return boolean.  True if this is a column matrix.  False if this is not a column matrix.
 */
bool
m_isColumn_int(matrix_int_t *m);

/**
 * @brief Find if this is a row matrix. The column value should equal 1.
 * @param m Pointer to the matrix_int_t struct.
 * @return boolean.  True if this a row matrix. False if this is not a column matrix.
 */
bool
m_isRow_int(matrix_int_t *m);

/**
 * @brief Find if this is a square matrix.  A square matrix has the same number of rows as it does columns.  Only square matrices have determinants.
 * @param m Pointer to the matrix_int_t struct.
 * @return boolean.  True if this is a square matrix.  False if this is not a square matrix.
 */
bool
m_isSquare_int(matrix_int_t *m);

/**
 * @brief Find if this is a singleton matrix, i.e. the number of rows and columns both equal 1.
 * @param m Pointer to the matrix_int_t struct.
 * @return boolean.  True if this is a singleton matrix.  False if this is not a singleton matrix.
 */
bool
m_isSingleton_int(matrix_int_t *m);

/**
 * @brief Find if the matrix is upper triangular (but not strictly so), i.e. if the row number is less than the column number, the value must be zero.
 * @param m Pointer to the matrix_int_t struct
 * @return boolean.  True if this matrix is upper triangular; false if not.
 */
bool
m_isUpperTriangular_int(matrix_int_t *m);

/**
 * @brief Find if the matrix is lower triangular (but not strictly so), i.e. if the row number is greater than the column number, the value must be zero.
 * @param m Pointer to the matrix_int_t struct
 * @return boolean.  True if this matrix is lower triangular; false if not.
 */
bool
m_isLowerTriangular_int(matrix_int_t *m);

/**
 * @brief Finds if the matrix is diagonal, i.e. it only has non-zero values where i == j.  A diagonal matrix can be use to scale other matrices when multiplied.
 * @param m Pointer to matrix_int_t struct object
 * @return boolean.  True if it is diagonal, false otherwise.
 */
bool
m_isDiagonal_int(matrix_int_t *m);

/**
 * @brief Finds if the matrix is an identity matrix.  An identity matrix is a diagonal matrix with the value 1 along the diagonal.  Multiply any matrix by the identity matrix and the result with be the matrix.
 * @param m Pointer to matrix_int_t object
 * @return boolean.  True if the matrix is an identity matrix, false otherwise.
 */
bool
m_isIdentity_int(matrix_int_t *m);

/**
 * @brief Finds if the matrix is a null matrix.  A null matrix has only 0 values.  This can be considered a special case of a binary matrix.  It's also a diagonal matrix, upper and lower triangular, and symmetric.
 * @param m Pointer to matrix_int_t object
 * @return boolean.  True if the matrix is null, false otherwise.
 */
bool
m_isNull_int(matrix_int_t *m);

/**
 * @brief Finds if the matrix is symmetric, this means for all x and y, Mxy = Myx
 * @param m Pointer to matrix_int_t object.
 * @return boolean.  True if symmetric, false otherwise.
 */
bool
m_isSymmetric_int(matrix_int_t *m);

/**
 * @brief Finds if the matrix is invertible.  This means that this matrix can be multiplied by another matrix to yield the identity matrix.
 * @param m Pointer to matrix_int_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 */
bool
m_isInvertable(matrix_int_t *m);

/**
 * @brief Finds if the matrix is orthogonal.  This means that multiplying the matrix with its transpose yields the identity matrix.  This is a special case of an invertable matrix.
 * @param m Pointer to matrix_int_t object.
 * @param m_transpose Pointer to matrix_int_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 */
bool
m_isOrthogonal_int(matrix_int_t *m, matrix_int_t *m_transpose);


/**
 * @brief Determines if the matrix is singular.  In other words, it is a square matrix, it is not invertable, and it has a determinant equal to 0.
 * @param m Pointer to matrix_int_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 */
bool
m_isSingular_int(matrix_int_t *m);

/**
 * @brief Determines whether a matrix is idempotent.  In other words, whether the matrix multiplied by itself yields itself.  A x A = A
 * @param m Pointer to matrix_int_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 */
bool
m_isIdempotent_int(matrix_int_t *m);

/**
 * @brief Determines whether a matrix is involutory.  In other words, if that matrix is its own inverse.
 * @param m Pointer to matrix_int_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 */
bool
m_isInvolutory_int(matrix_int_t *m);

/**
 * @brief Determines if a matrix is nilpotent.  In other words, whether that there exists some k such that M^k = a null matrix.  Such a matrix has an eigenvalue of 0.  Given an identity matrix, I, the determinent of(I + N) = 0.
 * @param m Pointer to matrix_int_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 */
bool
m_isNilpotent_int(matrix_int_t *m);

#endif