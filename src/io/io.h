#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Reads a full line from stdin, returns a dynamically allocated null-terminated string.
// Caller is responsible for freeing the returned pointer.
char* read_line(void);

// Reads a single character from stdin (blocking).
char read_char(void);

// Reads an integer from stdin. Returns 0 if input is invalid (optional: set error state).
int read_int(void);

// Reads a double-precision float from stdin. Returns 0.0 on invalid input.
double read_float(void);

// Prints a string followed by a newline to stdout.
void print_line(const char* str);

// Prints a single character to stdout.
void print_char(char c);

// Flushes stdout buffer to ensure all output is displayed immediately.
void flush_stdout(void);

#ifdef __cplusplus
}
#endif
