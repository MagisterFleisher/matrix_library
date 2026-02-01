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
    matrix_int_t *m3 = initializeMatrix_int(3, 3);
    matrix_int_t *m4 = initializeMatrix_int(3, 3);
    matrix_int_t *m5 = initializeMatrix_int(3, 1);
    matrix_int_t *m6 = initializeMatrix_int(1, 3);
    matrix_int_t *m7 = initializeMatrix_int(1, 1);

    const int matrix_array[9] = {1, 2, 3, 
                        4, 5, 6, 
                        7, 8, 9};
    copyArrayToMatrix_int(m, matrix_array, 9);

    printMatrix_int(m);
    (void) printf("At m[2, 1] : %d\n", m_at_int(m, 1,0));

    const int matrix_array2[9] = {1, 2, 3,
                            4, 5, 6,
                            7, 8, 9};
    copyArrayToMatrix_int(m2, matrix_array2, 9);
    printMatrix_int(m2);

    int *column2_matrix2 = m_selectColumn_int(m2, 1);
    (void) printf("\nColumn 2 of matrix 2: ");
    for(int index = 0; index < m->i; index++) {
        (void) printf("%d ", column2_matrix2[index]);
    }
    (void) printf("\n");
    free(column2_matrix2);

    int *row2_matrix2 = m_selectRow_int(m2, 1);
    (void) printf("\nRow 2 of matrix 2: ");
    for(int index = 0; index < m->j; index++) {
        (void) printf("%d ", row2_matrix2[index]);
    }
    (void) printf("\n");
    free(row2_matrix2);

    matrix_int_t *test_multiplication = m_multiply_int(m, m2);

    printMatrix_int(test_multiplication);

    const int matrix_array3[9] = {1, 0, 1,
                            1, 1, 1,
                            0, 1, 0};
    copyArrayToMatrix_int(m3, matrix_array3, 9);
    printMatrix_int(m3);

    const int matrix_array4[9] = {1, 0, 0,
                            0, 1, 0,
                            0, 0, 1};
    copyArrayToMatrix_int(m4, matrix_array4, 9);
    printMatrix_int(m4);

    const int matrix_array5[3] = {1, 0, 0};
    copyArrayToMatrix_int(m5, matrix_array5, 3);
    printMatrix_int(m5);

    const int matrix_array6[3] = {1, 
                                0, 
                                0};
    copyArrayToMatrix_int(m6, matrix_array6, 3);
    printMatrix_int(m6);

    const int matrix_array7[1] = {1};
    copyArrayToMatrix_int(m7, matrix_array7, 1);
    printMatrix_int(m7);

    matrix_int_t *test_multiplication2 = m_multiply_int(m4, m2);
    printMatrix_int(test_multiplication2);

    matrix_int_t *test_multiplication3 = m_multiply_int(m2, m4);
    printMatrix_int(test_multiplication3);

    freeMatrix_int(test_multiplication3);
    freeMatrix_int(test_multiplication2);
    freeMatrix_int(m7);
    freeMatrix_int(m6);
    freeMatrix_int(m5);
    freeMatrix_int(m4);
    freeMatrix_int(m3);
    freeMatrix_int(test_multiplication);
    freeMatrix_int(m2);
    freeMatrix_int(m);

    (void) printf("Argument count: %d\n", argument_count);
    return 0;
}