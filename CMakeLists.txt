cmake_minimum_required(VERSION 3.20)

project(extcp)

set(CMAKE_CXX_STANDARD 23)

message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Operating system: ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION} ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "Linker: ${CMAKE_LINKER}")



# add compiler flags
if(CMAKE_BUILD_TYPE MATCHES Release)
    add_compile_options(-O3 -Wall -Wextra -Wpedantic -std=c++23)
else()
    # for gdb
    add_compile_options(-g -O0 -std=c++23)
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/example)