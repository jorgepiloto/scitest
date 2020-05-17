
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
 * Tests the addition of two integer numbers
 */
void test_two_int_not_equal( void ) {
    /* Define actual and expected values for the test */
    int actual = 3;
    int expected = 4;
    /* Assert if both integer values are equal */
    ASSERT_INT_NOT_EQUAL(actual, expected);
}

/**
 * Test if two floats are within absolute tolerance
 */
void test_two_float_equal( void ) {
    /* Define actual and expected values for the test */
    float actual = 0.999;
    float expected = 1.000;
    float tol = 0.001;
    /* Assert if both integer values are equal */
   ASSERT_FLOAT_EQUAL(actual, expected, tol);
}

/**
 * Main function in which tests are collected
 */
int main ( void ) {

    /* Test session begins */
    START_TEST_SESSION();

    /* A collection of tests */
    RUN_TEST("test_add_two_numbers", test_add_two_numbers);
    RUN_TEST("test_two_int_not_equal", test_two_int_not_equal);
    RUN_TEST("test_two_float_equal", test_two_float_equal);

    /* Collect results and finish test session */
    FINISH_TEST_SESSION();

    return 0;
}

