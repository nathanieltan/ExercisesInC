/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void print_local() {
    int test = 4;

    printf ("Address of test is %p\n", &test);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(128);
    char *s = "Hello, World";

    void *x = malloc(26);
    void *y = malloc(26);

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
    printf ("q points to %p\n", q);

    print_local();

    printf ("x points to %p\n", x); // Difference between address of x and y is 0x30 which is 48 in decimal
    printf ("y points to %p\n", y);
    return 0;
}
