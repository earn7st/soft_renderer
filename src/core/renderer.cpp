#include "renderer.h"
#include "shader.h"

uint32_t cnt = 0;

bool Renderer::initialize(Framebuffer& fb) 
{
    if(!attach_framebuffer(fb))
    {
        std::cerr << "Renderer::initialize(): Failed while calling attach_framebuffer()\n";
        return false;
    }
    return true;
}

bool Renderer::attach_framebuffer(Framebuffer& fb)
{
    if(fb.is_valid())
    {
        render_states_.pTarget_framebuffer = &fb;
        return true;
    }
    return false;
}

// render scene from "camera"'s perspective (camera = scene.get_main_camera())
void Renderer::render(const Scene& scene)
{
    const Camera& camera = scene.get_main_camera();
    update_per_frame_uniforms(camera);

    const std::vector<Model>& models = scene.get_models();
    for(auto it = models.begin(); it != models.end(); ++it)
    {
        const Model& model = *it;
        draw_model(model);
    }
    
}

void Renderer::draw_model(const Model& model)
{
    update_per_model_uniforms(model);

    const Mesh* pMesh = model.get_pMesh();

    const std::vector<SubMesh>& sub_meshes = model.get_sub_meshes();
    for(auto it = sub_meshes.begin(); it != sub_meshes.end(); ++it)
    {
        const SubMesh& sub_mesh = *it;
        update_per_sub_mesh_uniforms(sub_mesh);

        const Material* pMaterial = model.get_pMaterial(sub_mesh.material_index);
        draw_call(*pMesh, sub_mesh.mesh_index_offset, sub_mesh.mesh_size, *pMaterial);
    }

}

// Geometry Stage :
// Model & View Transformation
// Vertex Shading
// Projection Transformation
// Clipping
// Screen Mapping
// Rasterization Stage :
// Triangle Traversal
// Pixel/Fragment Shading
// Merging  
void Renderer::draw_call(const Mesh& mesh, uint32_t offset, uint32_t size, const Material& material)
{
    if(size % 3 != 0){
        std::cerr << "Renderer::draw_call(): Size cannot divided by 3!\n";
        return ;
    }
    for (int i = offset; i < offset + size; ++i)
    {
        int tri_cnt = 3;
        while(--tri_cnt)
        {
            Vec4f pos = Vec4f(mesh.vertices[mesh.vertex_indices[i]], 1.0f);
            Vec4f normal = Vec4f(mesh.normals[mesh.normal_indices[i]], 1.0f);
            Vec2f texcoord = mesh.texcoords[mesh.texcoord_indices[i]];
            Vertex v(pos, normal, texcoord);

        }
    }
}

void Renderer::update_per_frame_uniforms(const Camera& camera)
{
    uniforms_.view_matrix = lookAt(camera.get_pos(), camera.get_center(), camera.get_up());
    uniforms_.projection_matrix = perspective(camera.get_fovy(), camera.get_aspect(), camera.get_near_plane(), camera.get_far_plane());
    uniforms_.VP_matrix = uniforms_.view_matrix * uniforms_.projection_matrix;
    uniforms_.world_camera_position = camera.get_pos();
}

// model transform
void Renderer::update_per_model_uniforms(const Model& model)
{
    // TODO
    uniforms_.model_matrix = Matrix::Identity;
    uniforms_.MVP_matrix = uniforms_.model_matrix * uniforms_.VP_matrix;
}

// sub-mesh local transform
void Renderer::update_per_sub_mesh_uniforms(const SubMesh& sub_mesh)
{
    // TODO
    uniforms_.sub_mesh_matrix = Matrix::Identity;
    //uniforms_.MVP_matrix = uniforms_.sub_mesh_matrix * uniforms_.MVP_matrix;
}