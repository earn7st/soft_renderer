#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

#include "vector.hpp"
#include "matrix.hpp"

struct Vertex
{
    Pos3f pos;
    Vec3f normal;
    Coord2f texcoord;

    Vertex() = default;
    Vertex(float posX, float posY, float posZ) : pos(posX, posY, posZ) {}
    Vertex(const Vertex& v) : pos(v.pos), normal(v.normal), texcoord(v.texcoord){}
};

struct Triangle
{
    Vertex v0, v1, v2;

    Triangle() = default;
    Triangle(const Vertex& _v0, const Vertex& _v1, const Vertex& _v2) : v0(_v0), v1(_v1), v2(_v2) {}
};

#endif