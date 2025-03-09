#include "../include/linear-algebra.h"

Complex_number_polar_form from_standard_to_polar(Complex_number z) {
   Complex_number_polar_form polarized_form;
   polarized_form.absolute_value = abs(get_absolute_value(z));

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

Complex_number_polar_form get_power(Complex_number_polar_form z, unsigned int n) {
   // z = r*e^{i\theta} => z^n = r^n * e^{i*n*\theta} | n \in R
   Complex_number_polar_form power;

   power.absolute_value = pow(z.absolute_value, 2);
   power.argument = z.argument * 2;
   power.argument = format_argument(power.argument);

   return power;
}

Complex_number_polar_form* get_roots(Complex_number_polar_form z, unsigned int n) {
   Complex_number_polar_form* roots;
   roots = (Complex_number_polar_form*) malloc(sizeof(Complex_number_polar_form) * n);

   size_t m = 0;
   while (m < n) {
      Complex_number_polar_form root;
      root.absolute_value = pow(z.absolute_value, 1/n);
      root.argument = (z.argument / n) + (2 * 180 * m) / n;
      root.argument = format_argument(root.argument);

      roots[m] = root;
      m += 1;
   }

   return roots;
}
