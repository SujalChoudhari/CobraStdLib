cmake_minimum_required(VERSION 3.20)
project(CobraStdLib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else ()
    if (WIN32)
        set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -static")
    endif ()
endif ()

set(COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(COMMON_EXPORT_DEF COBRA_EXPORTS)

function(add_cobra_library module_name)
    add_library(${module_name} SHARED ${ARGN})
    set_target_properties(${module_name} PROPERTIES PREFIX "" OUTPUT_NAME "cobra_${module_name}")
    target_include_directories(${module_name} PUBLIC ${COMMON_INCLUDE_DIR})
    target_compile_definitions(${module_name} PRIVATE ${COMMON_EXPORT_DEF})
endfunction()

add_cobra_library(str src/str.cpp)
add_cobra_library(math src/math.cpp)
