#ifndef PMM_H
#define PMM_H

// Just get some info from the mboot stuff in kernel/lib/multiboot.h
typedef struct multiboot_mem_map {
    unsigned int size;
    unsigned int base_addr_low, base_addr_high;
    unsigned int length_low, length_high;
} multiboot_mem_map_t;

typedef multiboot_mem_map_t mmap_entry_t;


// Init Physical Memory Manager
void pmm_init(mmap_entry_t *map);

// allocate a memory page
void* pmm_alloc_page();

// free a memory page
void pmm_free_page(void *);

#endif