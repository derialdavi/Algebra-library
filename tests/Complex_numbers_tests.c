#include <stdio.h>
#include <assert.h>

#include "../include/linear-algebra.h"

int main(void) {

   Complex_number z1;
   z1.real_part = 1;
   z1.imaginary_part = 0;

   Complex_number z2;
   z2.real_part = 0;
   z2.imaginary_part = 1;

   Complex_number z3 = add(z1, z2);

   assert(z3.real_part == 1 && z3.imaginary_part == 1);

   return 0;
}
