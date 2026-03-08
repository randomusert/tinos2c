#ifndef RANDOM_H
#define RANDOM_H

#include <lib/std/types.h>

void srand(uint32_t seed);
uint32_t rand();
uint32_t rand_range(uint32_t min, uint32_t max);
void srand_from_timer();

#endif // RANDOM_H