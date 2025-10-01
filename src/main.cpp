#include <iostream>

#include "vector.hpp"
#include "matrix.hpp"
#include "vertex.h"
#include "mesh.h"
#include "framebuffer.h"
#include "camera.h"
#include "renderer.h"
#include "engine.h"

int main(int argc, char* argv[])
{

    if(argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << "<model_filepath>" << std::endl;
        return 0;
    }

    std::string model_filepath = argv[1];
    
    Engine engine;
    if(engine.start_up(model_filepath) < 0) return -1;
    engine.run();

    return 0;
}