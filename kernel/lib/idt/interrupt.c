#include "interrupt.h"
#include <lib/pic/pic.h>
#include <console/console.h>


void isr_handler(struct registers regs) {
    outb(0x20, 0x20);
}
