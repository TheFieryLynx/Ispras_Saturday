#include "head.h"

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
    printf("Test1: 0 roots\t");
    assert(roots_calculation(&root_1, &root_2, &coef_a, &coef_b, &coef_c) == 0);
    printf("Test1 passed\n");

    coef_a = 0, coef_b = 2, coef_c = 10;
    printf("Test2: 1 root\t");
    assert(roots_calculation(&root_1, &root_2, &coef_a, &coef_b, &coef_c) == 1);
    printf("Test2 passed\n");

    coef_a = 1, coef_b = 3, coef_c = -4;
    printf("Test3: 2 roots\t");
    assert(roots_calculation(&root_1, &root_2, &coef_a, &coef_b, &coef_c) == 2);
    printf("Test3 passed\n");

    coef_a = 0, coef_b = 2, coef_c = 10;
    printf("Test4: 1 root\t");
    assert(roots_calculation(&root_1, &root_2, &coef_a, &coef_b, &coef_c) && root_1 == -5);
    printf("Test4 passed\n");

    coef_a = 1, coef_b = 3, coef_c = -4;
    printf("Test5: 2 roots\t");
    assert(roots_calculation(&root_1, &root_2, &coef_a, &coef_b, &coef_c) && root_1 == 1 && root_2 == -4);
    printf("Test5 passed\n"); 
} 