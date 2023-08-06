cmake_minimum_required(VERSION 3.26)
project(queue)

set(CMAKE_CXX_STANDARD 17)

add_executable(queue main.cpp
        element.h
        sequence_queue.cpp
        sequence_queue.h
        linked_queue.cpp
        linked_queue.h
)
