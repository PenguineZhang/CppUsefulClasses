cmake_minimum_required(VERSION 3.0)
project(DataStructures)

add_library(DataStructures SHARED DataStructures.hpp DataStructures.cpp)

add_executable(main main.cpp)
target_link_libraries(main DataStructures)