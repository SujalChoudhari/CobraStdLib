cmake_minimum_required(VERSION 3.20)
project(CobraStdLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Math shared lib
add_library(cobra_math SHARED 
    src/math/math.cpp
    src/math/math.h
)
target_include_directories(cobra_math PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/math
)

# Algorithms shared lib
add_library(cobra_algorithms SHARED
    src/algorithms/algorithms.cpp
    src/algorithms/algorithms.h
)
target_include_directories(cobra_algorithms PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms
)

# IO shared lib
add_library(cobra_io SHARED
    src/io/io.cpp
    src/io/io.h
)
target_include_directories(cobra_io PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/io
)

# File shared lib
add_library(cobra_file SHARED
    src/file/file.cpp
    src/file/file.h
)
target_include_directories(cobra_file PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/file
)

# Path shared lib
add_library(cobra_path SHARED
    src/path/path.cpp
    src/path/path.h
)
target_include_directories(cobra_path PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/path
)

