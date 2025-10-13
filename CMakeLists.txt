cmake_minimum_required(VERSION 3.20)
project(CobraStdLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# This block forces static linking of the C++ runtime.
# This makes our DLLs self-contained and portable.
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    # For GCC/Clang on Windows (like MinGW)
    if(WIN32)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    endif()
endif()

set(COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(COMMON_EXPORT_DEF COBRA_EXPORTS)

# --- Define a function to simplify creating libraries ---
function(add_cobra_library module_name)
    add_library(${module_name} SHARED ${ARGN})

    # Enforce consistent output names (e.g., "cobra_math.dll" not "libcobra_math.dll")
    set_target_properties(${module_name} PROPERTIES OUTPUT_NAME "cobra_${module_name}")

    target_include_directories(${module_name} PUBLIC ${COMMON_INCLUDE_DIR})
    target_compile_definitions(${module_name} PRIVATE ${COMMON_EXPORT_DEF})
endfunction()


# --- Use the function to define all our libraries ---

# Math shared lib
add_cobra_library(math
        src/math/arithmetic.cpp src/math/combinatorics.cpp src/math/complex.cpp
        src/math/constants.cpp src/math/geometry.cpp src/math/hyperbolic.cpp
        src/math/number_theory.cpp src/math/random.cpp src/math/statistics.cpp
        src/math/trig.cpp src/math/utils.cpp
)

# Algorithms shared lib
add_cobra_library(algorithms
        src/algorithms/algorithms.cpp
        src/algorithms/algorithms.h
)

# IO shared lib
add_cobra_library(io
        src/io/io.cpp
        src/io/io.h
)

# File shared lib
add_cobra_library(file
        src/file/file.cpp
        src/file/file.h
)

# Path shared lib
add_cobra_library(path
        src/path/path.cpp
        src/path/path.h
)