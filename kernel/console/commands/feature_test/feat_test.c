#include "feat_test.h"
#include <console/commands/feature_test/rand_test.h>
#include <console/commands/feature_test/crash_test.h>

void feat_test() {
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

            if (strcmp(buffer, "help") == 0) {
                print("Welcome to feature test!\n");
                print("This command is used to test various features of the kernel with the C library implementation.\n");
                print("Available tests:\n");
                print(" - rand: Test the random number generator\n");
                print(" - crash: Test the crash handling system\n");
                print(" - exit: Exit the feature test console\n");
            } else if (strcmp(buffer, "rand") == 0) {
                rand_test();
            } else if (strcmp(buffer, "crash") == 0) {
                crash_test_cmd();
            } else if (strcmp(buffer, "exit") == 0) {
                break;
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