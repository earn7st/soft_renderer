#ifndef __UNIFORMS_H__
#define __UNIFORMS_H__

#include "matrix.hpp"

struct PerFrameUniform
{
    Matrix view_matrix = Matrix::Identity;
    Matrix projection_matrix = Matrix::Identity;
    Matrix view_projection_matrix = Matrix::Identity;
    Vec3f world_camera_position = Vec3f(0.0f);
};

struct PerModelUniform
{
    Matrix model_matrix = Matrix::Identity;
};

#endif