cmake_minimum_required(VERSION 3.20)
project(CobraStdLib)

set(CMAKE_CXX_STANDARD 23)

# Math shared lib
add_library(cobra_math SHARED src/math/math.cpp src/math/math.h)
target_include_directories(cobra_math PUBLIC math)


# Algorithms Shared Library
add_library(cobra_algorithms SHARED
        src/algorithms/algorithms.cpp
        src/algorithms/algorithms.h)
target_include_directories(cobra_math PUBLIC math)
