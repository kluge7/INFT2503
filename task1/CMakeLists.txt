cmake_minimum_required(VERSION 3.5)

project(solution1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")

add_executable(solution1 solution1.cpp)
add_executable(solution2 solution2.cpp)
