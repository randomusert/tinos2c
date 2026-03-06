#include "number_guess.h"
#include <drivers/keyboard/handler.h>
#include <lib/std/stdio.h>

void game_number_guess(void) {
    print("Guess a number between 1 and 100:\n");
    

    int num = 61; // must be generated randomly later, but we don't have a random generator yet

    char buffer[128];
    int pos = 0;
    
    while (1)
    {
        char input = read_char();
        if (!input) continue;


        if (input == '\b') {
            if (pos > 0) {
                pos--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
        } else if (input == '\n') {
            buffer[pos] = '\0';
            print("\n");

            if (input > num)
            {
                print("Too high! Try again:\n");
            } else if (input < num)
            {
                print("Too low! Try again:\n");
            } else {
                print("Congratulations! You guessed the number!\n");
                break;
            }
            
            
            pos = 0;
        } else if (pos < sizeof(buffer) - 1) {
            buffer[pos++] = input;
            putchar(input);
        }

    }
    

    
}