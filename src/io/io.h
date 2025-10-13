#pragma once
#include "cobra.h"
#ifdef __cplusplus
extern "C" {
#endif

    COBRA_API char* read_line(void);
    COBRA_API char read_char(void);
    COBRA_API int read_int(void);
    COBRA_API double read_float(void);
    COBRA_API void print_line(const char* str);
    COBRA_API void print_char(char c);
    COBRA_API void flush_stdout(void);

#ifdef __cplusplus
}
#endif
