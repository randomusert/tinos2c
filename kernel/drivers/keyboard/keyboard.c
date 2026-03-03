#include <drivers/keyboard/keyboard.h>
#include <lib/std/stdio.h>


#define KBD_BUF_SIZE 256
static uint8_t kbd_buffer[KBD_BUF_SIZE];
static uint32_t kbd_head = 0;
static uint32_t kbd_tail = 0;

void kbd_push(uint8_t scancode) {
    uint32_t next = (kbd_head + 1) % KBD_BUF_SIZE;
    if (next != kbd_tail) {
        kbd_buffer[kbd_head] = scancode;
        kbd_head = next;
    }
}

uint8_t kbd_pop() {
    if (kbd_head == kbd_tail) return 0; 
    uint8_t scancode = kbd_buffer[kbd_tail];
    kbd_tail = (kbd_tail + 1) % KBD_BUF_SIZE;
    return scancode;
}
