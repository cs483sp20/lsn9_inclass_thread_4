cmake_minimum_required(VERSION 3.6)
project(l9_four_threads)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(l9_four_threads ${SOURCE_FILES})

target_link_libraries(l9_four_threads "-lpthread")
