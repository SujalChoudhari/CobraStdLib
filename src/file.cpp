#include <cstdio>
#include <cstdlib>

#include "cobra.h"

extern "C" {
COBRA_API FILE *file_open(const char *path, const char *mode) {
    if (!path || !mode) return nullptr;
    return fopen(path, mode);
}

COBRA_API void file_close(FILE *file) {
    if (!file) return;
    fclose(file);
}

COBRA_API int file_seek(FILE *file, long offset, int whence) {
    if (!file) return -1; // Return error code on invalid handle
    return fseek(file, offset, whence);
}

COBRA_API long file_tell(FILE *file) {
    if (!file) return -1;
    return ftell(file);
}

COBRA_API bool file_eof(FILE *file) {
    if (!file) return true; // Treat invalid handle as EOF
    return feof(file) != 0;
}

COBRA_API int file_flush(FILE *file) {
    if (!file) return -1;
    return fflush(file);
}

COBRA_API bool file_exists(const char *path) {
    if (!path) return false;
    FILE *f = fopen(path, "r");
    if (f) {
        fclose(f);
        return true;
    }
    return false;
}
}
