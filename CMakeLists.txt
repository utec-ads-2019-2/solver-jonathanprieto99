cmake_minimum_required(VERSION 3.12)
project(solver-jonathanprieto99)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS -pthread)



add_executable(solver-jonathanprieto99 node.h tree.h main.cpp)