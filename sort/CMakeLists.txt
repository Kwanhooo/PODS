cmake_minimum_required(VERSION 3.26)
project(sort)

set(CMAKE_CXX_STANDARD 17)

add_executable(sort main.cpp
        quick_sort.cpp
        quick_sort.h
        e2e_bubble.cpp
        e2e_bubble.h
        even_odd_carrier.cpp
        even_odd_carrier.h
        kth_small.cpp
        kth_small.h
)
