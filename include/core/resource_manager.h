#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include <string>

#include "mesh.h"
#include "material.h"

class ResourceManager
{
public:
    ResourceManager() = default;

    bool initialize();

    void load_mesh(const Mesh& mesh);
    void load_material(const Material& material);
    
    void load_model_by_file_name(const std::string& file_name);

private:
    std::vector<Mesh> meshes_;
    std::vector<Material> materials_;
};

#endif