#include <string>
#include <cstring>
#include <algorithm>

#include "cobra.h"

namespace {
    inline std::string *to_str_ptr(void *handle) {
        return static_cast<std::string *>(handle);
    }
}

extern "C" {
COBRA_API std::string *str_new(const char *initial_value) {
    if (initial_value == nullptr) {
        return new std::string();
    }
    return new std::string(initial_value);
}

COBRA_API void str_delete(void *handle) {
    delete to_str_ptr(handle);
}

COBRA_API char *str_get_as_string(void *handle) {
    if (!handle) {
        char *empty = new char[1];
        empty[0] = '\0';
        return empty;
    }

    const std::string &source = *to_str_ptr(handle);
    char *dest = new char[source.length() + 1];

#if defined(_WIN32) || defined(_MSC_VER)
    strcpy_s(dest, source.length() + 1, source.c_str());
#else
    strcpy(dest, source.c_str());
#endif

    return dest;
}

COBRA_API void str_free_string(char *buffer) {
    delete[] buffer;
}

COBRA_API int str_length(void *handle) {
    if (!handle) {
        return 0;
    }
    return static_cast<int>(to_str_ptr(handle)->length());
}

COBRA_API std::string *str_clone(void *handle) {
    if (!handle) {
        return nullptr;
    }
    return new std::string(*to_str_ptr(handle));
}

COBRA_API bool str_equals_handle(void *handle1, void *handle2) {
    if (handle1 == handle2) {
        return true;
    }
    if (!handle1 || !handle2) {
        return false;
    }
    return *to_str_ptr(handle1) == *to_str_ptr(handle2);
}

COBRA_API std::string *str_concat_handle(void *handle1, void *handle2) {
    if (!handle1) return str_clone(handle2);
    if (!handle2) return str_clone(handle1);

    return new std::string(*to_str_ptr(handle1) + *to_str_ptr(handle2));
}
}
