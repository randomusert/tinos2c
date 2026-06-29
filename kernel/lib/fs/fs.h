#ifndef FS_H
#define FS_H

#include "fs_structs.h"
#include <lib/std/types.h>


int fs_init(void);

FILE *fs_open(const char *path);

size_t fs_read(FILE *file, void *buffer, size_t bytes);

void fs_close(FILE *file);

FILE *fs_create(const char *path);

size_t fs_write(FILE *file, const void *buffer, size_t bytes);

int fs_delete(const char *path);

#endif // FS_H