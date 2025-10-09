#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <functional>

#include "mesh.h"
#include "framebuffer.h"
#include "camera.h"
#include "scene.h"
#include "render_state.h"
#include "uniform.h"
#include "shader.h"
#include "vertex.h"
#include "rasterizer.h"

class Renderer
{
public:
    Renderer() = default;

    bool initialize(Framebuffer&);
    bool attach_framebuffer(Framebuffer&);

    void render(const Scene&);
    void draw_model(const Model&);   // For Test
    void draw_sub_mesh(const SubMesh&); // For Test

    void update_per_frame_uniform(const Scene&);   // call when frame start
    void update_per_model_uniform(const Model&);    // call when drawing model
    void update_per_sub_mesh_uniform(const SubMesh&);

    // pipeline
    void draw_call(const Mesh& mesh, uint32_t offset, uint32_t size);

private:
    RenderState render_state_;
    Framebuffer* fb_;
    Uniform uniform_;
    Shader shader_;
    Rasterizer rasterizer_;
};

#endif