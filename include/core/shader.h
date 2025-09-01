#ifndef __SHADER_H__
#define __SHADER_H__

#include "vector.hpp"

struct VertexInput
{

};

struct VertexOutput
{

};

struct FragmentInput
{

};

struct FragmenOutput
{

};

using VertexShader = std::function<VertexOutput(const VertexInput&, const Uniforms&)>;
using FragmentShader = std::function<Vec4f(const FragmentInput, const Uniforms&)>;

class Shader
{
public:
    Shader() = default;
    
private:
    VertexShader vertex_shader_;
    FragmentShader fragment_shader_;
};

#endif