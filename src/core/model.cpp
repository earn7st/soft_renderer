#include "model.h"

const SubMesh& Model::get_sub_mesh(uint32_t index) const 
{
    assert(index < sub_meshes_.size() &&
            "Index out of sub_meshes_ bounds");
    return sub_meshes_[index];
}