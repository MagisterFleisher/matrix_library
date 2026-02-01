/**
 * @file myMatrix.h
 * @brief Header file of matrix library holding data structures and function prototypes
 * @author Aaron Fleisher
 * @date 2026-01-26
 * 
 * @todo Find a better way to hold the allocations in memory, perhaps an arena or pool.
 * @todo Use discriminated unions to make an easier way to use matrices of different types
 */

#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/**
 * @note Not all matrices have eigenvectors in the real numbers.  But, all matrices have eigenvectors if one expands the field to the complex numbers.
 */
#include <complex.h>

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
        bool is_Uppertriangular;
        bool is_Lowertriangular;
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

typedef struct Matrix_float_s {
    size_t i; // Row
    size_t j; // Column
    float *array;
    struct {
        int *eigenvector;
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
        bool is_Uppertriangular;
        bool is_Lowertriangular;
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
} matrix_float_t;

typedef struct Matrix_double_s {
    size_t i; // Row
    size_t j; // Column
    double *array;
    struct {
        double *eigenvector;
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
    } properties;
} matrix_double_t;

typedef enum { M_INT, M_FLOAT, M_DOUBLE } matrix_type_e;

typedef struct Matrix_t {
    matrix_type_e matrix_type;
    union {
        matrix_double_t matrix_double;
        matrix_int_t matrix_int;
        matrix_float_t matrix_float;
    } matrix_union;
} matrix_t;


/*************************** MATRIX OPERATIONS ************************/

/**
 * @brief Allocates a place in the heap for the matrix of dimensions i, columns, by j, rows 
 * @param i The number of rows, i.e. vectors
 * @param j The number of columns, i.e. items in each vector
 * @return A pointer to a matrix stuct
 */
matrix_int_t* initializeMatrix_int(const int i, const int j);

/**
 * @brief The matrix_int_t type has two arrays that need to be cleaned up before freeing the memory for the entire struct.
 * @param m The matrix that will be freed.
 */
void freeMatrix_int(matrix_int_t *m);

/**
 * @brief This function copies an array into the array of the matrix struct.  The array must be the length of the full size (i * j) of the matrix;
 * @param m matrix_int_t. The matrix struct
 * @param array integer list. The list of integer values to be added into the matrix
 * @param array_length size_t. This ensures that the function won't try to copy beyond the size of the array.  It also lets the function be sure that the array fits the matrix size.
 */
void copyArrayToMatrix_int(matrix_int_t *m, const int *array, const size_t array_length);

/**
 * @brief This generates an identity matrix of size, dim x dim.
 * @param dim the number of rows and columns in the matrix.  All identity matrices are square.  So, the function requires only one number to define the size of the matrix.
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
generateIdentityMatrix_int(const int dim);

/**
 * @brief This generates an random matrix of size, i x j, with values lower_bound <= x <= upper_bound
 * @param i the number of rows in the matrix.
 * @param j the number of columns in the matrix.
 * @param lower_bound All values in the matrix are greater than or equal to this lower bound.
 * @param upper_bound All values in the matrix are less than or equal to this upper bound. 
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
generateRandomMatrix_int(const int i, const int j, const int lower_bound, const int upper_bound);

/**
 * @brief Prints the matrix to stdout in the appropriate dimensions
 * @param m matrix_int_t.  The matrix struct holding the array and all metadata
 */
void printMatrix_int(matrix_int_t *m);

/**
 * @brief This function finds the value of the matrix at any given dimension.
 * @param m The matrix
 * @param i The row (i.e. value)
 * @param j The column (i.e. value)
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
 * @brief This function performs matrix multiplication, M1 x M2.  The result will be a new matrix struct allocated upon the heap.
 * @param m1 The first matrix
 * @param m2 The second matrix
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
m_multiply_int(matrix_int_t *m1, matrix_int_t *m2);


/**
 * @brief
 * @param
 * @return
 */
int
m_dotProduct_int(int *a1, int *a2, size_t length);

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
 * @brief
 * @param
 * @return
 */
int*
m_transpose_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
int
m_determinant_int(matrix_int_t *m);



/*************************** MATRIX CHARACTERIZATIONS ************************** */

/**
 * @brief
 * @param
 * @return
 */
bool
m_isBinary_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isColumn_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isRow_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isSquare_int(matrix_int_t *m);  /** If it isn't square, it is rectangular */

/**
 * @brief
 * @param
 * @return
 */
bool
m_isSingleton_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isUpperTriangular_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isLowerTriangular_int(matrix_int_t *m);


/**
 * @brief
 * @param
 * @return
 */
bool
m_isDiagonal_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isIdentity_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isNull_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isSymmetric_int(matrix_int_t *m);

/**
 * @brief Finds if the matrix is orthogonal.  This means that multiplying the matrix with its transpose yields the identity matrix.  This is a special case of an invertable matrix.
 * @param m Pointer to matrix_int_t object.
 * @param m_transpose Pointer to matrix_int_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 */
bool
m_isOrthogonal_int(matrix_int_t *m, matrix_int_t *m_transpose);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isSingular_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isIdempotent_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isInvolutory_int(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isNilpotent_int(matrix_int_t *m);

/**
 * @brief A stochastic 
 * @param
 * @return
 * @note Easy to parallelize
 */
bool
m_isStochastic_int(matrix_int_t *m);


#endif /** MYMATRIX_H */