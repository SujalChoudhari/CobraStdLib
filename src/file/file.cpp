#include "file.h"
#include <cstdio>
#include <cstdlib>

struct File {
    FILE* handle;
};

File* file_open(const char* path, const char* mode) {
    if (!path || !mode) return NULL;
    FILE* f = fopen(path, mode);
    if (!f) return NULL;
    File* file = (File*)malloc(sizeof(File));
    if (!file) {
        fclose(f);
        return NULL;
    }
    file->handle = f;
    return file;
}

void file_close(File* file) {
    if (!file) return;
    if (file->handle) fclose(file->handle);
    free(file);
}

unsigned int file_read(File* file, void* buffer, unsigned int count) {
    if (!file || !file->handle || !buffer || count == 0) return 0;
    return (unsigned int)fread(buffer, 1, count, file->handle);
}

unsigned int file_write(File* file, const void* buffer, unsigned int count) {
    if (!file || !file->handle || !buffer || count == 0) return 0;
    return (unsigned int)fwrite(buffer, 1, count, file->handle);
}

int file_seek(File* file, long offset, int whence) {
    if (!file || !file->handle) return -1;
    return fseek(file->handle, offset, whence);
}

long file_tell(File* file) {
    if (!file || !file->handle) return -1;
    return ftell(file->handle);
}

int file_eof(File* file) {
    if (!file || !file->handle) return 1;
    return feof(file->handle);
}

int file_flush(File* file) {
    if (!file || !file->handle) return -1;
    return fflush(file->handle);
}

int file_exists(const char* path) {
    if (!path) return 0;
    FILE* f = fopen(path, "r");
    if (f) {
        fclose(f);
        return 1;
    }
    return 0;
}
