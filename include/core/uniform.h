#ifndef __UNIFORM_H__
#define __UNIFORM_H__

#include "matrix.hpp"

struct Uniform
{
    // per-frame
    Matrix view_matrix = Matrix::Identity;  
    Matrix projection_matrix = Matrix::Identity;    
    Matrix VP_matrix = Matrix::Identity;
    Vec3f world_camera_position = Vec3f(0.0f);  

    // per-model
    Matrix model_matrix = Matrix::Identity;

    // per-submesh
    Matrix sub_mesh_matrix = Matrix::Identity;  // local transform
    Matrix MVP_matrix = Matrix::Identity;

    // material

    // lighting
};

#endif