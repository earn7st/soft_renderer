#ifndef __GEOMETRY_HPP__
#define __GEOMETRY_HPP__

#include "vector.hpp"

bool inside_triangle(const Vec2f& p, const Vec2f& v_a, const Vec2f& v_b, const Vec2f& v_c)
{
    float max_y = std::max({v_a.y_, v_b.y_, v_c.y_});
    Vec2f e_ab = v_b - v_a;
    Vec2f e_bc = v_c - v_b;
    Vec2f e_ca = v_a - v_c;
    Vec2f ap = p - v_a;
    Vec2f bp = p - v_b;
    Vec2f cp = p - v_c;

    // TODO: test top-left rule correct
    float cross_product_a = cross(e_ab, ap);
    if(cross_product_a == 0) 
        if(e_ab.y_ < 0 || (e_ab.y_ == 0 && max_y == v_a.y_))
            return true;
    float cross_product_b = cross(e_bc, bp);
    if(cross_product_b == 0) 
        if(e_bc.y_ < 0 || (e_bc.y_ == 0 && max_y == v_b.y_))
            return true;
    float cross_product_c = cross(e_ca, cp);
    if(cross_product_c == 0) 
        if(e_ca.y_ < 0 || (e_ca.y_ == 0 && max_y == v_c.y_))
            return true;

    bool x_a = cross_product_a < 0 ? true : false;
    bool x_b = cross_product_b < 0 ? true : false;
    bool x_c = cross_product_c < 0 ? true : false;

    return ((x_a ^ x_b) == 0 && (x_b ^ x_c) == 0);
}

Vec3f compute_barycentric_coord(const Vec2f&, const Vec2f&, const Vec2f&)
{
    // TODO
}

#endif