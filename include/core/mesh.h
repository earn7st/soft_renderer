#ifndef __MESH_H__
#define __MESH_H__

#include "vertex.h"

struct Mesh
{
    uint32_t num_vertices = 0;
    std::vector<Vec3f> vertices;
    std::vector<Vec3f> normals;
    std::vector<Vec2f> texcoords;

    uint32_t num_faces = 0;
    std::vector<uint32_t> vertex_indices;
    std::vector<uint32_t> normal_indices;
    std::vector<uint32_t> texcoord_indices;
};

/*
// TODO vertices expansion when draw_call
struct ProcessedMesh
{
    void initialize(const Mesh& mesh)
    {
        num_vertices = mesh.num_vertices;
        for(auto it = mesh.vertices.begin(); it != mesh.vertices.end(); ++it)
        {
            vertices.push_back(Vec4f(*it, 1.0f));
        }
        normals.assign(mesh.normals.begin(), mesh.normals.end());
        processed_vertices.assign(num_vertices, false); 
        processed_normals.assign(num_vertices, false);
    }

    uint32_t num_vertices = 0;
    std::vector<Vec4f> vertices;
    std::vector<Vec3f> normals;
    std::vector<bool> processed_vertices;
    std::vector<bool> processed_normals;
};
*/

#endif