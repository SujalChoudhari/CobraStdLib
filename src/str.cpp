// FILE: CobraStdLib/src/str.cpp

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring> // Required for strcpy

#include "cobra.h"

// Helper to safely cast a void* handle to a std::string pointer.
inline std::string *to_str_ptr(void *handle) {
    return static_cast<std::string *>(handle);
}

extern "C" {
// --- Memory Management ---

/**
 * @brief Creates a new std::string on the heap from a C-style string.
 * @param initial_value The initial text. Can be null, which creates an empty string.
 * @return A handle (pointer) to the new std::string object.
 */
COBRA_API std::string *str_new(const char *initial_value) {
    if (initial_value == nullptr) {
        return new std::string();
    }
    return new std::string(initial_value);
}

/**
 * @brief Deletes a std::string from the heap using its handle.
 * @param handle The handle to the string to delete.
 */
COBRA_API void str_delete(void *handle) {
    // Deleting a nullptr is a safe no-op in C++.
    delete to_str_ptr(handle);
}

// --- Conversion (for Marshalling back to Cobra) ---

/**
 * @brief Allocates a new C-string buffer and copies the handle's content into it.
 * This is the safe way to pass a string to the .NET runtime.
 * @param handle The handle to the string.
 * @return A new `char*` buffer that the caller must free by calling `str_free_string`.
 */
COBRA_API char *str_get_as_string(void *handle) {
    if (!handle) {
        // Return an empty, but valid, C-string if the handle is null.
        char *empty = new char[1];
        empty[0] = '\0';
        return empty;
    }

    const std::string &source = *to_str_ptr(handle);
    // Allocate enough memory for the string content plus the null terminator.
    char *dest = new char[source.length() + 1];

    // Use the secure version of strcpy on Windows, and standard strcpy on other platforms.
#if defined(_WIN32) || defined(_MSC_VER)
    strcpy_s(dest, source.length() + 1, source.c_str());
#else
    strcpy(dest, source.c_str());
#endif

    return dest;
}

/**
 * @brief Frees a C-string buffer that was allocated by `str_get_as_string`.
 * This is called by the C# interpreter to prevent memory leaks.
 * @param buffer The pointer to the C-string buffer to free.
 */
COBRA_API void str_free_string(char *buffer) {
    delete[] buffer;
}


// --- Comparison ---

COBRA_API bool str_equals(void *handle, const char *other) {
    if (!handle || !other) return false;
    return *to_str_ptr(handle) == other;
}

COBRA_API bool str_equals_handle(void *handle1, void *handle2) {
    if (!handle1 || !handle2) return (handle1 == handle2); // True if both are null.
    return *to_str_ptr(handle1) == *to_str_ptr(handle2);
}

// --- Information ---

COBRA_API int str_length(void *handle) {
    if (!handle) return 0;
    return static_cast<int>(to_str_ptr(handle)->length());
}

// --- Manipulation (these all return new handles) ---

COBRA_API std::string *str_concat(void *handle, const char *other) {
    if (!handle || !other) return nullptr;
    return new std::string(*to_str_ptr(handle) + other);
}

COBRA_API std::string *str_concat_handle(void *handle1, void *handle2) {
    if (!handle1 || !handle2) return nullptr;
    return new std::string(*to_str_ptr(handle1) + *to_str_ptr(handle2));
}

COBRA_API std::string *str_substring(void *handle, int start, int length) {
    if (!handle) return nullptr;
    return new std::string(to_str_ptr(handle)->substr(start, length));
}

COBRA_API std::string *str_to_upper(void *handle) {
    if (!handle) return nullptr;
    std::string upper_str = *to_str_ptr(handle);
    std::ranges::transform(upper_str, upper_str.begin(),
                           [](unsigned char c) { return std::toupper(c); });
    return new std::string(upper_str);
}

COBRA_API std::string *str_to_lower(void *handle) {
    if (!handle) return nullptr;
    std::string lower_str = *to_str_ptr(handle);
    std::ranges::transform(lower_str, lower_str.begin(),
                           [](unsigned char c) { return std::tolower(c); });
    return new std::string(lower_str);
}
}
