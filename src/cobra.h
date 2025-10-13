#pragma once

// This header defines the single export/import macro for all CobraStdLib modules.

#if defined(_WIN32)
    // The COBRA_EXPORTS definition is set by CMake for each library being built.
    #ifdef COBRA_EXPORTS
        #define COBRA_API __declspec(dllexport)
    #else
        #define COBRA_API __declspec(dllimport)
    #endif
#else // For Linux, macOS, etc., the macro is empty.
    #define COBRA_API
#endif