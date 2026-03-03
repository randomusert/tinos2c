[BITS 32]
[extern _main]
; Jos gdt_ptr on C-koodissa:
[extern gdt_ptr] 

section .text.prologue

global _start
global stack_top  ; <--- Lisää tämä

_start:
    cli
    
    ; GDT lataus tässä välissä (kuten aiemmin mainittu)
    ; lgdt [gdt_ptr]
    ; jmp 0x08:.reload
    ; .reload:
    ; ... segmenttien päivitys ...

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
    resb 8192      ; 8 KB pinoa
stack_top:         ; <--- Varmista että tämä on resb:n JÄLKEEN
