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

    (void) printf("\tMatrix1: \n");
    printMatrix_int(m);
    (void) printf("At m[2, 1] : %d\n", m_at_int(m, 1,0));

    const int matrix_array2[9] = {1, 2, 3,
                            4, 5, 6,
                            7, 8, 9};
    copyArrayToMatrix_int(m2, matrix_array2, 9);
    (void) printf("\tMatrix 2:\n");
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

    (void) printf("\tTest equality between m1 and m2: %d\n", m_isEqual_int(m, m2));

    matrix_int_t *test_multiplication = m_MatrixMultiply_int(m, m2);
    (void) printf("\tTest multiplication of matrix 1 X matrix 2: \n");
    printMatrix_int(test_multiplication);

    const int matrix_array3[9] = {1, 0, 1,
                            1, 1, 1,
                            0, 1, 0};
    copyArrayToMatrix_int(m3, matrix_array3, 9);
    (void) printf("\tMatrix 3:\n");
    printMatrix_int(m3);

    (void) printf("\tTest equality between m1 and m3: %d\n", m_isEqual_int(m, m3));

    const int matrix_array4[9] = {1, 0, 0,
                            0, 1, 0,
                            0, 0, 1};
    copyArrayToMatrix_int(m4, matrix_array4, 9);
    (void) printf("\tMatrix 4:\n");
    printMatrix_int(m4);

    const int matrix_array5[3] = {1, 0, 0};
    copyArrayToMatrix_int(m5, matrix_array5, 3);
    (void) printf("\tMatrix 5:\n");
    printMatrix_int(m5);

    const int matrix_array6[3] = {1, 
                                0, 
                                0};
    copyArrayToMatrix_int(m6, matrix_array6, 3);
    (void) printf("\tMatrix 6:\n");
    printMatrix_int(m6);

    const int matrix_array7[1] = {1};
    copyArrayToMatrix_int(m7, matrix_array7, 1);
    (void) printf("\tMatrix 7:\n");
    printMatrix_int(m7);

    matrix_int_t *test_multiplication2 = m_MatrixMultiply_int(m4, m2);
    (void) printf("\tTest multiplication m4 x m2\n");
    printMatrix_int(test_multiplication2);

    matrix_int_t *test_multiplication3 = m_MatrixMultiply_int(m2, m4);
    (void) printf("\tTest multiplication m2 x m4\n");
    printMatrix_int(test_multiplication3);

    matrix_int_t *random_matrix = generateRandomMatrix_int(4, 4, 0, 100);
    (void) printf("\tTest random matrix 4 x 4, values 0 to 100:\n");
    printMatrix_int(random_matrix);

    matrix_int_t *random_matrix2 = generateRandomMatrix_int(10, 10, 0, 100);
    (void) printf("\tTest random matrix 1k x 1k, values 0 to 100:\n");
    printMatrix_int(random_matrix2);

/*     matrix_int_t *big_multiplication = generateRandomMatrix_int(1000, 1000, 0, 100);
    matrix_int_t *test_multiplication4 = m_MatrixMultiply_int(random_matrix2, big_multiplication);
    (void) printf("\tTest multiplication of two 1k x 1k matrices:\n");
    printMatrix_int(test_multiplication4);
    (void) printf("\tTesting big identity multiplication...");
    matrix_int_t *big_identity = generateIdentityMatrix_int(1000);
    matrix_int_t *big_multiplication_identity = m_MatrixMultiply_int(big_identity, big_multiplication);
    (void) printf("\tTested big identity multiplication\n");
    
 */    matrix_int_t *test_identity_m = generateIdentityMatrix_int(4);
    (void) printf("\tTest Generate identity matrix, 4 x 4:\n");
    printMatrix_int(test_identity_m);

/* 
    freeMatrix_int(big_identity);
    freeMatrix_int(big_multiplication_identity);
    
    freeMatrix_int(big_multiplication);
    freeMatrix_int(test_multiplication4);
 */

    freeMatrix_int(random_matrix);
    freeMatrix_int(random_matrix2);
    
    freeMatrix_int(test_identity_m);
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