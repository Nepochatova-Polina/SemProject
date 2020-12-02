cmake_minimum_required(VERSION 3.17)
project(library)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES library.cpp main.cpp)
add_library(library ${SOURCE_FILES})