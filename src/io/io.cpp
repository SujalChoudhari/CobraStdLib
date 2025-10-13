#include "io.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Helper: initial buffer size for read_line
#define INITIAL_BUFFER_SIZE 128

char* read_line(void) {
    size_t capacity = INITIAL_BUFFER_SIZE;
    size_t length = 0;
    char* buffer = (char*)malloc(capacity);
    if (!buffer) return NULL;

    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        buffer[length++] = (char)c;
        if (length >= capacity) {
            capacity *= 2;
            char* temp = (char*)realloc(buffer, capacity);
            if (!temp) {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }
    }
    // If EOF and no data read, free and return NULL
    if (c == EOF && length == 0) {
        free(buffer);
        return NULL;
    }
    buffer[length] = '\0';
    return buffer;
}

char read_char(void) {
    int c = getchar();
    if (c == EOF) return '\0';
    return (char)c;
}

int read_int(void) {
    int value = 0;
    int result = scanf("%d", &value);
    if (result != 1) {
        // Clear invalid input
        int c;
        while ((c = getchar()) != EOF && c != '\n');
        return 0; // Or use a better error scheme
    }
    return value;
}

double read_float(void) {
    double value = 0.0;
    int result = scanf("%lf", &value);
    if (result != 1) {
        int c;
        while ((c = getchar()) != EOF && c != '\n');
        return 0.0;
    }
    return value;
}

void print_line(const char* str) {
    if (!str) return;
    fputs(str, stdout);
    fputc('\n', stdout);
}

void print_char(char c) {
    fputc(c, stdout);
}

void flush_stdout(void) {
    fflush(stdout);
}
