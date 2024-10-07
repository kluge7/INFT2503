# exercise1/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

# Set the project name and version for exercise1
project(Exercise1Project VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Include the header files from the include directory in exercise1
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add all source files from the src directory in exercise1
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Create the executable for exercise1
add_executable(exercise1_executable ${SRC_FILES})
