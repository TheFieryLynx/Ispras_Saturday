#include "headerfile.h"

void assert_int(int a, int b) 
{
    static int i = 1;
    assert(a == b);
    printf("Roots_calculation Test %d passed.\n", i++);
}

void assert_float(double a, double b) 
{
    static int i = 1;
    assert(IsZero(a - b));
    printf("Root correctness Test %d passed.\n", i++);
}

/**
 * Test function
 * 
 * @param root_1 first root
 * @param root_2 second root
 * @param coef_a Coefficient A
 * @param coef_b Coefficient B
 * @param coef_c Coefficient C
 *  
 * @return void
 */

void test_function()
{
    double root_1 = NAN, root_2 = NAN;
    double coef_a = 1, coef_b = 2, coef_c = 10;
    assert_int(roots_calculation(&root_1, &root_2, coef_a, coef_b, coef_c), 0);
    
    coef_a = 0, coef_b = 2, coef_c = 10;
    assert_int(roots_calculation(&root_1, &root_2, coef_a, coef_b, coef_c), 1);

    coef_a = 1, coef_b = 3, coef_c = -4;
    assert_int(roots_calculation(&root_1, &root_2, coef_a, coef_b, coef_c), 2);

    coef_a = 0, coef_b = 2, coef_c = 10;
    roots_calculation(&root_1, &root_2, coef_a, coef_b, coef_c);
    assert_float(root_1, -5.0);

    coef_a = 1, coef_b = 3, coef_c = -4;
    roots_calculation(&root_1, &root_2, coef_a, coef_b, coef_c); 
    assert_float(root_1, 1.0); 
    assert_float(root_2, -4.0); 
} 