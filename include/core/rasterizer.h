#ifndef __RASTERIZER_H__
#define __RASTERIZER_H__

#include "vertex.h"
#include "shader.h"
#include "uniform.h"
#include "render_state.h"

class Rasterizer
{
public:
    void rasterize(const Varying& v0, const Varying& v1, const Varying& v2, const Shader& shader, const RenderState& render_state, const Uniform& uniform);
    void draw_line(const Vec2f& v0, const Vec2f& v1, const Shader& shader, const RenderState& render_state);
    Vec2f viewport_transform(const Vec4f&, uint32_t screen_width, uint32_t screen_height);

private:
    void _draw_line_bresenham(const Vec2f& v0, const Vec2f& v1, const Shader& shader, const RenderState& render_state);
    void _draw_line_DDA(const Vec2f& v0, const Vec2f& v1, const Shader& shader, const RenderState& render_state);
};



#endif