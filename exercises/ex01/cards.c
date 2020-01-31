/**
 * Author: Nathaniel Tan
 * This file is an implimentation of blackjack card counting.
 */
#include <stdio.h>
#include <stdlib.h>

/* Takes the current card value and increments or decrements count accordingly.
 *  val: the value of the current card
 *  count: the current card count
 */
void update_count(int *val, int *count) {
    if ((*val > 2) && (*val < 7)) {
        (*count) ++;
    } else if (*val == 10) {
        (*count) --;
    }
}

/* Prompts the user for input and puts the reply in the given buffer.

   User input is truncated to the first two characters.

   prompt: string prompt to display
   card_name: buffer where result is stored
*/
void get_card_name(char *prompt, char *card_name) {
    puts(prompt);
    scanf("%2s", card_name);
}

int main() {
    char card_name[3];
    int count = 0;
    do {
        int val = 0;
        get_card_name("Enter the card name: ", card_name);
        switch(card_name[0]) {
            case 'K':
            case 'Q':
            case 'J':
                val = 10;
                break;
            case 'A':
                val = 11;
                break;
            case 'X':
                continue;
            default:
                val= atoi(card_name);
                if((val < 1) || (val > 10)) {
                    puts("I don't understand that value!");
                    continue;
                }
        }
        update_count(&val, &count);
        printf("Current count: %i\n", count);
    } while (card_name[0] != 'X');
    return 0;
}
