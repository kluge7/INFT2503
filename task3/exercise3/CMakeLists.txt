cmake_minimum_required(VERSION 3.5)

project(exercise3)

add_executable(exercise3
    main.cpp 
    Commodity.hpp 
)
target_include_directories(exercise3 PRIVATE ${CMAKE_SOURCE_DIR}/exercise3)
