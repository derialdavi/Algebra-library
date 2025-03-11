#include "../include/linear-algebra.h"

complex_number_polar_form from_standard_to_polar(complex_number z) {
   complex_number_polar_form polarized_form;
   polarized_form.absolute_value = get_absolute_value(z);

   // I chose to use the range [0, 2\pi) so the argument value is
   if (z.real_part == 0 && z.imaginary_part > 0) {
       polarized_form.argument = 90.0;
   
   } else if (z.real_part == 0 && z.imaginary_part < 0) {
       polarized_form.argument = (3 / 2) * 180;
   
   } else if (z.real_part == 0 && z.imaginary_part == 0) {
       // Indefinite
   
   } else if (z.real_part > 0 && z.imaginary_part >= 0) {
       polarized_form.argument = atan(z.imaginary_part / z.real_part);

   } else if (z.real_part > 0 && z.imaginary_part < 0) {
       polarized_form.argument = atan(z.imaginary_part / z.real_part) + 360;

   } else if (z.real_part < 0) {
       polarized_form.argument = atan(z.imaginary_part / z.real_part) + 180;
   }

   return polarized_form;
}

double format_argument(double argument) {
   while (argument >= 360) {
      argument -= 360;
   }

   return argument;
}

complex_number_polar_form get_power(complex_number_polar_form z, unsigned int n) {
   // z = r*e^{i\theta} => z^n = r^n * e^{i*n*\theta} | n \in R
   complex_number_polar_form power;

   power.absolute_value = pow(z.absolute_value, 2);
   power.argument = z.argument * 2;
   power.argument = format_argument(power.argument);

   return power;
}

complex_number_polar_form* get_roots(complex_number_polar_form z, unsigned int n) {
   complex_number_polar_form* roots;
   roots = (complex_number_polar_form*) malloc(sizeof(complex_number_polar_form) * n);

   size_t m = 0;
   while (m < n) {
      complex_number_polar_form root;
      root.absolute_value = pow(z.absolute_value, 1/n);
      root.argument = (z.argument / n) + (2 * 180 * m) / n;
      root.argument = format_argument(root.argument);

      roots[m] = root;
      m += 1;
   }

   return roots;
}

complex_number_polar_form add_polar_form(complex_number_polar_form z1, complex_number_polar_form z2) {
   complex_number_polar_form add_result;
   
    complex_number z1_standardized = from_polar_to_standard(z1);
    complex_number z2_standardized = from_polar_to_standard(z2);
    complex_number add_standardized = add_standard_form(z1_standardized, z2_standardized);
    add_result = from_standard_to_polar(add_standardized);

   return add_result;
}

complex_number_polar_form subtract_polar_form(complex_number_polar_form z1, complex_number_polar_form z2) {
   complex_number_polar_form subtract_result;
   
    complex_number z1_standardized = from_polar_to_standard(z1);
    complex_number z2_standardized = from_polar_to_standard(z2);
    complex_number subtract_standardized = subtract_standard_form(z1_standardized, z2_standardized);
    subtract_result = from_standard_to_polar(subtract_standardized);

   return subtract_result;
}

complex_number_polar_form multiply_polar_form(complex_number_polar_form z1, complex_number_polar_form z2) {
   complex_number_polar_form multiply_result;
   
    multiply_result.absolute_value = z1.absolute_value * z2.absolute_value;
    multiply_result.argument = z1.argument + z2.argument;
    multiply_result.argument = format_argument(multiply_result.argument);

   return multiply_result;
}

complex_number_polar_form divide_polar_form(complex_number_polar_form z1, complex_number_polar_form z2) {
   complex_number_polar_form divide_result;
   
    divide_result.absolute_value = z1.absolute_value / z2.absolute_value;
    divide_result.argument = z1.argument - z2.argument;
    divide_result.argument = format_argument(divide_result.argument);

   return divide_result;
}