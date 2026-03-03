#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <lib/std/types.h>
#include <lib/std/stdio.h>

struct registers {
    uint32_t ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
};

void isr_handler(struct registers regs);

#endif