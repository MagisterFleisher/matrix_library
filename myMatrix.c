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
        (void) printf("\n");
    }
    /**
     * @todo Write a section that prints out meta-data about matrix.
     */
}

/**
 * @brief This function finds the value of the matrix at any given dimension.
 * @param m The matrix
 * @param i The row (i.e. value)
 * @param j The column (i.e. value)
 * @return Value at that column x row
 */
int
m_at_int(matrix_int_t *m, int i, int j) {
    return m->array[(i * m->j) + j];
}


/**
 * @brief This function performs matrix multiplication, M1 x M2.  The result will be a new matrix struct allocated upon the heap.
 * @param m1 The first matrix
 * @param m2 The second matrix
 * @return A new matrix allocated upon the heap
 */
matrix_int_t*
m_multiply_int(matrix_int_t *m1, matrix_int_t *m2) {
    assert(m1->j == m2->i);
    /** The matrix result with have m1->rows and m2->columns */
    matrix_int_t *m = initializeMatrix_int(m1->i, m2->j);
    /**
     * Take dot product of first row of first matrix 
     *      and first column of second matrix.
     */
    const size_t result_array_length = m->i * m->j;
    size_t result_array_index = 0;

    for(size_t row_index = 0; row_index < m->i; row_index++) {
        for(size_t column_index = 0; column_index < m->j; column_index++) {
            int *row1_array = calloc(m1->i, sizeof(int));
            int *column2_array = calloc(m2->j, sizeof(int));
            int row_offset = m1->j * row_index;
            memcpy(row1_array, m1->array + row_offset, m1->i * sizeof(int));
            for(size_t index = 0; index < m2->j; index++) {
                column2_array[index] = m_at_int(m2, index, column_index);
            }
            int element = m_dotProduct_int(row1_array, column2_array, m1->i);
            m->array[result_array_index] = element;
            free(column2_array);
            free(row1_array);

            result_array_index++;
        }
    }
    return m;
}

/**
 * @brief Finds the dot product of two integer arrays of equal size
 * @param a1 integer array
 * @param a2 integer array
 * @param length length of both arrays
 * @return An integer value
 */
int
m_dotProduct_int(int *a1, int *a2, const size_t length) {
    int product = 0;
    for(size_t index = 0; index < length; index++) {
        product += a1[index] * a2[index];
    }
    return product;
}

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
 * @brief Find whether all values in the matrix are binary (i.e. 0 or 1)
 * @param m Pointer to the matrix_int_t struct.  It includes the number of rows, the number of columns, and the array of values required by the function
 * @return boolean.  True if the matrix only includes binary values.  False if the matrix includes non binary values.
 */
bool
m_isBinary_int(matrix_int_t *m) {
    for(size_t index = 0; index < (m->i * m->j); index++) { /* Note: m->i and m->j are size_t, so the index for this loop is also size_t.  Can this be improved? */
        if((0 != m->array[index]) && (1 != m->array[index])) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Find if this is a column matrix.  The row value should equal 1.
 * @param m Pointer to the matrix_int_t struct. 
 * @return boolean.  True if this is a column matrix.  False if this is not a column matrix.
 */
bool
m_isColumn_int(matrix_int_t *m) {
    return (1 == m->i) ? true : false;
}

/**
 * @brief Find if this is a row matrix. The column value should equal 1.
 * @param m Pointer to the matrix_int_t struct.
 * @return boolean.  True if this a row matrix. False if this is not a column matrix.
 */
bool
m_isRow_int(matrix_int_t *m) {
    return (1 == m->j) ? true : false;
}

/**
 * @brief Find if this is a square matrix.  A square matrix has the same number of rows as it does columns.  Only square matrices have determinants.
 * @param m Pointer to the matrix_int_t struct.
 * @return boolean.  True if this is a square matrix.  False if this is not a square matrix.
 */
bool
m_isSquare_int(matrix_int_t *m) {
    return (m->i == m->j) ? true : false;
}  /** If it isn't square, it is rectangular */

/**
 * @brief Find if this is a singleton matrix, i.e. the number of rows and columns both equal 1.
 * @param m Pointer to the matrix_int_t struct.
 * @return boolean.  True if this is a singleton matrix.  False if this is not a singleton matrix.
 */
bool
m_isSingleton_int(matrix_int_t *m) {
    return ((1 == m->i) && (1 == m->j)) ? true : false;
}

/**
 * @brief Find if the matrix is upper triangular (but not strictly so), i.e. if the row number is less than the column number, the value must be zero.
 * @param m Pointer to the matrix_int_t struct
 * @return boolean.  True if this matrix is upper triangular; false if not.
 */
bool
m_isUpperTriangular_int(matrix_int_t *m) {
    size_t i_index = 1;
    size_t j_index = 0;
    while((i_index < m->i) && (j_index < m->j)) {
        if(i_index > j_index) {
            j_index++;
            if(0 != m_at_int(m, i_index, j_index)) {
                return false;
            }
        } else {
            i_index++;
        }
    }
    /* The function would only reach this return if it has encountered no instance not indicative of an upper triangular matrix. */
    return true;
}

/**
 * @brief
 * @param
 * @return
 */
bool
m_isLowerTriangular_int(matrix_int_t *m) {
    size_t i_index = 0;
    size_t j_index = 1;
    while((i_index < m->i) && (j_index < m->j)) {
        if(i_index < j_index) {
            j_index++;
            if(0 != m_at_int(m, i_index, j_index)) {
                return false;
            }
        } else {
            i_index++;
        }
    }
    /* The function would only reach this return if it has encountered no instance not indicative of an upper triangular matrix. */
    return true;
}


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