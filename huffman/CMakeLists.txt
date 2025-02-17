cmake_minimum_required(VERSION 3.27)
project(huffman)

set(CMAKE_CXX_STANDARD 17)

add_executable(huffman main.cpp
        huffman.h
        huffman_classes.cpp)
