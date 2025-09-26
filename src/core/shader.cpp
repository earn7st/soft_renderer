#include "shader.h"
#include "uniforms.h"

void Shader::execute_vertex_shader(Vertex& input, const Uniforms& uniforms)
{
    return vertex_shader_(input, uniforms);
}

Vec3f Shader::execute_fragment_shader(const FragmentInput& input, const Uniforms& uniforms)
{
    return fragment_shader_(input, uniforms);
}

/*
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
*/

void blinn_phong_vertex_shader(Vertex& input, const Uniforms& uniforms)
{
    input.pos = uniforms.MVP_matrix * input.pos;
    // input.normal = 
    // input.texcoord = 
}

Vec3f blinn_phong_fragment_shader(const FragmentInput& input, const Uniforms& uniforms)
{
    return Vec3f(0);
}