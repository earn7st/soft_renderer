#ifndef __MODEL_H__
#define __MODEL_H__

#include "mesh.h"
#include "transform.h"

#include "material.h"

struct SubMesh
{
    Mesh* mesh = nullptr;
    Material* material = nullptr;
    Transform local_transform;
};

class Model
{
public:
    Model() = default;

    const SubMesh& get_sub_mesh(uint32_t index) const;

private:
    std::vector<SubMesh> sub_meshes_;
    
};

#endif