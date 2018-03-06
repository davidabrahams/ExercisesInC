## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/davidabrahams/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

128 = 1000 0000 in binary

If extended to 16-bit w/ sign extension, we get:

1111 1111 1000 0000

which is -128 in decimal.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

(Assuming number stored with 8 bits)

(12 XOR 255) - 1

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

To make multiplication easier? (ie, its not ambiguous what to with exponent when you multiple two numbers. Just add them?)

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

Want to store 0.625 as mantissa, bc 13 is 8 * 1.625. The mantisa is 0.5 + 0.125, so 101 with a bunch of 0s afterward. Exponent is 3 + 127 bias = 130. sign bit is 1:

11000001010100000000000000000000.

As an int, this number is 3243245568

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.


Done! It's in `convert_string.c` in this directory.
