cmake_minimum_required(VERSION 3.10)
project(SCRNE)
include_directories(
    src/maths
    src/core
    src/tests
)
add_executable(scrne 
    src/main.cpp
    src/maths/matrix.cpp
)

