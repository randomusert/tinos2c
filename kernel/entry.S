[BITS 32]
[extern _main]
[extern gdt_ptr] 

section .text.prologue

global _start
global stack_top

_start:
    cli
    
    mov esp, stack_top
    
    push eax
    push ebx
    call _main

hltLoop:
    hlt
    jmp hltLoop

section .bss
align 16

stack_bottom:
    resb 8192     
 
stack_top:         


gdt_ptr:
    dw (3 * 8) - 1   
    dd gdt_table     

gdt_table:
    dq 0
    dq 0x00cf9a000000ffff
    dq 0x00cf92000000ffff