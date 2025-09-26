#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

#include "vector.hpp"
#include "matrix.hpp"

struct Vertex
{
    Vertex() = default;
    Vertex(const Vec4f& _pos, const Vec4f& _normal, const Vec2f& _texcoord)
    : pos(_pos), normal(_normal), texcoord(_texcoord) {}
    Vertex(const Vertex& v) : pos(v.pos), normal(v.normal), texcoord(v.texcoord){}
    
    Vec4f pos;
    Vec4f normal;
    Vec2f texcoord;
};

#endif