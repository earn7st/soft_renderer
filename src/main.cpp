#include <iostream>

#include "vector.hpp"
#include "matrix.hpp"

#include "vertex.hpp"
#include "mesh.hpp"

#include "buffer.hpp"
#include "camera.hpp"

void DrawTriangle(const Camera& cam, const Mesh& mesh)
{
    Mat4 model_mat = Matrix::Identity;
    Mat4 view_mat = lookAt(cam.pos_, cam.center_, cam.up_);
    for(int i = 0; i < 3; ++i)
    {
        Vertex view_vertex;
        Vector4<float> vec;
        vec = view_mat * model_mat * Vector4<float>(mesh.vertices_[mesh.indices_[i]].pos, 1.0f);
        std::cout << vec;
    }
}

int main()
{

    Camera camera(Vec3f(0, 2, -5), Vec3f(0, 0, 0), Vec3f(0, 1, 0), 1.5f);
    
    Mesh m;

    Vertex v0(-1, 1, 0), v1(1, 1, 0), v2(0, -1, 0);
    m.vertices_.push_back(v0), m.vertices_.push_back(v1), m.vertices_.push_back(v2);
    m.indices_.push_back(0), m.indices_.push_back(1), m.indices_.push_back(2);
    
    DrawTriangle(camera, m);


    return 0;
}