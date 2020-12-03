cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(untitled main.cpp)

include(FindPkgConfig)
find_package(library REQUIRED)
include_directories(${LIBRARY_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${LIBRARY_LIBRARY})