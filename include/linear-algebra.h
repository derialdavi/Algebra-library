#ifndef LINEAR_ALGEBRA
#define LINEAR_ALGEBRA

#include <math.h>
#include <stdlib.h>

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
} Complex_number;

typedef struct {
   double absolute_value;
   double argument;
} Complex_number_polar_form;



Complex_number get_conjucate(Complex_number);
double get_absolute_value(Complex_number);
Complex_number get_multiplicative_inverse(Complex_number);
Complex_number from_polar_to_standard(Complex_number_polar_form);

Complex_number add(Complex_number, Complex_number);
Complex_number subtract(Complex_number, Complex_number); // still to implement
Complex_number multiply(Complex_number, Complex_number); // still to implement
Complex_number divide(Complex_number, Complex_number); // still to implement


double format_argument(double);
Complex_number_polar_form get_power(Complex_number_polar_form, unsigned int);
Complex_number_polar_form* get_roots(Complex_number_polar_form, unsigned int);
Complex_number_polar_form from_standard_to_polar(Complex_number);

Complex_number_polar_form multiply(Complex_number_polar_form, Complex_number_polar_form); // still to implement

#endif
