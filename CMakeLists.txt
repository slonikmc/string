cmake_minimum_required(VERSION 3.20)
project(5e_string C)

set(CMAKE_C_STANDARD 11)

add_executable(5e_string main.c)

add_library(str string/string_.h string/string_.c
        # string/tasks/digitToStartTransform.h
        # string/tasks/reverseWords.h
        )

target_link_libraries(5e_string str)
