cmake_minimum_required(VERSION 3.28)
project(SET3_A2i)

set(CMAKE_CXX_STANDARD 17)

add_executable(SET3_A2i main.cpp
        ArrayGenerator.h
        MergeSort.cpp
        HybridSort.h
        HybridSort.cpp
        ArrayGenerator.cpp
        SortTester.h
        SortTester.cpp
)
