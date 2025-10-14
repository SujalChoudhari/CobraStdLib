#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>

#include "cobra.h"

#ifdef _WIN32
#include <windows.h>
#include <PathCch.h>
#pragma comment(lib, "Pathcch.lib")
const char PLATFORM_SEPARATOR = '\\';
#else
#include <unistd.h>
#include <limits.h>
const char PLATFORM_SEPARATOR = '/';
#endif

extern "C" {
static char *alloc_and_copy(const std::string &s) {
    char *buf = (char *) malloc(s.length() + 1);
    if (!buf) return nullptr;
    strcpy(buf, s.c_str());
    return buf;
}

COBRA_API char *path_join(const char *p1, const char *p2) {
    if (!p1 || !p2) return nullptr;
    std::string path1(p1);
    if (path1.empty()) return alloc_and_copy(p2);
    if (path1.back() != '/' && path1.back() != '\\') {
        path1 += PLATFORM_SEPARATOR;
    }
    return alloc_and_copy(path1 + p2);
}

COBRA_API char *path_absolute(const char *path) {
    if (!path) return nullptr;
#ifdef _WIN32
    char buffer[MAX_PATH];
    if (_fullpath(buffer, path, MAX_PATH) == nullptr) return nullptr;
#else
    char buffer[PATH_MAX];
    if (realpath(path, buffer) == nullptr) return nullptr;
#endif
    return alloc_and_copy(buffer);
}

COBRA_API char *path_dirname(const char *path) {
    if (!path || !*path) return nullptr;
    std::string p(path);
    size_t pos = p.find_last_of("/\\");
    if (pos == std::string::npos) return alloc_and_copy(".");
    return alloc_and_copy(p.substr(0, pos));
}

COBRA_API char *path_basename(const char *path) {
    if (!path || !*path) return alloc_and_copy("");
    std::string p(path);
    size_t pos = p.find_last_of("/\\");
    if (pos == std::string::npos) return alloc_and_copy(p);
    return alloc_and_copy(p.substr(pos + 1));
}

COBRA_API char *path_extension(const char *path) {
    if (!path) return nullptr;
    std::string base = path_basename(path);
    size_t pos = base.find_last_of('.');
    if (pos == std::string::npos) return alloc_and_copy("");
    return alloc_and_copy(base.substr(pos));
}

COBRA_API bool path_is_absolute(const char *path) {
    if (!path || !*path) return false;
#ifdef _WIN32
    return (path[1] == ':' && (path[2] == '\\' || path[2] == '/')) || (path[0] == '\\' && path[1] == '\\');
#else
    return path[0] == '/';
#endif
}

COBRA_API char *path_normalize(const char *path) {
    if (!path) return nullptr;
    std::string p(path);
    std::vector<std::string> parts;
    std::string current;
    for (char c: p) {
        if (c == '/' || c == '\\') {
            if (!current.empty()) parts.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }
    if (!current.empty()) parts.push_back(current);

    std::vector<std::string> result_parts;
    for (const auto &part: parts) {
        if (part == "..") {
            if (!result_parts.empty()) result_parts.pop_back();
        } else if (part != ".") {
            result_parts.push_back(part);
        }
    }

    std::string result;
    if (path_is_absolute(path)) result += PLATFORM_SEPARATOR;
    for (size_t i = 0; i < result_parts.size(); ++i) {
        result += result_parts[i];
        if (i < result_parts.size() - 1) result += PLATFORM_SEPARATOR;
    }
    return alloc_and_copy(result);
}
}
