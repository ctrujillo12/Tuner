# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

# src/CMakeLists.txt

# Grab all .c and .cpp source files in src/
FILE(GLOB_RECURSE app_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

idf_component_register(
    SRCS ${app_sources}
    INCLUDE_DIRS "."  # include current directory for headers
)

