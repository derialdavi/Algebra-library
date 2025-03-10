#include <stdio.h>
#include <assert.h>

#include "../include/linear-algebra.h"

int main(void) {

   // SUMS
   Complex_number z1 = {1, 0};
   Complex_number z2 = {0, 1};
   Complex_number z3 = add_standard_form(z1, z2);
   assert(z3.real_part == 1 && z3.imaginary_part == 1);

   // SUBS
   Complex_number z4 = subtract_standard_form(z1, z2);
   assert(z4.real_part == 1 && z4.imaginary_part == -1);

   // MULTS
   Complex_number z5 = multiply_standard_form(z1, z2);
   assert(z5.real_part == 0 && z5.imaginary_part == 1);

   // DIVS
   Complex_number z6 = {4, 3};
   Complex_number z7 = {5, -2};
   Complex_number z8 = divide_standard_form(z6, z7);
   // Since fp are not precise, I can't check exact value so I check for very similar value
   assert(z8.real_part - 0.482759 < 1e-6 && z8.imaginary_part - 0.793103 < 1e-6);

   return 0;
}
