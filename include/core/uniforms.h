#ifndef __UNIFORMS_H__
#define __UNIFORMS_H__

#include "matrix.hpp"

struct Uniforms
{
    Matrix view_matrix = Matrix::Identity;  // per-frame
    Matrix projection_matrix = Matrix::Identity;    // per-frame
    Matrix VP_matrix = Matrix::Identity; // per-frame
    Vec3f world_camera_position = Vec3f(0.0f);  // per-frame

    Matrix model_matrix = Matrix::Identity; // per-model
    Matrix sub_mesh_matrix = Matrix::Identity;  // per-sub_mesh: local transform 
    Matrix MVP_matrix = Matrix::Identity;
};

#endif