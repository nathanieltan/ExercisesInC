#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 1024

/* Question 3:
 * I mostly referenced Head First C for handling arguments
 * I accidently left out incrementing argv and argc and
 * it took me a while to figure out what was wrong
 *
 * Question 4:
 * The professional implimentations have more robust argment handling
 * and error messages
 */
int main (int argc, char *argv[]) {

    char input[1024];

    char ch;
    int append = 0;

    while ((ch = getopt(argc, argv, "a") != EOF)) {
        switch(ch) {
            case 'a':
                append = 1;
                break;
            default:
                fprintf(stderr, "invalid option '%s' \n", optarg);
                break;
        }
    }

    argc -= optind;
    argv += optind;

    FILE *out_file;

    if (append) {
        out_file = fopen(argv[0], "a");
    }
    else {
        out_file = fopen(argv[0], "w");
    }

    while(fgets(input, BUFF_SIZE, stdin) != NULL) {
        fprintf(out_file, "%s", input);
        fprintf(stdout, "%s", input);
    }

    fclose(out_file);

    return 0;
}
