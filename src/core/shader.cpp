#include "shader.h"
#include "uniform.h"

VertexOut Shader::execute_vertex_shader(const Vertex& input, const Uniform& uniform) const
{
    return vertex_shader_(input, uniform);
}

RGBA Shader::execute_fragment_shader(const FragmentIn& input, const Uniform& uniform) const
{
    return fragment_shader_(input, uniform);
}

/*
struct Uniform
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

VertexOut default_vertex_shader(const Vertex& input, const Uniform& uniform)
{
    VertexOut out;
    std::cout << uniform.view_matrix * uniform.model_matrix * input.pos;
    out.clip_pos = uniform.MVP_matrix * input.pos;
    out.world_pos = uniform.model_matrix * input.pos;
    // out.world_normal = 
    out.texcoord = input.texcoord;

    return out;
}

RGBA blinn_phong_fragment_shader(const FragmentIn& input, const Uniform& uniform)
{
    return RGBA(0, 0, 0, 255);
}

RGBA wireframe_fragment_shader(const FragmentIn& input, const Uniform& uniform)
{
    return RGBA(0, 0, 0, 255); // Black
}