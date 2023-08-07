cmake_minimum_required(VERSION 3.26)
project(string)

set(CMAKE_CXX_STANDARD 17)

add_executable(string main.cpp
        sequence_string.cpp
        sequence_string.h
        kmp.cpp
        kmp.h)
