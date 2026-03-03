#include "console.h"
#include <lib/std/stdio.h>
#include "../drivers/keyboard/handler.h"


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
                print("TINOS2 0.1 alpha 1\n");
                print("Build: 1\n");
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