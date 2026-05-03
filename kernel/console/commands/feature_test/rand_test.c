#include "rand_test.h"

void rand_test() {
    print("Random numbers:\n");

    for (int i = 0; i < 10; i++) {
        uint32_t r = rand_range(1,10000);

        // crude number printing
        char c = '0' + (r % 10);
        putchar(c);
        putchar('\n');
    }
}