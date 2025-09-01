#ifndef __MATERIAL_H__
#define __MATERIAL_H__

#include "vector.hpp"

class Material
{
public:
    Material() = default;
};

class BlinnPhongMaterial : public Material
{
public:
    BlinnPhongMaterial() = default;  

private:
    Vec3f ambient_;
    Vec3f diffuse_;
    Vec3f specular_;
    float shininess_;
};

#endif