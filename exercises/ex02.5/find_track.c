/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[])
{
    int status;

    int errorCodeSize;
    char *error_buff;

    for(int i=0; i < NUM_TRACKS; i++) {
        regex_t reg;

        // Compiles regex pattern, exits if fails to compile
        if(regcomp(&reg, pattern, REG_EXTENDED|REG_NOSUB)){
            printf("Pattern failed to compile");
            exit(1);
        }

        status = regexec(&reg, tracks[i], (size_t) 0, NULL, 0);


        if(status == 0){
            printf("Track %i: '%s'\n", i, tracks[i]);
        } 
        else if(status == REG_NOMATCH){
            
        }
        else {
            // Checks size of error code and then mallocs that amount of bytes
            errorCodeSize = regerror(status, &reg, (char *)NULL, (size_t)0);
            error_buff = malloc(errorCodeSize);

            printf("error_buff size:%d", errorCodeSize);

            regerror(status, &reg, error_buff, errorCodeSize);

            printf("%s\n", error_buff);
            exit(1);
        }
        regfree(&reg);
    }
   

}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
