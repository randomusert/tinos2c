#include "ver.h"
#include <lib/info.h>
#include <lib/build.h>
#include <lib/std/stdio.h>

void ver_cmd() {
    print("Tinos Version: ");
    print(TINOS_VERSION);
    print(" (");
    print(TINOS_RELEASE_CHANNEL);
    print(") \nBuild: ");
    print_int(TINOS_BUILD);
    print("\n");
}