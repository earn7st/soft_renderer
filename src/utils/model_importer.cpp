#include "model_importer.h"

#include <sstream>
#include <fstream>
#include <map>
#include <tuple>

#include "mesh.h"
#include "vector.hpp"
#include "vertex.h"

struct VertexRef
{
    uint32_t pos_idx = -1;
    uint32_t normal_idx = -1;
    uint32_t texcoord_idx = -1;
    bool operator < (const VertexRef& other) const 
    {
        if(pos_idx != other.pos_idx) return pos_idx < other.pos_idx;
        if(normal_idx != other.normal_idx) return normal_idx < other.normal_idx;
        if(texcoord_idx != other.texcoord_idx) return texcoord_idx < other.texcoord_idx;
        return false;
    }
};

Model ObjImporter::import(const std::string& model_filepath, ResourceManager& rm)
{
    Model model;   

    std::ifstream file_stream(model_filepath);
    if(!file_stream.is_open())
    {
        std::cerr << "ObjImporter::import(): Model File Open Failed " << std::endl;
        return model; 
    }
   
    std::vector<Vec3f> pos;
    std::vector<Vec3f> normal;
    std::vector<Vec2f> texcoord;

    Mesh result_mesh;
    std::map<VertexRef, uint32_t> vertex_map;

    uint32_t num_faces = 0;

    std::string line;
    while(std::getline(file_stream, line))
    {
        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if(type == "v")
        {
            Vec3f tmp;
            ss >> tmp.x_ >> tmp.y_ >> tmp.z_;
            pos.push_back(tmp);
        } else if (type == "vn")
        {
            Vec3f tmp;
            ss >> tmp.x_ >> tmp.y_ >> tmp.z_;
            normal.push_back(tmp);
        } else if (type == "vt")
        {
            Vec2f tmp;
            ss >> tmp.x_ >> tmp.y_;
            texcoord.push_back(tmp);
        } else if (type == "f")
        {
            num_faces ++;
            for (int i = 0; i < 3; i ++)
            {
                std::string segment;
                ss >> segment;
                std::stringstream segment_ss(segment);
                
                std::string token;
                uint32_t idx;

                VertexRef vf;

                for (int k = 0; k < 3 && std::getline(segment_ss, token, '/'); ++k)
                {
                    if (!token.empty())
                    {
                        idx = std::stoi(token);
                        if (idx >= 1)
                        {
                            if (k == 0)
                            {
                                vf.pos_idx = idx - 1;
                            } else if (k == 1)
                            {
                                vf.texcoord_idx = idx - 1;
                            } else if (k == 2)
                            {
                                vf.normal_idx = idx - 1;
                            }
                        }
                    }
                }

                if (vertex_map.count(vf))
                {
                    result_mesh.indices.push_back(vertex_map[vf]);
                } else 
                {
                    Vertex new_vertex;

                    const Vec3f& raw_pos = pos[vf.pos_idx];
                    new_vertex.pos = Vec4f(raw_pos, 1.f);
                    if(vf.texcoord_idx != -1)
                    {
                        const Vec2f& raw_texcoord = texcoord[vf.texcoord_idx];
                        new_vertex.texcoord = raw_texcoord;
                    }
                    if(vf.normal_idx != -1)
                    {
                        const Vec3f& raw_normal = normal[vf.texcoord_idx];
                        new_vertex.normal = Vec4f(raw_normal, 0.f);
                    }
                    
                    result_mesh.vertices.push_back(new_vertex);

                    uint32_t new_index = result_mesh.vertices.size() - 1;
                    vertex_map[vf] = new_index;

                    result_mesh.indices.push_back(new_index);
                }
            }
        }
    }

    result_mesh.num_vertices = result_mesh.vertices.size();
    result_mesh.num_faces = num_faces;

    // store result_mesh data to resource manager
    rm.load_mesh(result_mesh);

    // set model's default one sub_mesh
    SubMesh sub_mesh0;
    sub_mesh0.offset = 0;
    sub_mesh0.size = result_mesh.indices.size();

    model.set_pMesh(rm.get_meshes().back());
    model.add_sub_mesh(sub_mesh0);

    return model;
}