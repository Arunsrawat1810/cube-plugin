cmake_minimum_required(VERSION 3.10)
project(CubeJsonPlugin)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Dynamically grab CubeLib includes
file(GLOB_RECURSE CUBELIB_HEADERS
    "/home/arun/Downloads/cubelib-4.9/src/cube/include/*.h"
)
foreach(header ${CUBELIB_HEADERS})
    get_filename_component(header_dir ${header} DIRECTORY)
    list(APPEND CUBELIB_INCLUDE_DIRS ${header_dir})
endforeach()
list(REMOVE_DUPLICATES CUBELIB_INCLUDE_DIRS)

include_directories(${CUBELIB_INCLUDE_DIRS})

# CubeGUI include dirs
include_directories(
    /home/arun/Downloads/cubegui-4.9/src
    /home/arun/Downloads/cubegui-4.9/src/GUI-qt/display
    /home/arun/Downloads/cubegui-4.9/src/GUI-qt/display/plugins
    /home/arun/Downloads/cubegui-4.9/src/GUI-qt/display/utils
)

add_library(CubeJsonPlugin SHARED
    src/CubeJsonPlugin.cpp
    src/CubeJsonPlugin.h
)

target_link_libraries(CubeJsonPlugin Qt6::Widgets)
