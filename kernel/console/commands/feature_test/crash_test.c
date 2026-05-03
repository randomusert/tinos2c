#include "crash_test.h"
#include <lib/crash/crash.h>

void crash_test_cmd() {
    crash("This Crash was triggered by the crash_test_cmd function in crash_test.c. This is a test of the crash handling system.");
}