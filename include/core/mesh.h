#ifndef __MESH_HPP__
#define __MESH_HPP__

#include "vertex.h"

class Mesh
{
public:
    Mesh() = default;

    uint32_t get_num_faces() const { return num_faces_; }

    const std::vector<Vertex>& get_vertices() const { return vertices_; }
    const std::vector<uint32_t>& get_indices() const { return indices_; }

    // For Test
    void add_vertex(Vertex& vertex) { vertices_.push_back(vertex); }
    void add_index(uint32_t index) { indices_.push_back(index); }

private:
    std::vector<Vertex> vertices_;
    std::vector<uint32_t> indices_;

    uint32_t num_faces_;
};


#endif