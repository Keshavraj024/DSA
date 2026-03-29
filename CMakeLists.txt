cmake_minimum_required(VERSION 3.16)

project(DSA VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

add_executable(DSA LinkedList/LinkedList.h LinkedList/LinkedList.cpp main.cpp)
target_compile_features(DSA PRIVATE cxx_std_23)
