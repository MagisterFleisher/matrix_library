/**
 * @file myMatrix.c
 * @brief Matrix library functions
 * @author Aaron Fleisher
 * @date 2026-01-26
 * 
 * @todo Find a better way to hold the allocations in memory, perhaps an arena or pool.
 * @todo Use discriminated unions to make an easier way to use matrices of different types
 * @todo Use a better random number generator such as Mersenne twister or openSSL's random number generator
 * @todo Add a description of the space and time O() values of each function
 * @todo Ensure const correctness
 */
#include "myMatrix.h"


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