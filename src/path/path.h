#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Joins two paths with the appropriate separator.
// Returns a newly allocated string; caller must free.
char* path_join(const char* base, const char* addition);

// Returns absolute path of `path`. Returns newly allocated string or NULL on failure.
// Note: May resolve symbolic links (platform dependent).
char* path_absolute(const char* path);

// Returns directory part of the path (everything before last separator).
// Returns newly allocated string or "." if no directory component.
// Caller must free.
char* path_dirname(const char* path);

// Returns file name part of the path (everything after last separator).
// Returns newly allocated string; caller must free.
char* path_basename(const char* path);

// Returns file extension including the dot, or empty string if none.
// Returns newly allocated string; caller must free.
char* path_extension(const char* path);

// Returns 1 if path is absolute, 0 otherwise.
int path_is_absolute(const char* path);

// Normalizes the path by removing redundant ".", "..", and duplicate separators.
// Returns newly allocated string; caller must free.
char* path_normalize(const char* path);

#ifdef __cplusplus
}
#endif
