#include "scene.h"

bool Scene::initialize() 
{
    return true;
}

void Scene::add_model(const Model& model)
{
    models_.push_back(model);
}

const Camera& Scene::get_main_camera() const
{
    return main_camera_;
}
const std::vector<Model>& Scene::get_models() const
{
    return models_;
}

