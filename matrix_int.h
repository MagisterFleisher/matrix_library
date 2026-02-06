/**
 * @file matrix_int.h
 * @brief The header file containing matrix structs, typedefs, and function prototypes for integer matrices.  Note, this does not include double size integers.
 * @author Aaron Fleisher
 * @date 2026-02-06
 * 
 * 
 */

 #ifndef MATRIX_INT_H
 #define MATRIX_INT_H

#include "myMatrix.h"


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
} matrix_int_t;


 #endif