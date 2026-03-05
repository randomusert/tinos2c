#include <lib/multiboot.h>
#include <lib/std/stdio.h>
#include "console/console.h"
#include <lib/pic/pic.h>
#include <lib/std/string.h>
#include <lib/idt/idt.h>
#include <lib/gdt/gdt.h>

// Do not change or remove the multiboot header, as it is required for GRUB to load the kernel correctly.
// The multiboot header must be placed in the first 8KB of the kernel image, and it must be aligned to a 4-byte boundary.
__attribute__((section(".multiboot")))
struct multiboot_header_t mboot_header = {
    .magic = MULTIBOOT_MAGIC,
    .flags = MULTIBOOT_FLAGS,
    .checksum = -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)
};

void _main(struct multiboot_info_t *mboot_info, uint32_t mboot_magic) { 
    init_gdt();
    init_idt();
    pic_remap(0x20, 0x28); // Remap PIC:

    asm volatile("sti"); // Enable interrupts after PIC remapping

    console();

        
}