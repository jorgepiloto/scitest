
#include "scitest.h"

/**
 * Tests the addition of two integer numbers
 */
void test_add_two_numbers( void ) {
    /* Define actual and expected values for the test */
    int actual = 2 + 2;
    int expected = 4;
    /* Assert if both integer values are equal */
    ASSERT_INT_EQUAL(actual, expected);
}


/**
 * Main function in which tests are collected
 */
int main ( void ) {

    /* Test session begins */
    START_TEST_SESSION();

    /* A collection of tests */
    RUN_TEST("test_add_two_numbers", test_add_two_numbers);

    /* Collect results and finish test session */
    FINISH_TEST_SESSION();

    return 0;
}

