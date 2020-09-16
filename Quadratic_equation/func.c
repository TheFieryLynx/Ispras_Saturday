#include "head.h"

/**
 * This is file with all functions.
 * 
 * @param EPS const close to zero
 */

const double EPS = 1E-6;

/**
 * Checks the variable for zero
 * 
 * @param value double value
 * @return true if value is zero
 */

_Bool IsZero(double value) 
{
    return fabs(value) < EPS;
}


/**
 * Checks the variable for positivity
 * 
 * @param value double value
 * @return true if value is positive
 */

_Bool IsPositive(double value)
{
    return value > EPS;
}

/**
 * Reading coefficients A, B, C
 * 
 * @param coef_a Coefficient A
 * @param coef_b Coefficient B
 * @param coef_c Coefficient C
 * @return void
 */

void reading_coefficients(double *coef_a, double *coef_b, double *coef_c)
{
    printf("Please input coefficients of the equation.\n");
    printf("Input a: ");
    scanf("%lf", coef_a);
    printf("Input b: ");
    scanf("%lf", coef_b);
    printf("Input c: ");
    scanf("%lf", coef_c);
}

/**
 * This function calculates roots of the equation and returns the number of roots
 * 
 * @param root_1 first root
 * @param root_2 second root
 * @param coef_a Coefficient A
 * @param coef_b Coefficient B
 * @param coef_c Coefficient C
 * @return number_of_roots
 */


int roots_calculation(double *root_1,  double *root_2, double *coef_a, double *coef_b, double *coef_c)
{
    double d = *coef_b * *coef_b - 4 * *coef_a * *coef_c;
    if (IsZero(*coef_a)) {
        if (!IsZero(*coef_b)) {
            *root_1 = -*coef_c / *coef_b;
            return 1;
        }
    } else if (IsZero(d)) {
        *root_1 = -*coef_b / (2 * *coef_a);
        return 1;
    } else if (IsPositive(d)) {
        *root_1 = (-*coef_b + sqrt(d)) / (2 * *coef_a);
        *root_2 = (-*coef_b - sqrt(d)) / (2 * *coef_a);
        return 2;
    }
    return 0;
}


/**
 * This function prints roots depending on the quantity
 * 
 * @param number_of_roots number of roots returned from roots_calculation function
 * @param root_1 first root
 * @param root_2 second root
 * @return void
 */

void print_roots(int number_of_roots, double root_1, double root_2)
{
    if (number_of_roots == 0) {
        printf ("There are no roots\n");
    } else if (number_of_roots == 1) {
        printf ("There is only one root: %lf\n", root_1);
    } else {
        printf ("There are two roots: %lf %lf\n", root_1, root_2);
    }
}