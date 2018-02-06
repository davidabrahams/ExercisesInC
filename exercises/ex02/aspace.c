/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    // here's a super high quality photo of my memory drawing:
    // https://photos.app.goo.gl/qn8UL3B4bljyLCJy1
    int var2 = 5;
    void *p = malloc(128);
    void *w = malloc(128);
    void *seven1 = malloc(7);
    void *seven2 = malloc(7);
    char *s = "Literal string";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("Address of p is %p\n", p);
    printf ("Address of w is %p\n", w); // this address is higher that p's
    printf ("Address of seven1 is %p\n", seven1);
    printf ("Address of seven2 is %p\n", seven2); // hm. 32 bytes apart. I tried
                                                  // this with different values.
    printf ("Address of s is %p\n", s);

    return 0;
}
