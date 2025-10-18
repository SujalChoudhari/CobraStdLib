#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <ranges>
#include <sstream>

#include "cobra.h"

inline std::string* to_str_ptr(void* handle) {
    return static_cast<std::string*>(handle);
}

inline std::vector<std::string*>* to_vec_ptr(void* handle) {
    return static_cast<std::vector<std::string*>*>(handle);
}

extern "C" {

// --- Memory Management ---

COBRA_API std::string* str_new(const char* initial_value) {
    if (initial_value == nullptr) {
        return new std::string();
    }
    return new std::string(initial_value);
}

COBRA_API void str_delete(void* handle) {
    delete to_str_ptr(handle);
}

// --- Conversion (Marshalling back to Cobra) ---

COBRA_API char* str_get_as_string(void* handle) {
    if (!handle) {
        char* empty = new char[1];
        empty[0] = '\0';
        return empty;
    }

    const std::string& source = *to_str_ptr(handle);
    char* dest = new char[source.length() + 1];

#if defined(_WIN32) || defined(_MSC_VER)
    strcpy_s(dest, source.length() + 1, source.c_str());
#else
    strcpy(dest, source.c_str());
#endif

    return dest;
}

COBRA_API void str_free_string(char* buffer) {
    delete[] buffer;
}


// --- Information & Comparison ---

COBRA_API int str_length(void* handle) {
    if (!handle) return 0;
    return static_cast<int>(to_str_ptr(handle)->length());
}

COBRA_API bool str_equals(void* handle, const char* other) {
    if (!handle || !other) return false;
    return to_str_ptr(handle)->compare(other) == 0;
}

COBRA_API bool str_equals_handle(void* handle1, void* handle2) {
    if (handle1 == handle2) return true;
    if (!handle1 || !handle2) return false;
    return *to_str_ptr(handle1) == *to_str_ptr(handle2);
}

COBRA_API bool str_starts_with(void* handle, const char* prefix) {
    if (!handle || !prefix) return false;
    return to_str_ptr(handle)->starts_with(prefix);
}

COBRA_API bool str_ends_with(void* handle, const char* suffix) {
    if (!handle || !suffix) return false;
    return to_str_ptr(handle)->ends_with(suffix);
}


// --- Manipulation (these all return new handles) ---

COBRA_API std::string* str_concat(void* handle, const char* other) {
    if (!handle || !other) return nullptr;
    return new std::string(*to_str_ptr(handle) + other);
}

COBRA_API std::string* str_concat_handle(void* handle1, void* handle2) {
    if (!handle1 || !handle2) return nullptr;
    return new std::string(*to_str_ptr(handle1) + *to_str_ptr(handle2));
}

COBRA_API std::string* str_substring(void* handle, int start, int length) {
    if (!handle) return nullptr;
    return new std::string(to_str_ptr(handle)->substr(start, length));
}

COBRA_API std::string* str_to_upper(void* handle) {
    if (!handle) return nullptr;
    std::string upper_str = *to_str_ptr(handle);
    std::ranges::transform(upper_str, upper_str.begin(),
                           [](unsigned char c) { return std::toupper(c); });
    return new std::string(upper_str);
}

COBRA_API std::string* str_to_lower(void* handle) {
    if (!handle) return nullptr;
    std::string lower_str = *to_str_ptr(handle);
    std::ranges::transform(lower_str, lower_str.begin(),
                           [](unsigned char c) { return std::tolower(c); });
    return new std::string(lower_str);
}

COBRA_API std::string* str_reverse(void* handle) {
    if (!handle) return nullptr;
    std::string reversed_str = *to_str_ptr(handle);
    std::ranges::reverse(reversed_str);
    return new std::string(reversed_str);
}

COBRA_API std::string* str_replace(void* handle, const char* old_substr, const char* new_substr) {
    if (!handle || !old_substr || !new_substr) return nullptr;
    std::string new_str = *to_str_ptr(handle);
    std::string old_s(old_substr);
    std::string new_s(new_substr);
    size_t pos = 0;
    while ((pos = new_str.find(old_s, pos)) != std::string::npos) {
        new_str.replace(pos, old_s.length(), new_s);
        pos += new_s.length();
    }
    return new std::string(new_str);
}

COBRA_API std::string* str_trim_start(void* handle) {
    if (!handle) return nullptr;
    std::string s = *to_str_ptr(handle);
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return new std::string(s);
}

COBRA_API std::string* str_trim_end(void* handle) {
    if (!handle) return nullptr;
    std::string s = *to_str_ptr(handle);
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return new std::string(s);
}

COBRA_API std::string* str_trim(void* handle) {
    if (!handle) return nullptr;
    std::string s = *to_str_ptr(handle);
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return new std::string(s);
}

// --- Splitting ---

COBRA_API void* str_split(void* handle, const char* delimiter) {
    if (!handle || !delimiter) return nullptr;

    auto* results = new std::vector<std::string*>();
    std::string source = *to_str_ptr(handle);
    std::string delim(delimiter);
    size_t pos_start = 0, pos_end;

    if (delim.empty() && !source.empty()) {
        for (char c : source) {
            results->push_back(new std::string(1, c));
        }
        return results;
    }

    while ((pos_end = source.find(delim, pos_start)) != std::string::npos) {
        std::string token = source.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim.length();
        results->push_back(new std::string(token));
    }

    results->push_back(new std::string(source.substr(pos_start)));
    return results;
}

COBRA_API int str_split_result_count(void* split_result_handle) {
    if (!split_result_handle) return 0;
    return static_cast<int>(to_vec_ptr(split_result_handle)->size());
}

COBRA_API std::string* str_split_result_get(void* split_result_handle, int index) {
    if (!split_result_handle) return nullptr;
    auto* vec = to_vec_ptr(split_result_handle);
    if (index < 0 || static_cast<size_t>(index) >= vec->size()) {
        return nullptr;
    }
    return (*vec)[index];
}

COBRA_API void str_split_result_delete(void* split_result_handle) {
    if (!split_result_handle) return;
    auto* vec = to_vec_ptr(split_result_handle);
    for (std::string* s : *vec) {
        delete s;
    }
    delete vec;
}

}