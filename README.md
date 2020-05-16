SCITEST: a simple header file for unit testing in C
===================================================

Although there are lots of testing frameworks available for C programming I
found most of them "too complex" for such a simple task. Therefore I ended up
developing my own testing framework oriented to scientific development.

How to use
----------
Simply copy the **scitest.h** header inside yout `tests/` directory. Let us see
how to create a simple file test under the name `test_example.c`:

```c
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
```

This output is very similar to the one shown by the Pytest framework from Python
language:

```bash
============================ TEST SESSION STARTS ========================= 

test_add_two_numbers...  [PASSED]


==========================
PASSED: 1	FAILED: 0
```


Future improvements
-------------------

I still need to add more MACROS related to floats, double, pointers, structures
and others. Hope to do it as soon as I required them.

