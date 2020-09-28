#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/**
 * Head file
 */

void reading_coefficients(double *coef_a, double *coef_b, double *coef_c);
int roots_calculation(double *root_1,  double *root_2, double coef_a, double coef_b, double coef_c);
void print_roots(int number_of_roots, double root_1, double root_2);
void test_function();
_Bool IsZero(double value);
_Bool IsPositive(double value);