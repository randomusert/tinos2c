#ifndef STDIO_H
#define STDIO_H

#include <lib/std/types.h>

unsigned char inb(unsigned short port);
void outb(unsigned short port, unsigned char val);


void scroll_screen();
void putchar(char c);
void print(const char *str);
void update_cursor(int x, int y);
void clear_screen();


uint16_t vga_entry(char c, uint8_t color);



#endif