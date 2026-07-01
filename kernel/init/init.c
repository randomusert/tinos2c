#include "init.h"
#include "../lib/crash/crash.h"
#include "../console/console.h"
#include "../lib/pic/pic.h"
#include "../lib/std/string.h"
#include "../lib/idt/idt.h"
#include "../lib/gdt/gdt.h"
#include "../drivers/keyboard/handler.h"

void sysInit(void) {
    print("System Init starting...\n");

    print("Initializing interrupts\n");

    init_gdt();
    init_idt();

    print("Interrupts initialized\n");

    print("Remapping the PIC\n");

    pic_remap(0x20, 0x28); // Remap PIC:

    print("PIC remapped\n");

    print("Enabling interrupts\n");

    asm volatile("sti"); // Enable interrupts after PIC remapping

    print("Enabled interrupts\n");

    print("Loading console\n");

    clear_screen();

    console();

}

void tryOrInstall(void) {
    char buffer[128];
    int pos = 0;

    
    
    print("Do you want to try or install the OS?\n");
    print("Please type 'try' or 'install' to continue\n");

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

            if (strcmp(buffer, "install") == 0) {
                unimplemented("Install OS");
            } else if (strcmp(buffer, "try") == 0) {
                sysInit();
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


