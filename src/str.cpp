#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <stdexcept>

#include "cobra.h"

// --- Helper Functions ---
namespace {
    // Safely cast the generic handle to a std::string pointer
    inline std::string* to_str_ptr(void* handle) {
        return static_cast<std::string*>(handle);
    }

    // Safely get a reference, throwing if the handle is null
    inline const std::string& as_str(void* handle) {
        if (!handle) throw std::runtime_error("String handle is null.");
        return *to_str_ptr(handle);
    }

    // Helper to allocate a C-style string for the FFI to consume.
    // The C# side is responsible for freeing this with str_free_string.
    char* return_string(const std::string& s) {
        char* buffer = new char[s.length() + 1];
    #if defined(_WIN32) || defined(_MSC_VER)
        strcpy_s(buffer, s.length() + 1, s.c_str());
    #else
        strcpy(buffer, s.c_str());
    #endif
        return buffer;
    }
}

extern "C" {

// --- Memory Management ---
COBRA_API std::string* str_create(const char* initial_value) {
    if (initial_value == nullptr) {
        return new std::string();
    }
    return new std::string(initial_value);
}

COBRA_API void str_delete(void* handle) {
    delete to_str_ptr(handle);
}

// --- FFI String Marshalling ---
COBRA_API char* str_get_as_string(void* handle) {
    if (!handle) return return_string("");
    return return_string(as_str(handle));
}

COBRA_API void str_free_string(char* buffer) {
    delete[] buffer;
}

// --- String Operations (returning primitives) ---
COBRA_API int str_length(void* handle) {
    return handle ? static_cast<int>(as_str(handle).length()) : 0;
}

COBRA_API bool str_is_empty(void* handle) {
    return handle ? as_str(handle).empty() : true;
}

COBRA_API bool str_contains(void* handle, const char* sub) {
    if (!handle || !sub) return false;
    return as_str(handle).find(sub) != std::string::npos;
}

// --- String Operations (returning new handles) ---
COBRA_API std::string* str_to_upper(void* handle) {
    if (!handle) return nullptr;
    std::string s = as_str(handle);
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::toupper(c); });
    return new std::string(s);
}

COBRA_API std::string* str_to_lower(void* handle) {
    if (!handle) return nullptr;
    std::string s = as_str(handle);
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
    return new std::string(s);
}

COBRA_API std::string* str_substring(void* handle, int start, int len) {
    if (!handle) return nullptr;
    return new std::string(as_str(handle).substr(std::max(0, start), std::max(0, len)));
}

COBRA_API std::string* str_replace(void* handle, const char* old_str, const char* new_str) {
    if (!handle || !old_str || !new_str) return new std::string(as_str(handle));
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

} // extern "C"
