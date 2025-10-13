cmake_minimum_required(VERSION 3.20)
project(CobraStdLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# All modules will share the same include directory and export definition
set(COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(COMMON_EXPORT_DEF COBRA_EXPORTS)

# Math shared lib
add_library(cobra_math SHARED
        src/math/arithmetic.cpp
        src/math/combinatorics.cpp
        src/math/complex.cpp
        src/math/constants.cpp
        src/math/geometry.cpp
        src/math/hyperbolic.cpp
        src/math/number_theory.cpp
        src/math/random.cpp
        src/math/statistics.cpp
        src/math/trig.cpp
        src/math/utils.cpp
)
target_include_directories(cobra_math PUBLIC ${COMMON_INCLUDE_DIR})
target_compile_definitions(cobra_math PRIVATE ${COMMON_EXPORT_DEF})

# Algorithms shared lib
add_library(cobra_algorithms SHARED
        src/algorithms/algorithms.cpp
        src/algorithms/algorithms.h
)
target_include_directories(cobra_algorithms PUBLIC ${COMMON_INCLUDE_DIR})
target_compile_definitions(cobra_algorithms PRIVATE ${COMMON_EXPORT_DEF})

# IO shared lib
add_library(cobra_io SHARED
        src/io/io.cpp
        src/io/io.h
)
target_include_directories(cobra_io PUBLIC ${COMMON_INCLUDE_DIR})
target_compile_definitions(cobra_io PRIVATE ${COMMON_EXPORT_DEF})

# File shared lib
add_library(cobra_file SHARED
        src/file/file.cpp
        src/file/file.h
)
target_include_directories(cobra_file PUBLIC ${COMMON_INCLUDE_DIR})
target_compile_definitions(cobra_file PRIVATE ${COMMON_EXPORT_DEF})

# Path shared lib
add_library(cobra_path SHARED
        src/path/path.cpp
        src/path/path.h
)
target_include_directories(cobra_path PUBLIC ${COMMON_INCLUDE_DIR})
target_compile_definitions(cobra_path PRIVATE ${COMMON_EXPORT_DEF})