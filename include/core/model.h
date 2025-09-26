#ifndef __MODEL_H__
#define __MODEL_H__

#include "mesh.h"
#include "transform.h"
#include "material.h"

struct SubMesh
{
    uint32_t mesh_index_offset = 0;
    uint32_t mesh_size = 0;
    uint32_t material_index = 0;
    Transform local_transform;
};

class Model
{
    
public:
    Model() = default;

    const Mesh* get_pMesh() const;
    const Mesh& get_mesh() const;
    const Material* get_pMaterial(uint32_t index) const;
    const Material& get_material(uint32_t index) const;

    const SubMesh& get_sub_mesh(uint32_t index) const;
    const std::vector<SubMesh>& get_sub_meshes() const;

    void add_sub_mesh(SubMesh&);

private:

    // Pointer to Data (in ResourceManager)
    Mesh* pMesh_;
    std::vector<Material*> pMaterials_;

    std::vector<SubMesh> sub_meshes_;
    Transform transform_;
};

#endif