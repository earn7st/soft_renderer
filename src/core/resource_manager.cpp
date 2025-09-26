#include "resource_manager.h"

bool ResourceManager::initialize()
{
    return true;
}

void ResourceManager::load_mesh(const Mesh& mesh)
{
    meshes_.push_back(mesh);
}

void ResourceManager::load_material(const Material& material)
{
    materials_.push_back(material);
}

//void ResourceManager::load_model_by_file_name()