cmake_minimum_required(VERSION 3.26)
project(linear_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(linear_list
        sequence_list.cpp
        sequence_list.h
        main.cpp
        linked_list.cpp
        linked_list.h
        element.h
)
