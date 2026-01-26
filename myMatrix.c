/**
 * @file myMatrix.c
 * @brief Matrix library functions
 * @author Aaron Fleisher
 * @date 2026-01-26
 * 
 * @todo Find a better way to hold the allocations in memory, perhaps an arena or pool.
 * @todo Use discriminated unions to make an easier way to use matrices of different types
 */
#include "myMatrix.h"


/*************************** MATRIX OPERATIONS ************************/

/**
 * @brief Allocates a place in the heap for the matrix of dimensions i, columns, by j, rows 
 * @param i The number of rows, i.e. vectors
 * @param j The number of columns, i.e. items in each vector
 * @return A pointer to a matrix stuct
 */
matrix_int_t* 
initializeMatrix_int(int i, int j) {
    matrix_int_t *m = malloc(sizeof(matrix_int_t));

    m->i = i;
    m->j = j;

    /* Allocating an array the size of the matrix */
    m->array = calloc(i * j, sizeof(int));

    /* The eigenvector of a matrix is a column vector of the same size as the column of the original matrix */
    m->properties.eigenvector = calloc(j, sizeof(complex));

    return m;
}

/**
 * @brief The matrix_int_t type has two arrays that need to be cleaned up before freeing the memory for the entire struct.
 * @param m The matrix that will be freed.
 */
void
freeMatrix_int(matrix_int_t *m) {
    free(m->array);
    free(m->properties.eigenvector);
    free(m);
}


/**
 * @brief This function copies an array into the array of the matrix struct.  The array must be the length of the full size (i * j) of the matrix;
 * @param m matrix_int_t. The matrix struct
 * @param array integer list. The list of integer values to be added into the matrix
 * @param array_length size_t. This ensures that the function won't try to copy beyond the size of the array.  It also lets the function be sure that the array fits the matrix size.
 */
void
copyArrayToMatrix_int(matrix_int_t *m, int *array, const size_t array_length) {
    assert(array_length == (m->i * m->j));

    for(size_t index = 0; index < array_length; index++) {
        m->array[index] = array[index];
    }
}

/**
 * @brief Prints the matrix to stdout in the appropriate dimensions
 * @param m matrix_int_t.  The matrix struct holding the array and all metadata
 */
void
printMatrix_int(matrix_int_t *m) {
    for(size_t row = 0; row < m->i; row++) {
        for(size_t column = 0; column < m->j; column++) {
            size_t array_member = (row * m->j) + column;
            (void) printf("%d ", m->array[array_member]);
        }
    }
    /**
     * @todo Write a section that prints out meta-data about matrix.
     */
}


/**
 * @brief This function finds the value of the matrix at any given dimension.
 * @param m The matrix
 * @param i The row (i.e. value)
 * @param j The columnTriton Programming Language (i.e. value)
 * @return Value at that column x row
 */
int
m_at_int(matrix_int_t *m, int i, int j);


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
m_dotProduct_int(matrix_int_t *m);

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
m_isTriangular_int(matrix_int_t *m);

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
 * @brief
 * @param
 * @return
 */
bool
m_isOrthogonal_int(matrix_int_t *m);

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