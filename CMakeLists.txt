# Linki Cmake file
cmake_minimum_required(VERSION 3.10)
project(linki)

# C language
set(CMAKE_C_STANDARD 11)

if (WIN32)
    add_link_options(-lWs2_32)
endif()

add_library(linki SHARED)

include_directories("native/${CMAKE_SYSTEM_NAME}/include/")
file(GLOB_RECURSE LINKI_SRC "native/${CMAKE_SYSTEM_NAME}/src/*.c")
target_sources(linki PRIVATE ${LINKI_SRC})
target_link_libraries(linki PRIVATE -static -lws2_32)