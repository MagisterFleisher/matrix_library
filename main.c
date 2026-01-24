/**
 * @file main.c
 * @brief The basic file for beginning development of this matrix library
 * @author Aaron Fleisher
 * @date 2026-01-23
 * 
 * @todo Find a better way to hold the allocations in memory, perhaps an arena or pool.
 * @todo Use discriminated unions to make an easier way to use matrices of different types
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief The matrix type holds the dimensions of the matrix (i columns x j rows) as well as a pointer to an array that holds the matrix information.  The array has one dimension in order to maintain a contiguous block of memory for all the elements of the array.  A "2-dimensional", or double pointer, a[i][j] does not guarantee fast memory usage.  The 
 * @var i - size_t.  This denotes the number of rows in the matrix
 * @var j - size_t.  This denotes the number of columns in the matrix
 * @var array - a pointer to a place in memory that will hold the values in the array
 * @var struct of properties
 * @todo bitpack the boolean properties
 * @todo when the matrix is identity, symmetric, diagonal, etc... it can have a more compact representation.
 */
typedef struct Matrix_int_s {
    size_t i; // Row
    size_t j; // Column
    int *array;
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
        bool is_triangular;
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
        bool is_triangular;
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
        bool is_triangular;
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


/**
 * @brief Allocates a place in the heap for the matrix of dimensions i, columns, by j, rows 
 * @param i The number of rows, i.e. vectors
 * @param j The number of columns, i.e. items in each vector
 * @return A pointer to a matrix stuct
 */
matrix_int_t* 
initializeMatrix(int i, int j);


/**
 * @brief This function finds the value of the matrix at any given dimension.
 * @param m The matrix
 * @param i The row (i.e. value)
 * @param j The column (i.e. value)
 * @return Value at that column x row
 */
int 
m_at(matrix_int_t m, int i, int j);


/**
 * @brief This function performs matrix multiplication, M1 x M2.  The result will be a new matrix struct allocated upon the heap.
 * @param m1 The first matrix
 * @param m2 The second matrix
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
m_multiply(matrix_int_t *m1, matrix_int_t *m2);


/**
 * @brief
 * @param
 * @return
 */
int
m_dotProduct(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
float
m_eigenValue(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
matrix_int_t*
m_eigenVector(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
matrix_int_t*
m_transpose(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
int
m_determinant(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isBinary(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isColumn(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isRow(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isSquare(matrix_int_t *m);  /** If it isn't square, it is rectangular */

/**
 * @brief
 * @param
 * @return
 */
bool
m_isSingleton(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isTriangular(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isDiagonal(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isIdentity(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isNull(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isSymmetric(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isOrthogonal(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isSingular(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isIdempotent(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isInvolutory(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isNilpotent(matrix_int_t *m);

/**
 * @brief
 * @param
 * @return
 */
bool
m_isStochastic(matrix_int_t *m);




int
main(int argument_count, char **argument_vector) {
    (void) printf("Argument count: %d\n", argument_count);
    return 0;
}