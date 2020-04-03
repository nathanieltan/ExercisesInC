/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

/**
 * Experiment results:
 * The code seg faults because the array in foo is a local variable and
 * when the frame for foo is done array no longer exists so the pointer that
 * foo returns points to garbage data at the same address array used to be at
 *
 * commenting out the print statements gets rid of the prints and doesn't change
 * anything else
 */
int *foo() {
    int i;
    int array[SIZE];

    /* printf("%p\n", array); */

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    /* printf("%p\n", array); */

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
