#include <stdio.h>

// printf just x experiment:
// when not optimized, an int 5 is stored in memory then printed.
// when optimized, the int 5 is directly printed and not separately stored
//
// y = x + 1 experiment:
// when not optimized, an int 5 is stored in memory,
// then 1 is added to the value and then the value is passed to be printed
// when optimized, the value 6 is put into memory and printed directly
int main() {
    int x = 5;
    int y = x + 1;
    printf("y is equal to %i", y);
    return 0;
}
