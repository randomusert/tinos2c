#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <lib/std/types.h>
// keyboard function prototypes
void  kbd_push(uint8_t scanode);
uint8_t kbd_pop();
#endif