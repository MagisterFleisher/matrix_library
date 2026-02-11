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

void
testMatrixInt(void) {

    matrix_int_t *m = initializeMatrix_int(3, 3);
    matrix_int_t *m2 = initializeMatrix_int(3, 3);
    /* matrix_int_t *m3 = initializeMatrix_int(3, 3);
    matrix_int_t *m4 = initializeMatrix_int(3, 3);
    matrix_int_t *m5 = initializeMatrix_int(3, 1);
    matrix_int_t *m6 = initializeMatrix_int(1, 3);
    matrix_int_t *m7 = initializeMatrix_int(1, 1);
 */
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
/* 
    int *column2_matrix2 = m_selectColumn_int(m2, 1);
    (void) printf("\nColumn 2 of matrix 2: ");
    for(int index = 0; index < m->i; index++) {
        (void) printf("%d ", column2_matrix2[index]);
    }
    (void) printf("\n");
    
    int *row2_matrix2 = m_selectRow_int(m2, 1);
    (void) printf("\nRow 2 of matrix 2: ");
    for(int index = 0; index < m->j; index++) {
        (void) printf("%d ", row2_matrix2[index]);
    }
    (void) printf("\n");

    int dot_product = v_dotProduct_int(row2_matrix2, column2_matrix2, 3);

    (void) printf("Dot product of matrix and column: %d\n", dot_product);
    free(column2_matrix2);
    free(row2_matrix2); */

    (void) printf("\tTest equality between m1 and m2: %d\n", m_isEqual_int(m, m2));

    (void) printf("\n\nTest transposition of m2.....\n");
    matrix_int_t *transposed_m2 = m_transpose_int(m2);
    printMatrix_int(transposed_m2);
    freeMatrix_int(transposed_m2);
    
    matrix_int_t *test_multiplication = m_MatrixMultiply_int(m, m2);
    (void) printf("\tTest multiplication of matrix 1 X matrix 2: \n");
    printMatrix_int(test_multiplication);

    /*

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
*/

    matrix_int_t *random_matrix2 = generateRandomMatrix_int(4000, 4000, 0, 100);
    (void) printf("\tTest random matrix 10k x 10k, values 0 to 100:\n");
    //printMatrix_int(random_matrix2);

    matrix_int_t *big_multiplication = generateRandomMatrix_int(4000, 4000, 0, 100);
    (void) printf("\tTest multiplication of two 10k x 10k matrices:\n");

    float average_time = 0.0;
    float total_profile = 0.0;
    int iterations_profile = 1000;
   // for(int index = 0; index < iterations_profile; index++) {
        clock_t time_start = clock();
        matrix_int_t *test_multiplication4 = m_MatrixMultiply_int(random_matrix2, big_multiplication);
        freeMatrix_int(test_multiplication4);
        clock_t time_end = clock();
        total_profile += (float) (time_end - time_start) / CLOCKS_PER_SEC;
    //}
    average_time = (total_profile / ((float) iterations_profile));
    (void) printf("-------------------\n\t\tBig matrix average performance: %f\n--------------------\n\n", average_time);


    //    printMatrix_int(test_multiplication4);
/*     (void) printf("\tTesting big identity multiplication...");
    matrix_int_t *big_identity = generateIdentityMatrix_int(10000);
    matrix_int_t *big_multiplication_identity = m_MatrixMultiply_int(big_identity, big_multiplication);
 */
   /* (void) printf("\tTested big identity multiplication\n");
    
    matrix_int_t *test_identity_m = generateIdentityMatrix_int(4);
    (void) printf("\tTest Generate identity matrix, 4 x 4:\n");
    */
   // printMatrix_int(test_identity_m);

 
/*     freeMatrix_int(big_identity);
    freeMatrix_int(big_multiplication_identity);
 */    
    //freeMatrix_int(big_multiplication);

    //freeMatrix_int(random_matrix);
    //freeMatrix_int(random_matrix2);
    
    //freeMatrix_int(test_identity_m);
    //freeMatrix_int(test_multiplication3);
    //freeMatrix_int(test_multiplication2);
    /* freeMatrix_int(m7);
    freeMatrix_int(m6);
    freeMatrix_int(m5);
    freeMatrix_int(m4);
    freeMatrix_int(m3); */
    freeMatrix_int(test_multiplication);
    freeMatrix_int(m2);
    freeMatrix_int(m);
}

void
testMatrixDouble(void) {

    matrix_double_t *m = initializeMatrix_double(3, 3);
     matrix_double_t *m2 = initializeMatrix_double(3, 3);
/*    matrix_double_t *m3 = initializeMatrix_double(3, 3);
    matrix_double_t *m4 = initializeMatrix_double(3, 3);
    matrix_double_t *m5 = initializeMatrix_double(3, 1);
    matrix_double_t *m6 = initializeMatrix_double(1, 3);
    matrix_double_t *m7 = initializeMatrix_double(1, 1);
 */
    const double matrix_array[9] = {1.0, 2.0, 3.0, 
                        4.0, 5.0, 6.0, 
                        7.0, 8.0, 9.0};
    copyArrayToMatrix_double(m, matrix_array, 9);

    (void) printf("\tMatrix1: \n");
    printMatrix_double(m);
    (void) printf("At m[2, 1] : %lf\n", m_at_double(m, 1,0));
    const double matrix_array2[9] = {1.0, 2.0, 3.0,
        4.0, 5.0, 6.0,
        7.0, 8.0, 9.0};
    copyArrayToMatrix_double(m2, matrix_array2, 9);
    (void) printf("\tMatrix 2:\n");
    printMatrix_double(m2);

    matrix_double_t *add_m_m2 = m_MatrixAdd_double(m, m2);
    printMatrix_double(add_m_m2);
    freeMatrix_double(add_m_m2);


    
    double *column2_matrix2 = m_selectColumn_double(m2, 1);
    (void) printf("\nColumn 2 of matrix 2: ");
    for(int index = 0; index < m->i; index++) {
        (void) printf("%lf ", column2_matrix2[index]);
        }
    (void) printf("\n");
    free(column2_matrix2);
    
    double *row2_matrix2 = m_selectRow_double(m2, 1);
    (void) printf("\nRow 2 of matrix 2: ");
    for(int index = 0; index < m->j; index++) {
        (void) printf("%lf ", row2_matrix2[index]);
    }
    (void) printf("\n");
    free(row2_matrix2);
    
    (void) printf("\tTest equality between m1 and m2: %d\n", m_isEqual_double(m, m2));
    matrix_double_t *test_multiplication = m_MatrixMultiply_double(m, m2);
    (void) printf("\tTest multiplication of matrix 1 X matrix 2: \n");
    printMatrix_double(test_multiplication);

    /* 

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

    matrix_int_t *random_matrix2 = generateRandomMatrix_int(10000, 10000, 0, 100);
    (void) printf("\tTest random matrix 1k x 1k, values 0 to 100:\n");
  //  printMatrix_int(random_matrix2);

    matrix_int_t *big_multiplication = generateRandomMatrix_int(10000, 10000, 0, 100);
    (void) printf("\tTest multiplication of two 10k x 10k matrices:\n");

    float average_time = 0.0;
    float total_profile = 0.0;
    int iterations_profile = 1000;
    for(int index = 0; index < iterations_profile; index++) {
        clock_t time_start = clock();
        matrix_int_t *test_multiplication4 = m_MatrixMultiply_int(random_matrix2, big_multiplication);
        freeMatrix_int(test_multiplication4);
        clock_t time_end = clock();
        total_profile += (float) (time_end - time_start) / CLOCKS_PER_SEC;
    }
    average_time = (total_profile / ((float) iterations_profile));
    (void) printf("-------------------\n\t\tBig matrix average performance: %f\n--------------------\n\n", average_time);


    //    printMatrix_int(test_multiplication4);
    (void) printf("\tTesting big identity multiplication...");
    matrix_int_t *big_identity = generateIdentityMatrix_int(10000);
    matrix_int_t *big_multiplication_identity = m_MatrixMultiply_int(big_identity, big_multiplication);

    (void) printf("\tTested big identity multiplication\n");
    
    matrix_int_t *test_identity_m = generateIdentityMatrix_int(4);
    (void) printf("\tTest Generate identity matrix, 4 x 4:\n");
   // printMatrix_int(test_identity_m);

 
    freeMatrix_int(big_identity);
    freeMatrix_int(big_multiplication_identity);
    
    freeMatrix_int(big_multiplication);

    freeMatrix_int(random_matrix);
    freeMatrix_int(random_matrix2);
    
    freeMatrix_int(test_identity_m);
    freeMatrix_int(test_multiplication3);
    freeMatrix_int(test_multiplication2);
    freeMatrix_int(m7);
    freeMatrix_int(m6);
    freeMatrix_int(m5);
    freeMatrix_int(m4);
    freeMatrix_int(m3);*/
    freeMatrix_double(test_multiplication); 
    freeMatrix_double(m2);
    freeMatrix_double(m);
}



int
main(int argument_count, char **argument_vector) {
    // testMatrixInt();
    testMatrixDouble();
    (void) printf("Argument count: %d\n", argument_count);
    return 0;
}