#include "path.h"
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#ifdef _WIN32
    #include <windows.h>
    #define PATH_SEPARATOR '\\'
#else
    #include <unistd.h>
    #include <limits.h>
    #define PATH_SEPARATOR '/'
#endif

static bool is_separator(char c) {
#ifdef _WIN32
    return c == '/' || c == '\\';
#else
    return c == '/';
#endif
}

char* path_join(const char* base, const char* addition) {
    if (!base || !addition) return NULL;

    std::string b(base);
    std::string a(addition);

    // If addition is absolute, return addition
    if (path_is_absolute(addition)) {
        char* res = (char*)malloc(a.size() + 1);
        strcpy(res, a.c_str());
        return res;
    }

    // Ensure base ends with separator
    if (!b.empty() && !is_separator(b.back())) {
        b += PATH_SEPARATOR;
    }
    b += a;

    char* res = (char*)malloc(b.size() + 1);
    strcpy(res, b.c_str());
    return res;
}

char* path_absolute(const char* path) {
    if (!path) return NULL;

#ifdef _WIN32
    char buffer[MAX_PATH];
    if (!_fullpath(buffer, path, MAX_PATH)) {
        return NULL;
    }
    size_t len = strlen(buffer);
    char* res = (char*)malloc(len + 1);
    strcpy(res, buffer);
    return res;
#else
    char buffer[PATH_MAX];
    if (!realpath(path, buffer)) {
        return NULL;
    }
    size_t len = strlen(buffer);
    char* res = (char*)malloc(len + 1);
    strcpy(res, buffer);
    return res;
#endif
}

char* path_dirname(const char* path) {
    if (!path) return NULL;
    std::string p(path);

    // Remove trailing separators
    while (!p.empty() && is_separator(p.back())) {
        p.pop_back();
    }
    size_t pos = p.find_last_of(PATH_SEPARATOR);
    if (pos == std::string::npos) {
        // No directory part
        char* res = (char*)malloc(2);
        strcpy(res, ".");
        return res;
    }

    std::string dir = p.substr(0, pos);
    if (dir.empty()) dir = std::string(1, PATH_SEPARATOR);

    char* res = (char*)malloc(dir.size() + 1);
    strcpy(res, dir.c_str());
    return res;
}

char* path_basename(const char* path) {
    if (!path) return NULL;
    std::string p(path);

    // Remove trailing separators
    while (!p.empty() && is_separator(p.back())) {
        p.pop_back();
    }

    size_t pos = p.find_last_of(PATH_SEPARATOR);
    std::string base = (pos == std::string::npos) ? p : p.substr(pos + 1);

    char* res = (char*)malloc(base.size() + 1);
    strcpy(res, base.c_str());
    return res;
}

char* path_extension(const char* path) {
    if (!path) return NULL;
    std::string p(path);
    size_t pos = p.find_last_of('.');
    size_t sep_pos = p.find_last_of(PATH_SEPARATOR);
    if (pos == std::string::npos || (sep_pos != std::string::npos && pos < sep_pos)) {
        // No extension found
        char* res = (char*)malloc(1);
        res[0] = '\0';
        return res;
    }

    std::string ext = p.substr(pos);
    char* res = (char*)malloc(ext.size() + 1);
    strcpy(res, ext.c_str());
    return res;
}

int path_is_absolute(const char* path) {
    if (!path || !*path) return 0;

#ifdef _WIN32
    // e.g. C:\ or \\server\share
    if ((path[0] && path[1] == ':' && (path[2] == '\\' || path[2] == '/')) ||
        (path[0] == '\\' && path[1] == '\\')) {
        return 1;
    }
    return 0;
#else
    return path[0] == '/';
#endif
}

char* path_normalize(const char* path) {
    if (!path) return NULL;
    std::string p(path);

    std::vector<std::string> parts;
    std::stringstream ss(p);
    std::string item;
    char sep = PATH_SEPARATOR;

    // Split by separator
    for (size_t i = 0; i < p.size(); ++i) {
        if (is_separator(p[i])) {
            p[i] = sep;
        }
    }

    size_t start = 0;
    for (size_t i = 0; i <= p.size(); ++i) {
        if (i == p.size() || p[i] == sep) {
            if (i > start) {
                item = p.substr(start, i - start);
                if (item == ".") {
                    // Skip
                } else if (item == "..") {
                    if (!parts.empty()) parts.pop_back();
                } else {
                    parts.push_back(item);
                }
            }
            start = i + 1;
        }
    }

    std::string normalized;
#ifdef _WIN32
    // Windows absolute path handling
    if (path_is_absolute(path)) {
        if (p.size() >= 2 && p[1] == ':') {
            normalized += p[0];
            normalized += ':';
            normalized += sep;
        }
    }
    // else relative path, no leading separator
#else
    if (path_is_absolute(path)) normalized += sep;
#endif

    for (size_t i = 0; i < parts.size(); ++i) {
        normalized += parts[i];
        if (i + 1 < parts.size()) normalized += sep;
    }

    char* res = (char*)malloc(normalized.size() + 1);
    strcpy(res, normalized.c_str());
    return res;
}
