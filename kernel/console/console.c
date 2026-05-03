#include "console.h"
#include <lib/std/stdio.h>
#include "../drivers/keyboard/handler.h"
#include "commands/help.h"
#include <apps/games/number_guess.h>
#include "commands/feature_test/feat_test.h"
#include <lib/build.h>

void console() {
    char buffer[128];
    int pos = 0;

    print(">");

    while (1) {
        char c = read_char();
        if (!c) continue;

        if (c == '\b') {
            if (pos > 0) {
                pos--;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
        } else if (c == '\n') {
            buffer[pos] = '\0';
            print("\n");

            if (strcmp(buffer, "ver") == 0) {
                print("TINOS2 0.1 alpha 4\n");
                print("Build: " + TINOS_BUILD);
            } else if (strcmp(buffer, "help") == 0) {
                help_cmd();
            } else if (strcmp(buffer, "halt") == 0)
            {
                while (1) asm volatile ("hlt");
            } else if (strcmp(buffer, "clear") == 0)
            {
                clear_screen();
            }else if (strcmp(buffer, "guessnum") == 0)
            {
                game_number_guess();
            }else if (strcmp(buffer, "feattest") == 0)
            {
                feat_test();
            } else {
                print("Unknown command: ");
                print(buffer);
                print("\n");
            }

            print(">");
            pos = 0;
        } else if (pos < sizeof(buffer) - 1) {
            buffer[pos++] = c;
            putchar(c);
        }
    }
}