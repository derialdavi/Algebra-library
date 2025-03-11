#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "../unity/unity.h"
#include "../include/linear-algebra.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_get_conjucate(void) {
    complex_number z = {1, 2};
    complex_number conjucate = get_conjucate(z);

    TEST_ASSERT_EQUAL_FLOAT(1, conjucate.real_part);
    TEST_ASSERT_EQUAL_FLOAT(-2, conjucate.imaginary_part);
}

int main(void) {

   UNITY_BEGIN();
   RUN_TEST(test_get_conjucate);
   return UNITY_END();
   
}
