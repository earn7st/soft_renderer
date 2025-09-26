cmake_minimum_required(VERSION 3.10)
project(SCRNE)

set(SDL3_PATH "/opt/homebrew/Cellar/sdl3/3.2.22/include")
set(SDL3_LIBRARY "/opt/homebrew/Cellar/sdl3/3.2.22/lib/libSDL3.dylib")
include_directories(
    ${SDL3_PATH}
    include/maths
    include/core
    include/light
    include/shader
)
add_executable(scrne
    src/main.cpp
    src/maths/matrix.cpp
    src/core/displayer.cpp
    src/core/engine.cpp
    src/core/framebuffer.cpp
    src/core/input_handler.cpp
    src/core/material.cpp
    src/core/model.cpp
    src/core/renderer.cpp
    src/core/resource_manager.cpp
    src/core/scene.cpp
    src/core/shader.cpp
    src/core/texture.cpp
    )
target_link_libraries(scrne PRIVATE ${SDL3_LIBRARY})
