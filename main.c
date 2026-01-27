/**
 * @file main.c
 * @brief The basic file for beginning development of this matrix library
 * @author Aaron Fleisher
 * @date 2026-01-23
 * 
 * @todo Find a better way to hold the allocations in memory, perhaps an arena or pool.
 * @todo Use discriminated unions to make an easier way to use matrices of different types
 */
#include "myMatrix.h"

int
main(int argument_count, char **argument_vector) {

    matrix_int_t *m = initializeMatrix_int(3, 3);
    matrix_int_t *m2 = initializeMatrix_int(3, 3);
    
    int matrix_array[9] = {1, 2, 3, 
                        4, 5, 6, 
                        7, 8, 9};
    copyArrayToMatrix_int(m, matrix_array, 9);

    printMatrix_int(m);
    (void) printf("At m[2, 1] : %d\n", m_at_int(m, 1,0));

    int matrix_array2[9] = {1, 2, 3,
                            4, 5, 6,
                            7, 8, 9};
    copyArrayToMatrix_int(m2, matrix_array2, 9);
    printMatrix_int(m2);

    matrix_int_t *test_copy = m_multiply_int(m, m2);
    printMatrix_int(test_copy);
    freeMatrix_int(test_copy);

    freeMatrix_int(m2);
    freeMatrix_int(m);

    (void) printf("Argument count: %d\n", argument_count);
    return 0;
}