#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <functional>

#include "mesh.h"
#include "framebuffer.h"
#include "camera.h"
#include "scene.h"
#include "render_states.h"
#include "uniforms.h"
#include "shader.h"
#include "vertex.h"

class Renderer
{
public:
    Renderer() = default;

    bool initialize(Framebuffer&);
    bool attach_framebuffer(Framebuffer&);

    void render(const Scene&);
    void draw_model(const Model&);   // For Test
    void draw_sub_mesh(const SubMesh&); // For Test

    void update_per_frame_uniforms(const Camera&);   // call when frame start
    void update_per_model_uniforms(const Model&);    // call when drawing model
    void update_per_sub_mesh_uniforms(const SubMesh&);

    // pipeline
    void draw_call(const Mesh& mesh, uint32_t offset, uint32_t size, const Material& material);
    void rasterize();


private:
    RenderStates render_states_;
    Uniforms uniforms_;
    Shader shader_;
};

#endif