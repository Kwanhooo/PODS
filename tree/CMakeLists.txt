cmake_minimum_required(VERSION 3.26)
project(tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(tree main.cpp
        sequence_binary_tree.cpp
        sequence_binary_tree.h
        element.h
        sequence_binary_tree_zero.cpp
        sequence_binary_tree_zero.h
        threaded_binary_tree.cpp
        threaded_binary_tree.h)
