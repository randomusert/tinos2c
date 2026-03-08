#include "number_guess.h"
#include <drivers/keyboard/handler.h>
#include <lib/std/stdio.h>
#include <lib/std/random.h>

int atoi(const char* str) {
    int result = 0;
    int i = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result;
}

void game_number_guess(void) {

    print("Guess a number between 1 and 100:\n");

    int num = rand_range(1, 100); // TODO: replace with RNG later

    char buffer[16];
    int pos = 0;

    while (1) {

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

            int guess = atoi(buffer);

            if (guess == num) {
                print("Congratulations! You guessed the number!\n");
                break;
            } 
            else if (guess > num) {
                print("Too high! Try again:\n");
            } 
            else {
                print("Too low! Try again:\n");
            }

            pos = 0;

        } else if (pos < sizeof(buffer) - 1) {

            if (input >= '0' && input <= '9') { // only allow digits
                buffer[pos++] = input;
                putchar(input);
            }

        }
    }
}