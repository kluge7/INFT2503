cmake_minimum_required(VERSION 3.5)

project(exercise4)

add_executable(exercise4
    main.cpp 
)
target_include_directories(exercise4 PRIVATE ${CMAKE_SOURCE_DIR}/exercise4)
