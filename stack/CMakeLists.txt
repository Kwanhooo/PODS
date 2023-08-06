cmake_minimum_required(VERSION 3.26)
project(stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(stack main.cpp
        sequence_stack.cpp
        sequence_stack.h
        element.h
        linked_stack.cpp
        linked_stack.h
        doubly_linked_stack.cpp
        doubly_linked_stack.h
)
