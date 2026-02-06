/**
 * @file myMatrix.h
 * @brief Header file of matrix library holding data structures and function prototypes
 * @author Aaron Fleisher
 * @date 2026-01-26
 * 
 * @todo Find a better way to hold the allocations in memory, perhaps an arena or pool.
 * @todo Use discriminated unions to make an easier way to use matrices of different types
 */

#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/**
 * @note Not all matrices have eigenvectors in the real numbers.  But, all matrices have eigenvectors if one expands the field to the complex numbers.
 */
#include <complex.h>


#endif /** MYMATRIX_H */