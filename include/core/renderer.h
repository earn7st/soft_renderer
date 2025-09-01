#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "mesh.h"
#include "framebuffer.h"
#include "camera.h"
#include "scene.h"
#include "render_states.h"
#include "uniforms.h"

class Renderer
{
public:
    Renderer() = default;

    void initialize();

    void attach_framebuffer(Framebuffer&);

    void draw_sub_mesh(const Camera&, const SubMesh&); // For Test
    void draw_model(const Camera&, const Model&);   // For Test 
    void draw_scene(const Camera&, const Scene&);

    // TODO 帧的概念
    /*
    void begin_frame(float deltaTime) {
        // 更新时间
        m_time += deltaTime;
        
        // 更新PerFrame Uniforms（每帧一次）
        update_per_frame_uniforms(deltaTime);
    }
    */
    void update_per_model_uniform(const Model&);    // 每个模型渲染前调用
    void update_per_frame_uniform(const Camera&);   // 每帧开始时调用

    void rasterize();


private:

    RenderStates render_states_;

    PerFrameUniform per_frame_uniform_;
    PerModelUniform per_model_uniform_;
};

#endif