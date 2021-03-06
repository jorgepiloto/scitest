/**
 * File: scitest.h
 *
 * Author: Jorge Martinez (jorge@on-orbit.dev)
 *
 * Description: Holds scientific testing utilities.
 *
 * Date: 15th May, 2020
 */


#ifndef _SCITEST_H_
#define _SCITEST_H_


#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>


/**
 * ANSI color definitions
 */
#define NO_COLOR    "\x1b[0m"
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define BROWN       "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA     "\x1b[35m"
#define CYAN        "\x1b[36m"
#define GRAY        "\x1b[37m"


/**
 * Message collection
 */
#define MSG_OK do { printf(GREEN "[PASSED]\n" NO_COLOR); } while (0)
#define MSG_FAIL do { printf(RED "[FAILED]\n" NO_COLOR); } while (0)
#define MSG_XFAIL do { printf(CYAN "[XFAILED]\n" NO_COLOR); } while (0)


/* Passed, failed and total amount of tests units */
int PASSED = 0;
int FAILED = 0;
int TOTAL = 0;


/**
 * Assertion macro for comparing equal integers 
 */
#define ASSERT_INT_EQUAL(actual, desired) do {   \
    if (actual == desired) {               \
        MSG_OK; PASSED++; TOTAL++;         \
    } else {                               \
        MSG_FAIL;                          \
        printf("Actual: %d\tExpected: %d\n\n", actual, desired); \
        FAILED++; TOTAL++;                 \
    }                                      \
    } while (0)


/**
 * Asserion macro for comparing different integers
 */
#define ASSERT_INT_NOT_EQUAL(actual, desired) do {   \
    if (actual != desired) {               \
        MSG_OK; PASSED++; TOTAL++;         \
    } else {                               \
        MSG_FAIL;                          \
        printf("Actual: %d\tExpected: %d\n\n", actual, desired); \
        FAILED++; TOTAL++;                 \
    }                                      \
    } while (0) 


/**
 * Asserion macro for comparing two equal floats
 */
#define ASSERT_FLOAT_EQUAL(actual, desired, tol) do {   \
    if (fabs(actual - desired) <= tol) {               \
        MSG_OK; PASSED++; TOTAL++;         \
    } else {                               \
        MSG_FAIL;                          \
        printf("Actual: %f\nExpected: %f\n\n", actual, desired); \
        FAILED++; TOTAL++;                 \
    }                                      \
    } while (0) 


/**
 * Asserion macro for comparing two different floats
 */
#define ASSERT_FLOAT_NOT_EQUAL(actual, desired, tol) do {   \
    if (fabs(actual - desired) >= tol) {               \
        MSG_OK; PASSED++; TOTAL++;         \
    } else {                               \
        MSG_FAIL;                          \
        printf("Actual: %f\tExpected: %f\n\n", actual, desired); \
        FAILED++; TOTAL++;                 \
    }                                      \
    } while (0) 


/**
 * Asserion macro for comparing two equal doubles
 */
#define ASSERT_DOUBLE_EQUAL(actual, desired, tol) do {   \
    if (dabs(actual - desired) <= tol) {               \
        MSG_OK; PASSED++; TOTAL++;         \
    } else {                               \
        MSG_FAIL;                          \
        printf("Actual: %lf\tExpected: %lf\n\n", actual, desired); \
        FAILED++; TOTAL++;                 \
    }                                      \
    } while (0) 


/**
 * Asserion macro for comparing two different doubles
 */
#define ASSERT_DOUBLE_NOT_EQUAL(actual, desired, tol) do {   \
    if (dabs(actual - desired) >= tol) {               \
        MSG_OK; PASSED++; TOTAL++;         \
    } else {                               \
        MSG_FAIL;                          \
        printf("Actual: %lf\tExpected: %lf\n\n", actual, desired); \
        FAILED++; TOTAL++;                 \
    }                                      \
    } while (0) 


/**
 * Assertion macro for comparing two strings
 */
#define ASSERT_STRING_EQUAL(actual, desired) do {\
    if (strcmp(actual, desired) == 0) {    \
        MSG_OK; PASSED++; TOTAL++;         \
    } else {                               \
        MSG_FAIL;                          \
        printf("Actual: %s\tExpected: %s\n\n", actual, desired); \
        FAILED++; TOTAL++;                 \
    }                                      \
    } while (0)


/**
 * Macro for running tests and avoiding function pointers
 */
#define RUN_TEST(test_name, test_func) do { \
    printf("%s...  ", test_name);           \
    test_func();                            \
    } while (0)


/**
 * Abosulte value for a float quantity
 */
float fabs(float a) {
    return a < 0 ? -1 * a : a;
}


/**
 * Absolute value for a double quantity
 */
double dabs(double a) {
    return a < 0 ? -1 * a : a;
}


/**
 * Starts test session by printing a centred colored message
 */
void START_TEST_SESSION( void ) {

    /* Get window size */
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);    
    
    for (int i = 0; i < w.ws_col / 2 - 10; i++ ) {
        printf("=");
    }

    printf(GREEN " TEST SESSION STARTS " NO_COLOR);

    for (int i = 0; i < w.ws_col / 2 - 11; i++ ) {
        printf("=");
    }
    printf(" \n");

}


/**
 * Finish test session and output the results
 */
void FINISH_TEST_SESSION( void ) {

    printf("\n==========================\n");
    printf(GREEN "PASSED: %d\t" RED "FAILED: %d\n" NO_COLOR, PASSED, FAILED);

}


#endif /* _SCITEST_H_ */
