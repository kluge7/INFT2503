cmake_minimum_required(VERSION 3.5)

project(exercise2)

add_executable(exercise2 
    main.cpp 
    Circle.cpp 
)
target_include_directories(exercise2 PRIVATE ${CMAKE_SOURCE_DIR}/exercise2)
