#include "random.h"
#include <lib/std/stdio.h>



static uint32_t rng_state = 1;

void srand(uint32_t seed) {
    if (seed == 0) seed = 1;
    rng_state = seed;
}


uint32_t rand() {
    rng_state = rng_state * 1664525 + 1013904223;
    return rng_state;
}


uint32_t rand_range(uint32_t min, uint32_t max) {
    return rand() % (max - min) + min;
}

void srand_from_timer() {
    uint32_t seed = inb(0x40);
    seed |= inb(0x40) << 8;
    seed |= inb(0x40) << 16;
    seed |= inb(0x40) << 24;

    srand(seed);
}