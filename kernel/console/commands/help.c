#include <lib/std/stdio.h>
#include "help.h"

ICommand help_command = {
    .name = "help",
    .execute = help_cmd
};

void help_cmd() {
    print("Available commands:\n");
    print("ver - Show OS version\n");
    print("help - Show this help message\n");
    print("halt - Halt the system\n");
}