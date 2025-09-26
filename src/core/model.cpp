#include "model.h"

const Mesh* Model::get_pMesh() const 
{
    return pMesh_;
}

const Mesh& Model::get_mesh() const 
{
    return *pMesh_;
}

const Material* Model::get_pMaterial(uint32_t i) const
{
    assert(i < pMaterials_.size() && "Model::get_pMaterial() : Model Material Index Out of Bound!!");
    return pMaterials_[i];
}

const Material& Model::get_material(uint32_t i) const
{
    assert(i < pMaterials_.size() && "Model::get_material() : Model Material Index Out of Bound!!");
    return *pMaterials_[i];
}

const SubMesh& Model::get_sub_mesh(uint32_t index) const 
{
    assert(index < sub_meshes_.size() &&
            "Model::get_sub_mesh() : Index out of sub_meshes_ bounds");
    return sub_meshes_[index];
}

const std::vector<SubMesh>& Model::get_sub_meshes() const
{
    return sub_meshes_;
}

void Model::add_sub_mesh(SubMesh& submesh)
{
    sub_meshes_.push_back(submesh);
}