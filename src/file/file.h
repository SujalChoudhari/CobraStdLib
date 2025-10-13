#pragma once
#include "cobra.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct File File;

COBRA_API File* file_open(const char* path, const char* mode);
COBRA_API void file_close(File* file);
COBRA_API unsigned int file_read(File* file, void* buffer, unsigned int count);
COBRA_API unsigned int file_write(File* file, const void* buffer, unsigned int count);
COBRA_API int file_seek(File* file, long offset, int whence);
COBRA_API long file_tell(File* file);
COBRA_API int file_eof(File* file);
COBRA_API int file_flush(File* file);
COBRA_API int file_exists(const char* path);

#ifdef __cplusplus
}
#endif
