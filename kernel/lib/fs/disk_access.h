#ifndef DISK_ACCESS_H
#define DISK_ACCESS_H


#include <std/types.h>

int disk_read(uint32_t lba, uint32_t count, void *buffer);

int disk_write(uint32_t lba, uint32_t count, const void *buffer);

#endif