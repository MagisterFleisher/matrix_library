#ifndef MATRIX_FLOAT_H
#define MATRIX_FLOAT_H

#include "myMatrix.h"

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
} matrix_float_t;


/**
 * @brief Determines if the matrix is right stochastic.  In other words the matrix is square, it has nonnegative real numbers, and the sum of each row is 1.
 * @param m Pointer to matrix_float_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 * @note Easy to parallelize
 */
bool
m_isRightStochastic_float(matrix_float_t *m);

/**
 * @brief Determines if the matrix is left stochastic.  In other words the matrix is square, it has nonnegative real numbers, and the sum of each column is 1.
 * @param m Pointer to matrix_float_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 * @note Easy to parallelize
 */
bool
m_isLeftStochastic_float(matrix_float_t *m);

/**
 * @brief Determines if the matrix is doubly stochastic.  In other words the matrix is square, it has nonnegative real numbers, the sum of each row is 1, and sum of each column is 1.
 * @param m Pointer to matrix_float_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 * @note Easy to parallelize
 */
bool
m_isDoublyStochastic_float(matrix_float_t *m);

/**
 * @brief Determines if the matrix is substochastic.  In other words the matrix is square, it has nonnegative real numbers, and the sum of each row is less than or equal to 1.  All right and doubly stochastic matrices are substochastic as well
 * @param m Pointer to matrix_float_t object.
 * @return boolean.  True if orthogonal, false otherwise.
 * @note Easy to parallelize
 */
bool
m_isSubStochastic_float(matrix_float_t *m);

#endif