#include "idt.h"

void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags) {
    idt[num].base_low  = base & 0xFFFF;
    idt[num].base_high = (base >> 16) & 0xFFFF;
    idt[num].sel       = sel;
    idt[num].always0   = 0;
    idt[num].flags     = flags; 
}

void init_idt() {
    idt_p.limit = (sizeof(idt_entry_t) * 256) - 1;
    idt_p.base  = (uint32_t)&idt;

    memset(&idt, 0, sizeof(idt_entry_t) * 256);

    idt_flush((uint32_t)&idt_p);
}
