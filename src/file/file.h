#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct File File;

// Open a file with mode string ("r", "w", "a", "rb", "wb", etc.)
// Returns NULL if failed.
File* file_open(const char* path, const char* mode);

// Close an opened file.
void file_close(File* file);

// Read up to `count` bytes into `buffer`. Returns number of bytes read.
unsigned int file_read(File* file, void* buffer, unsigned int count);

// Write `count` bytes from `buffer` to file. Returns number of bytes written.
unsigned int file_write(File* file, const void* buffer, unsigned int count);

// Move file position to `offset` relative to `whence`
// whence: 0 = start, 1 = current, 2 = end
// Returns 0 on success, non-zero on failure.
int file_seek(File* file, long offset, int whence);

// Returns current position in file or -1 on error.
long file_tell(File* file);

// Check if end-of-file has been reached. Returns non-zero if EOF.
int file_eof(File* file);

// Flush file buffers to disk.
int file_flush(File* file);

// Check if a file exists on disk. Returns 1 if yes, 0 if no.
int file_exists(const char* path);

#ifdef __cplusplus
}
#endif
