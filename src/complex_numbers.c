#include "../include/linear-algebra.h"

complex_number get_conjucate(complex_number z) {
   // z = a + bi => conjucate(z) = a - bi
   complex_number conjucate;
   conjucate.real_part = z.real_part;
   conjucate.imaginary_part = z.imaginary_part * (-1);

   return conjucate;
}

double get_absolute_value(complex_number z) {
   // z = a + bi => abs(z) = sqrt{a^2 + b^2}
   return sqrt(pow(z.real_part, 2) + pow(z.imaginary_part, 2));
}

complex_number get_multiplicative_inverse(complex_number z) {
   // z = a + bi => z^{-1} = conjucate(z) / (abs(z))^2
   // OR (faster)
   // z = a + bi => z^{-1} = 1 / z
   complex_number multiplicative_inverse;
   multiplicative_inverse = divide_standard_form((complex_number){1, 0}, z);

   // I have to check for division by zero

   return multiplicative_inverse;
}

complex_number add_standard_form(complex_number z1, complex_number z2) {
   complex_number add_result;
   add_result.real_part = z1.real_part + z2.real_part;
   add_result.imaginary_part = z1.imaginary_part + z2.imaginary_part;

   return add_result;
}

complex_number subtract_standard_form(complex_number z1, complex_number z2) {
   complex_number subtract_result;
   subtract_result.real_part = z1.real_part - z2.real_part;
   subtract_result.imaginary_part = z1.imaginary_part - z2.imaginary_part;

   return subtract_result;
}

complex_number multiply_standard_form(complex_number z1, complex_number z2) {
   complex_number multiply_result;

   double first = z1.real_part * z2.real_part;
   double second = z1.real_part * z2.imaginary_part;
   double third = z1.imaginary_part * z2.real_part;
   double fourth = (z1.imaginary_part * z2.imaginary_part) * (-1);

   multiply_result.real_part = first + fourth;
   multiply_result.imaginary_part = second + third;

   return multiply_result;
}

complex_number divide_standard_form(complex_number z1, complex_number z2) {
   complex_number divide_result;

   complex_number conjucate = get_conjucate(z2);
   complex_number numerator = multiply_standard_form(conjucate, z1);
   complex_number denominatore = multiply_standard_form(conjucate, z2);

   divide_result.real_part = numerator.real_part / denominatore.real_part;
   divide_result.imaginary_part = numerator.imaginary_part / denominatore.real_part;

   return divide_result;
}

complex_number from_polar_to_standard(complex_number_polar_form z) {
   complex_number standardized_form;

   standardized_form.real_part = z.absolute_value * cos(z.argument * (3.14159/180));
   standardized_form.real_part = round(standardized_form.real_part * 100.0) / 100.0; // round to 2 decimal places
   standardized_form.imaginary_part = z.absolute_value * sin(z.argument * (3.14159/180));
   standardized_form.imaginary_part = round(standardized_form.imaginary_part * 100.0) / 100.0; // round to 2 decimal places

   return standardized_form;
}