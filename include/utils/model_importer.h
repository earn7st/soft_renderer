#ifndef __MODEL_IMPORTER_HPP__
#define __MODEL_IMPORTER_HPP__

#include "model.h"
#include "resource_manager.h"

class IModelImporter
{
public:
    IModelImporter() = default;
    virtual ~IModelImporter() = default;

    virtual Model import(const std::string& model_filepath, ResourceManager&) = 0;
};

class ObjImporter : public IModelImporter
{
public:
    virtual Model import(const std::string& model_filepath, ResourceManager&) override;
};

// class FbxImporter : publid IModelImporter
// {
// public:
//     virtual Model import(const std::string& model_filepath);
// };

#endif