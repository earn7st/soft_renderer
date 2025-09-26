#ifndef __SHADER_H__
#define __SHADER_H__

#include "vector.hpp"
#include "uniforms.h"
#include "vertex.h"

#include <functional>

struct FragmentInput
{

};

typedef std::function<void(Vertex&, const Uniforms&)> VertexShader;
typedef std::function<Vec3f(const FragmentInput&, const Uniforms&)> FragmentShader;

void blinn_phong_vertex_shader(Vertex& input, const Uniforms& uniforms);
Vec3f blinn_phong_fragment_shader(const FragmentInput& input, const Uniforms& uniforms);

class Shader
{
public:
    Shader() = default;

    void execute_vertex_shader(Vertex& input, const Uniforms& uniforms);
    Vec3f execute_fragment_shader(const FragmentInput& input, const Uniforms& uniforms);

private:
    VertexShader vertex_shader_ = blinn_phong_vertex_shader;
    FragmentShader fragment_shader_ = blinn_phong_fragment_shader;
};

#endif