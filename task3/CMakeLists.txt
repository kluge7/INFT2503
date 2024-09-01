cmake_minimum_required(VERSION 3.5)

project(task3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra)

add_executable(exercise1 exercise1.cpp)

add_subdirectory(exercise2)
add_subdirectory(exercise3)
add_subdirectory(exercise4)

