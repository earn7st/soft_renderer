#ifndef __SHADER_H__
#define __SHADER_H__

#include "vector.hpp"
#include "uniform.h"
#include "vertex.h"

#include <functional>

struct Varying
{
    Vec4f clip_pos;
    Vec4f world_pos;
    Vec4f world_normal;
    Vec2f texcoord;
    float clip_w;
};

typedef Varying VertexOut;
typedef Varying FragmentIn;

typedef std::function<VertexOut(const Vertex&, const Uniform&)> VertexShader;
typedef std::function<RGBA(const FragmentIn&, const Uniform&)> FragmentShader;

VertexOut default_vertex_shader(const Vertex& input, const Uniform& uniform);
RGBA blinn_phong_fragment_shader(const FragmentIn& input, const Uniform& uniform);
RGBA wireframe_fragment_shader(const FragmentIn& input, const Uniform& uniform);

class Shader
{
public:
    Shader(VertexShader vs = default_vertex_shader, FragmentShader fs = blinn_phong_fragment_shader)
    : vertex_shader_(vs), fragment_shader_(fs) {}

    VertexOut execute_vertex_shader(const Vertex& input, const Uniform& uniform) const;
    RGBA execute_fragment_shader(const FragmentIn& input, const Uniform& uniform) const;

private:
    VertexShader vertex_shader_;
    FragmentShader fragment_shader_;
};

#endif