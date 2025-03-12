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

/*
 * TESTING FOR CONJUCATE VALUE
 *  only the imaginary part should be negated
 *  only particular case is when the imaginary part is 0
 */ 
void test_get_conjucate(void) {
    complex_number z = {1, 2};
    complex_number conjucate = get_conjucate(z);

    TEST_ASSERT_EQUAL_FLOAT(1, conjucate.real_part);
    TEST_ASSERT_EQUAL_FLOAT(-2, conjucate.imaginary_part);

    complex_number z1 = {5, -7};
    complex_number conjucate1 = get_conjucate(z1);

    TEST_ASSERT_EQUAL_FLOAT(5, conjucate1.real_part);
    TEST_ASSERT_EQUAL_FLOAT(7, conjucate1.imaginary_part);

    complex_number z2 = {-12, 0};
    complex_number conjucate2 = get_conjucate(z2);

    TEST_ASSERT_EQUAL_FLOAT(-12, conjucate2.real_part);
    TEST_ASSERT_EQUAL_FLOAT(0, conjucate2.imaginary_part);
}

/*
 * TESTING FOR ABSOLUTE VALUE:
 *  no particular cases
 *  here the return value is checked in a range (most of the times)
 *  because of the floating point precision
 */
void test_get_absolute_value(void) {
    complex_number z = {3, 4};
    double absolute_value = get_absolute_value(z);

    TEST_ASSERT_EQUAL_FLOAT(5, absolute_value);

    complex_number z1 = {0, 0};
    double absolute_value1 = get_absolute_value(z1);

    TEST_ASSERT_EQUAL_FLOAT(0, absolute_value1);

    complex_number z2 = {1, 1};
    double absolute_value2 = get_absolute_value(z2);

    TEST_ASSERT_FLOAT_WITHIN(1e-5, 1.41421, absolute_value2);

    complex_number z3 = {1, -1};
    double absolute_value3 = get_absolute_value(z3);

    TEST_ASSERT_FLOAT_WITHIN(1e-5, 1.41421, absolute_value3);

    complex_number z4 = {-1, -1};
    double absolute_value4 = get_absolute_value(z4);

    TEST_ASSERT_FLOAT_WITHIN(1e-5, 1.41421, absolute_value4);

    complex_number z5 = {3, 4};
    double absolute_value5 = get_absolute_value(z5);

    TEST_ASSERT_EQUAL_FLOAT(5, absolute_value5);

    complex_number z6 = {5, 6};
    double absolute_value6 = get_absolute_value(z6);

    TEST_ASSERT_FLOAT_WITHIN(1e-4, 7.81024, absolute_value6);
}

/*
 * TESTING FOR MULTIPLICATIVE INVERSE:
 *  the only particular case is when the real part and the imaginary part are 0
 *  in this case the return value should be NaN
 */
void test_get_multiplicative_inverse(void) {
    complex_number z = {0, 0};
    complex_number multiplicative_inverse = get_multiplicative_inverse(z);

    TEST_ASSERT_FLOAT_IS_NAN(multiplicative_inverse.real_part);
    TEST_ASSERT_FLOAT_IS_NAN(multiplicative_inverse.imaginary_part);

    complex_number z1 = {0, 1};
    complex_number multiplicative_inverse1 = get_multiplicative_inverse(z1);

    TEST_ASSERT_EQUAL_FLOAT(0, multiplicative_inverse1.real_part);
    TEST_ASSERT_EQUAL_FLOAT(-1, multiplicative_inverse1.imaginary_part);

    complex_number z2 = {1, 0};
    complex_number multiplicative_inverse2 = get_multiplicative_inverse(z2);

    TEST_ASSERT_EQUAL_FLOAT(1, multiplicative_inverse2.real_part);
    TEST_ASSERT_EQUAL_FLOAT(0, multiplicative_inverse2.imaginary_part);

    complex_number z3 = {-3, 8};
    complex_number multiplicative_inverse3 = get_multiplicative_inverse(z3);

    TEST_ASSERT_FLOAT_WITHIN(1e-5, -0.04109, multiplicative_inverse3.real_part);
    TEST_ASSERT_FLOAT_WITHIN(1e-5, -0.10958, multiplicative_inverse3.imaginary_part);

    complex_number z4 = {2, -3};
    complex_number multiplicative_inverse4 = get_multiplicative_inverse(z4);

    TEST_ASSERT_FLOAT_WITHIN(1e-5, 0.15385, multiplicative_inverse4.real_part);
    TEST_ASSERT_FLOAT_WITHIN(1e-5, 0.23077, multiplicative_inverse4.imaginary_part);
}

/*
 * TESTING FOR ADDITION OF COMPLEX NUMBERS:
 *  no particular cases
 *  checking addition with neutral element, with negative and positive numbers
 */
void test_add_standard_form(void) {
    complex_number z1 = {1, 2};
    complex_number z2 = {3, 4};
    complex_number add_result = add_standard_form(z1, z2);

    TEST_ASSERT_EQUAL_FLOAT(4, add_result.real_part);
    TEST_ASSERT_EQUAL_FLOAT(6, add_result.imaginary_part);

    complex_number z3 = {1, 2};
    complex_number z4 = {3, -4};
    complex_number add_result1 = add_standard_form(z3, z4);

    TEST_ASSERT_EQUAL_FLOAT(4, add_result1.real_part);
    TEST_ASSERT_EQUAL_FLOAT(-2, add_result1.imaginary_part);

    complex_number z5 = {1, 2};
    complex_number z6 = {0, 0};
    complex_number add_result2 = add_standard_form(z5, z6);

    TEST_ASSERT_EQUAL_FLOAT(1, add_result2.real_part);
    TEST_ASSERT_EQUAL_FLOAT(2, add_result2.imaginary_part);

    complex_number z7 = {0, 0};
    complex_number z8 = {0, 0};
    complex_number add_result3 = add_standard_form(z7, z8);

    TEST_ASSERT_EQUAL_FLOAT(0, add_result3.real_part);
    TEST_ASSERT_EQUAL_FLOAT(0, add_result3.imaginary_part);
}

/*
 * TESTING FOR SUBTRACTION OF COMPLEX NUMBERS:
 *  no particular cases
 *  checking subtraction with neutral element, with negative and positive numbers
 */
void test_subtract_standard_form(void) {
    complex_number z1 = {1, 2};
    complex_number z2 = {3, 4};
    complex_number subtract_result = subtract_standard_form(z1, z2);

    TEST_ASSERT_EQUAL_FLOAT(-2, subtract_result.real_part);
    TEST_ASSERT_EQUAL_FLOAT(-2, subtract_result.imaginary_part);

    complex_number z3 = {1, 2};
    complex_number z4 = {3, -4};
    complex_number subtract_result1 = subtract_standard_form(z3, z4);

    TEST_ASSERT_EQUAL_FLOAT(-2, subtract_result1.real_part);
    TEST_ASSERT_EQUAL_FLOAT(6, subtract_result1.imaginary_part);

    complex_number z5 = {1, 2};
    complex_number z6 = {0, 0};
    complex_number subtract_result2 = subtract_standard_form(z5, z6);

    TEST_ASSERT_EQUAL_FLOAT(1, subtract_result2.real_part);
    TEST_ASSERT_EQUAL_FLOAT(2, subtract_result2.imaginary_part);

    complex_number z7 = {0, 0};
    complex_number z8 = {0, 0};
    complex_number subtract_result3 = subtract_standard_form(z7, z8);

    TEST_ASSERT_EQUAL_FLOAT(0, subtract_result3.real_part);
    TEST_ASSERT_EQUAL_FLOAT(0, subtract_result3.imaginary_part);
}

/*
 * TESTING FOR MULTIPLICATION OF COMPLEX NUMBERS:
 *  no particular cases
 *  checking multiplication with neutral element, with negative and positive numbers
 */
void test_multiply_standard_form(void) {
    complex_number z1 = {1, 2};
    complex_number z2 = {3, 4};
    complex_number multiply_result = multiply_standard_form(z1, z2);

    TEST_ASSERT_EQUAL_FLOAT(-5, multiply_result.real_part);
    TEST_ASSERT_EQUAL_FLOAT(10, multiply_result.imaginary_part);

    complex_number z3 = {1, 2};
    complex_number z4 = {3, -4};
    complex_number multiply_result1 = multiply_standard_form(z3, z4);

    TEST_ASSERT_EQUAL_FLOAT(11, multiply_result1.real_part);
    TEST_ASSERT_EQUAL_FLOAT(2, multiply_result1.imaginary_part);

    complex_number z5 = {1, 2};
    complex_number z6 = {0, 0};
    complex_number multiply_result2 = multiply_standard_form(z5, z6);

    TEST_ASSERT_EQUAL_FLOAT(0, multiply_result2.real_part);
    TEST_ASSERT_EQUAL_FLOAT(0, multiply_result2.imaginary_part);

    complex_number z7 = {0, 0};
    complex_number z8 = {0, 0};
    complex_number multiply_result3 = multiply_standard_form(z7, z8);

    TEST_ASSERT_EQUAL_FLOAT(0, multiply_result3.real_part);
    TEST_ASSERT_EQUAL_FLOAT(0, multiply_result3.imaginary_part);

    // neutral element
    complex_number z9 = {5, 6};
    complex_number z10 = {1, 0};
    complex_number multiply_result4 = multiply_standard_form(z9, z10);

    TEST_ASSERT_EQUAL_FLOAT(5, multiply_result4.real_part);
    TEST_ASSERT_EQUAL_FLOAT(6, multiply_result4.imaginary_part);
}

/*
 * TESTING FOR DIVISION OF COMPLEX NUMBERS:
 *  particular case is when the denominator is (0, 0)
 *  in this case the return value should be NaN.
 * checking division with neutral element and generic numbers
 */
void test_divide_standard_form(void) {
    complex_number z1 = {1, 2};
    complex_number z2 = {3, 4};
    complex_number divide_result = divide_standard_form(z1, z2);

    TEST_ASSERT_FLOAT_WITHIN(1e-5, 0.44, divide_result.real_part);
    TEST_ASSERT_FLOAT_WITHIN(1e-5, 0.08, divide_result.imaginary_part);

    complex_number z3 = {1, 2};
    complex_number z4 = {3, -4};
    complex_number divide_result1 = divide_standard_form(z3, z4);

    TEST_ASSERT_FLOAT_WITHIN(1e-5, -0.2, divide_result1.real_part);
    TEST_ASSERT_FLOAT_WITHIN(1e-5, 0.4, divide_result1.imaginary_part);

    complex_number z5 = {1, 2};
    complex_number z6 = {0, 0};
    complex_number divide_result2 = divide_standard_form(z5, z6);

    TEST_ASSERT_FLOAT_IS_NAN(divide_result2.real_part);
    TEST_ASSERT_FLOAT_IS_NAN(divide_result2.imaginary_part);

    complex_number z7 = {0, 0};
    complex_number z8 = {0, 0};
    complex_number divide_result3 = divide_standard_form(z7, z8);

    TEST_ASSERT_FLOAT_IS_NAN(divide_result3.real_part);
    TEST_ASSERT_FLOAT_IS_NAN(divide_result3.imaginary_part);

    complex_number z9 = {5, 6};
    complex_number z10 = {5, 6};
    complex_number divide_result4 = divide_standard_form(z9, z10);

    TEST_ASSERT_EQUAL_FLOAT(1, divide_result4.real_part);
    TEST_ASSERT_EQUAL_FLOAT(0, divide_result4.imaginary_part);

    // neutral element
    
}

int main(void) {

   UNITY_BEGIN();

   RUN_TEST(test_get_conjucate);
   RUN_TEST(test_get_absolute_value);
   RUN_TEST(test_get_multiplicative_inverse);

   RUN_TEST(test_add_standard_form);
   RUN_TEST(test_subtract_standard_form);
   RUN_TEST(test_multiply_standard_form);
   RUN_TEST(test_divide_standard_form);

   return UNITY_END();
   
}
