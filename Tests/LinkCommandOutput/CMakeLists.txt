# a simple CPP test case
cmake_minimum_required(VERSION 2.6)
include(CMakePrintHelpers)
project (LinkCommandOutput CXX)

set(CMAKE_EXPORT_LINK_COMMANDS ON)
set(CMAKE_DEBUG_POSTFIX "_test_debug_postfix")

#Simple link flag
add_link_options(-Wl)

#To c
add_library(say-a STATIC
        c.cpp
        a1.cpp)

add_library(say-c SHARED
        a.cpp)

add_executable(maina maina.cpp)
add_executable(mainb mainb.cpp b.cpp)
include_directories(${LinkCommandOutput_SOURCE_DIR}/../../Source)
target_link_libraries(maina PRIVATE say-c say-a)
