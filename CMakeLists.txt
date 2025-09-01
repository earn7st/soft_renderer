cmake_minimum_required(VERSION 3.10)
project(SCRNE)
include_directories(
    src/maths
    include/core
    include/lights
    include/shaders
)
add_executable(scrne 
    src/main.cpp
    src/maths/matrix.cpp
    src/core/framebuffer.cpp
    src/core/material.cpp
    src/core/mesh.cpp
    src/core/model.cpp
    src/core/renderer.cpp
    src/core/resource_manager.cpp
    src/core/scene.cpp
    src/core/texture.cpp
    src/shaders/blinn_phong_f.cpp
    src/shaders/blinn_phong_v.cpp

)

