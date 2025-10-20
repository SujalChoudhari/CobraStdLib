#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <stdexcept>

#include "cobra.h"

namespace {
    // Helper to safely cast the generic handle to a std::string pointer
    inline std::string *to_str_ptr(void *handle) {
        return static_cast<std::string *>(handle);
    }

    // Helper to safely get a reference, throwing if the handle is null
    inline const std::string &as_str(void *handle) {
        if (!handle) throw std::runtime_error("String handle is null.");
        return *to_str_ptr(handle);
    }
}

extern "C" {
// --- Memory Management ---

// (renamed from str_new)
COBRA_API std::string *str_create(const char *initial_value) {
    if (initial_value == nullptr) {
        return new std::string();
    }
    return new std::string(initial_value);
}

COBRA_API void str_delete(void *handle) {
    delete to_str_ptr(handle);
}

// --- String Data Access ---

COBRA_API char *str_get_as_string(void *handle) {
    if (!handle) {
        // Return an empty, null-terminated string for C#
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

// Required by Cobra FFI to free the string returned by str_get_as_string
COBRA_API void str_free_string(char *buffer) {
    delete[] buffer;
}

COBRA_API int str_length(void *handle) {
    return handle ? static_cast<int>(as_str(handle).length()) : 0;
}

COBRA_API bool str_is_empty(void *handle) {
    return handle ? as_str(handle).empty() : true;
}

COBRA_API char *str_at(void *handle, int index) {
    const std::string &s = as_str(handle);
    if (index < 0 || static_cast<size_t>(index) >= s.length()) {
        // Return empty string for out of bounds
        char *empty = new char[1];
        empty[0] = '\0';
        return empty;
    }
    // Return a single character as a null-terminated string
    char *single_char = new char[2];
    single_char[0] = s.at(index);
    single_char[1] = '\0';
    return single_char;
}

// --- Searching and Comparison ---

COBRA_API bool str_contains(void *handle, const char *sub) {
    if (!handle || !sub) return false;
    return as_str(handle).find(sub) != std::string::npos;
}

COBRA_API bool str_starts_with(void *handle, const char *prefix) {
    if (!handle || !prefix) return false;
    return as_str(handle).starts_with(prefix);
}

COBRA_API bool str_ends_with(void *handle, const char *suffix) {
    if (!handle || !suffix) return false;
    return as_str(handle).ends_with(suffix);
}

COBRA_API int str_find(void *handle, const char *sub, int start) {
    if (!handle || !sub) return -1;
    size_t pos = as_str(handle).find(sub, std::max(0, start));
    return (pos == std::string::npos) ? -1 : static_cast<int>(pos);
}

COBRA_API int str_rfind(void *handle, const char *sub, int start) {
    if (!handle || !sub) return -1;
    size_t pos = as_str(handle).rfind(sub, std::max(0, start));
    return (pos == std::string::npos) ? -1 : static_cast<int>(pos);
}

// --- Modification and Transformation (returning new handles) ---

COBRA_API std::string *str_clone(void *handle) {
    if (!handle) return nullptr;
    return new std::string(as_str(handle));
}

COBRA_API std::string *str_to_upper(void *handle) {
    if (!handle) return nullptr;
    std::string s = as_str(handle);
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
    return new std::string(s);
}

COBRA_API std::string *str_to_lower(void *handle) {
    if (!handle) return nullptr;
    std::string s = as_str(handle);
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    return new std::string(s);
}

COBRA_API std::string *str_substring(void *handle, int start, int len) {
    if (!handle) return nullptr;
    return new std::string(as_str(handle).substr(std::max(0, start), std::max(0, len)));
}

COBRA_API std::string *str_replace(void *handle, const char *old_str, const char *new_str) {
    if (!handle || !old_str || !new_str) return str_clone(handle);
    std::string s = as_str(handle);
    std::string old_s(old_str);
    std::string new_s(new_str);
    size_t pos = 0;
    while ((pos = s.find(old_s, pos)) != std::string::npos) {
        s.replace(pos, old_s.length(), new_s);
        pos += new_s.length();
    }
    return new std::string(s);
}

COBRA_API std::string *str_trim(void *handle) {
    if (!handle) return nullptr;
    std::string s = as_str(handle);
    const char *ws = " \t\n\r\f\v";
    s.erase(0, s.find_first_not_of(ws));
    s.erase(s.find_last_not_of(ws) + 1);
    return new std::string(s);
}

COBRA_API std::string *str_reverse(void *handle) {
    if (!handle) return nullptr;
    std::string s = as_str(handle);
    std::reverse(s.begin(), s.end());
    return new std::string(s);
}

COBRA_API std::string *str_concat_handle(void *handle1, void *handle2) {
    if (!handle1) return str_clone(handle2);
    if (!handle2) return str_clone(handle1);
    return new std::string(as_str(handle1) + as_str(handle2));
}
} // extern "C"
