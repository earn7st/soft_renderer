#ifndef __MESH_HPP__
#define __MESH_HPP__

#include "vertex.hpp"

class Mesh
{
public:
    Mesh() = default;
    
    std::vector<Vertex> vertices_;
    std::vector<uint32_t> indices_;
};

#endif