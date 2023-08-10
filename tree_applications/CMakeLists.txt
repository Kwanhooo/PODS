cmake_minimum_required(VERSION 3.26)
project(tree_applications)

set(CMAKE_CXX_STANDARD 17)

add_executable(tree_applications main.cpp
        disjoint_set.cpp
        disjoint_set.h
        huffman_encoding.cpp
        huffman_encoding.h
)
