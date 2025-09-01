#include "renderer.h"

void Renderer::initialize() {}

void Renderer::attach_framebuffer(Framebuffer& fb)
{
    render_states_.pTarget_framebuffer = &fb;
}

void Renderer::draw_model(const Camera& camera, const Model& model)
{
    // Test
    Mesh* const mesh = model.get_sub_mesh(0).mesh;
    Material* const material = model.get_sub_mesh(0).material;

    update_per_model_uniform(model);
    // 应该在帧开始（begin_frame）的时候更新，记得改
    update_per_frame_uniform(camera);
    
    

}

void Renderer::draw_scene(const Camera& camera, const Scene& scene)
{
    
}

void Renderer::update_per_frame_uniform(const Camera& camera)
{
    per_frame_uniform_.view_matrix = lookAt(camera.get_pos(), camera.get_center(), camera.get_up());
    per_frame_uniform_.projection_matrix = perspective(camera.get_fovy(), camera.get_aspect(), camera.get_near_plane(), camera.get_far_plane());
    per_frame_uniform_.view_projection_matrix = per_frame_uniform_.view_matrix * per_frame_uniform_.projection_matrix;
    per_frame_uniform_.world_camera_position = camera.get_pos();
}

void Renderer::update_per_model_uniform(const Model& model)
{
    // per_model_uniform_.model_matrix;
}