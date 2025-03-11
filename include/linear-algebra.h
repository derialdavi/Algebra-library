#ifndef LINEAR_ALGEBRA
#define LINEAR_ALGEBRA

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/*
   ____                      _                                   _                   
  / ___|___  _ __ ___  _ __ | | _____  __  _ __  _   _ _ __ ___ | |__   ___ _ __ ___ 
 | |   / _ \| '_ ` _ \| '_ \| |/ _ \ \/ / | '_ \| | | | '_ ` _ \| '_ \ / _ \ '__/ __|
 | |__| (_) | | | | | | |_) | |  __/>  <  | | | | |_| | | | | | | |_) |  __/ |  \__ \
  \____\___/|_| |_| |_| .__/|_|\___/_/\_\ |_| |_|\__,_|_| |_| |_|_.__/ \___|_|  |___/
                      |_|                                                            
*/

typedef struct {
   double real_part;
   double imaginary_part;
} complex_number;

typedef struct {
   double absolute_value;
   double argument;
} complex_number_polar_form;



complex_number get_conjucate(complex_number);
double get_absolute_value(complex_number);
complex_number get_multiplicative_inverse(complex_number);
complex_number from_polar_to_standard(complex_number_polar_form);

complex_number add_standard_form(complex_number, complex_number);
complex_number subtract_standard_form(complex_number, complex_number);
complex_number multiply_standard_form(complex_number, complex_number);
complex_number divide_standard_form(complex_number, complex_number);


double format_argument(double);
complex_number_polar_form get_power(complex_number_polar_form, unsigned int);
complex_number_polar_form* get_roots(complex_number_polar_form, unsigned int);
complex_number_polar_form from_standard_to_polar(complex_number);

complex_number_polar_form add_polar_form(complex_number_polar_form, complex_number_polar_form);
complex_number_polar_form subtract_polar_form(complex_number_polar_form, complex_number_polar_form);
complex_number_polar_form multiply_polar_form(complex_number_polar_form, complex_number_polar_form);
complex_number_polar_form divide_polar_form(complex_number_polar_form, complex_number_polar_form);

#endif
