#include "crash.h"
#include <lib/std/stdio.h>

void crash(const char* message) {
    
    print("Kernel Crash: ");
    print(message);
    print("\nSystem Halted.");

    while (1) {
        asm volatile ("hlt");
    }
}