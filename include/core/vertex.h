#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

#include "vector.hpp"
#include "matrix.hpp"

struct Vertex
{
    Pos3f pos;
    Vec3f normal;
    Coord2f texcoord;
    Color color;

    Vertex() = default;
    Vertex(float posX, float posY, float posZ) : pos(posX, posY, posZ) {}
    Vertex(const Vertex& v) : pos(v.pos), normal(v.normal), texcoord(v.texcoord){}
};

#endif