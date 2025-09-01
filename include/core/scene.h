#ifndef __SCENE_H__
#define __SCENE_H__

#include "model.h"
#include "material.h"

#include "resource_manager.h"

class Scene
{
public:
    Scene() = default;

    void add_model(const Model& model);

private:
    std::vector<Model> models_;
};

#endif