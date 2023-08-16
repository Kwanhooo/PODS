cmake_minimum_required(VERSION 3.26)
project(graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(graph main.cpp
        adjacency_matrix_graph.cpp
        adjacency_matrix_graph.h
        linked_list_graph.cpp
        linked_list_graph.h)
