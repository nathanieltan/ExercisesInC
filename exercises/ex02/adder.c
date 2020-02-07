#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 8

void compute_sum (int numbers[BUFFER_SIZE]) {
    int sum = 0;

    for (int i = 0; i < BUFFER_SIZE; i++) {
        sum += numbers[i];
    }
    printf("Sum is %d", sum);

}

int main () {
    int numbers[BUFFER_SIZE];
    char input[8];
    int buffer_index = 0;

    for (int i = 0; i < BUFFER_SIZE; i++) {
        numbers[i] = 0;
    }

    puts("Enter numbers:");

    while (fgets(input, 8, stdin)) {
        if (buffer_index >= BUFFER_SIZE) {
            puts("Inputs exceed buffer size, exiting");
            break;
        }

        numbers[buffer_index] = atoi(input);

        if ((numbers[buffer_index] == 0 && input[0] != '0')) {
            puts("Input was not a number, exiting");
            break;
        }

        buffer_index ++;
    }

    compute_sum(numbers);
    return 0;
}
