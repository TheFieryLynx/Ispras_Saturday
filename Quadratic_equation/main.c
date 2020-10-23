#include "headerfile.h"

/**
 * This program solves a quadratic equation Ax^2 + Bx + C;
 * Run this program with Makefile: make && ./run
 * 
 * To see the documentation of this project:
 * doxygen Doxyfile
 * *your_browser* doxygen/html/index.html
 * 
 * 
 * Execution of the program
 * starts here.
 *
 * @param root_1 first root
 * @param root_2 second root
 * @param coef_a Coefficient A
 * @param coef_b Coefficient B
 * @param coef_c Coefficient C
 *  
 * @return Program exit status
 */

int main(void)
{
    test_function();
    double root_1, root_2, coef_a, coef_b, coef_c;
    int number_of_roots;
    reading_coefficients(&coef_a, &coef_b, &coef_c);
    number_of_roots = roots_calculation(&root_1, &root_2, coef_a, coef_b, coef_c);
    print_roots(number_of_roots, root_1, root_2);
}