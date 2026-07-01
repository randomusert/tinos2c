#ifndef TFS_FILE_HEADERS_H
#define TFS_FILE_HEADERS_H

#include <std/types.h>


// REQUIRED FOR ALL TEXE EXECUTABLE BINARIES!!!
struct tfs_exec_header {
    uint32_t magic;   // "TEXE"
    uint32_t entry;
    uint32_t size;
};

#endif