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


global idt_flush
idt_flush:
    mov eax, [esp+4]  ; Hae idt_p osoite pinosta
    lidt [eax]        ; Lataa IDT
    ret
