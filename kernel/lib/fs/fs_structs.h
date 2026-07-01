#ifndef FS_STRUCTS_H
#define FS_STRUCTS_H

#include <lib/std/types.h>

typedef struct
{
    uint32_t first_cluster;
    uint32_t size;
    uint32_t position;
} FILE;

typedef struct
{
  char name[32];

  uint32_t start_sector;

  uint32_t size;

  uint8_t used;

} FileEntry;


#endif