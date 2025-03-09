#include "../include/linear-algebra.h"

Complex_number get_conjucate(Complex_number z) {
   // z = a + bi => conjucate(z) = a - bi
   Complex_number conjucate;
   conjucate.real_part = z.real_part;
   conjucate.imaginary_part = z.imaginary_part * (-1);

   return conjucate;
}

double get_absolute_value(Complex_number z) {
   // z = a + bi => abs(z) = sqrt{a^2 + b^2}
   return sqrt(pow(z.real_part, 2) + pow(z.imaginary_part, 2));
}

Complex_number get_multiplicative_inverse(Complex_number z) {
   // z = a + bi => z^{-1} = conjucate(z) / (abs(z))^2
   Complex_number conjucate = get_conjucate(z);
   double absolute_value = get_absolute_value(z);

   Complex_number multiplicative_inverse;
   multiplicative_inverse.real_part = conjucate.real_part / pow(absolute_value, 2);
   multiplicative_inverse.imaginary_part = conjucate.imaginary_part / pow(absolute_value, 2);

   return multiplicative_inverse;
}

Complex_number from_polar_to_standard(Complex_number_polar_form z) {
   Complex_number standardized_form;

   standardized_form.real_part = z.absolute_value * cos(z.argument);
   standardized_form.imaginary_part = z.absolute_value * sin(z.argument);

   return standardized_form;
}

Complex_number add(Complex_number z1, Complex_number z2) {
   Complex_number add_result;
   add_result.real_part = z1.real_part + z2.real_part;
   add_result.imaginary_part = z1.imaginary_part + z2.imaginary_part;

   return add_result;
}
