/*  Code for Think OS.

Copyright 2016 Allen B. Downey
License: MIT License https://opensource.org/licenses/MIT
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

union FloatIntUnion {
    float f;
    uint32_t i;
} b;

/* Get the exponent part of a float.
*/
uint32_t get_exponent(float x) {
    b.f = x;
    uint32_t mask = 0xff;
    uint32_t expon = (b.i >> 23) & mask;
    return expon;
}

float make_float(uint32_t mant, uint8_t sign, uint16_t exponent) {
  b.i = mant;
  b.i = b.i | (sign << 31);
  b.i = b.i | (exponent << 23);
  return b.f;
}

/* Divide a float by a power of two.
*/
float div_by_pow_2(float x, int n)
{
  b.f = x;
  uint32_t mant_mask = 0x7fffff;
  uint32_t mant = b.i & mant_mask;
  uint8_t sign = b.i >> 31;
  uint32_t exp = get_exponent(x) - 1;
  return make_float(mant, sign, exp);
}

int main() {
    float y = div_by_pow_2(-4.82, 1);
    printf("%f\n", y);
}
