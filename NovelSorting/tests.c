#include "headerfile.h"

/**
 * Assert function for cmp functuions: Reverse_Cmp() and Straight_cmp()
 * @param a - assert first argument
 * @param b - assert second argument
 */
void assert_cmp(int a, int b) 
{
    static int i = 1;
    assert(a == b);
    
    printf("CmpTest %d passed.\n", i++);
}

/**
 * Assert function for qsort functuion
 * @param a - assert first argument
 * @param b - assert second argument
 */

void assert_qsort(char **a, char **b, int n)
{
    static int i = 1;
    for(int j = 0; j < n; j++) {
        assert(Straight_cmp(a[j], b[j]) == 0);
    }
    printf("QsortTest %d passed.\n", i++);
}

/**
 * calls all tests
 */

void Run_tests()
{
    test_Straight_cmp();
    test_Reverse_Cmp();
    test_MyQsort();
}

/**
 * Set of Straight_cmp() function tests
 */

void test_Straight_cmp()
{
    assert_cmp(Straight_cmp((char *)("тест"), (char *)("тест")), 0);
    assert_cmp(Straight_cmp((char *)("теста"), (char *)("тест")), 1);
    assert_cmp(Straight_cmp((char *)("тест"), (char *)("теста")), -1);
    assert_cmp(Straight_cmp((char *)(""), (char *)("")), 0);
    assert_cmp(Straight_cmp((char *)("а"), (char *)("")), 1);
}

/**
 * Set of Reverse_Cmp() function tests
 */

void test_Reverse_Cmp()
{
    assert_cmp(Reverse_Cmp((char *)("тестишь"), (char *)("тестишь")), 0);
    assert_cmp(Reverse_Cmp((char *)("атестишь"), (char *)("тестишь")), 1);
    assert_cmp(Reverse_Cmp((char *)("тестишь"), (char *)("атестишь")), -1);
    assert_cmp(Reverse_Cmp((char *)(""), (char *)("")), 0);
    assert_cmp(Reverse_Cmp((char *)("а"), (char *)("")), 1);
}

/**
 * Set of MyQsort() function tests
 */

void test_MyQsort()
{
    char *unsorted_1[4] = {"б", "а", "г", "в"};
    My_Qsort(unsorted_1, 4, Straight_cmp);
    char *sorted_1[4] = {"а", "б", "в", "г"};
    assert_qsort(unsorted_1, sorted_1, 4);

    char *unsorted_2[4] = {"бшь", "ашь", "гшь", "вшь"};
    My_Qsort(unsorted_2, 4, Reverse_Cmp);
    char *sorted_2[4] = {"ашь", "бшь", "вшь", "гшь"};
    assert_qsort(unsorted_2, sorted_2, 4);

}