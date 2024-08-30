# Linki Cmake file
cmake_minimum_required(VERSION 3.10)
project(linki)

# C language
set(CMAKE_C_STANDARD 11)


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-D DEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")

if (WIN32)
    add_link_options(-lWs2_32)
endif()

add_library(linki SHARED)
target_include_directories(linki PUBLIC "native/${CMAKE_SYSTEM_NAME}/include/")


file(GLOB_RECURSE LINKI_SRC "native/${CMAKE_SYSTEM_NAME}/src/*.c")
target_sources(linki PRIVATE ${LINKI_SRC})
target_link_libraries(linki PRIVATE -static -lws2_32)