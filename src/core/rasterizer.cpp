#include "rasterizer.h"

void Rasterizer::rasterize(const Varying& v0, const Varying& v1, const Varying& v2, const Shader& shader, const RenderState& render_state, const Uniform& uniform)
{
    // Perspective Division
    Vec4f v0_ndc_pos = v0.clip_pos / v0.clip_pos.w_;
    Vec4f v1_ndc_pos = v1.clip_pos / v1.clip_pos.w_;
    Vec4f v2_ndc_pos = v2.clip_pos / v2.clip_pos.w_;

    // std::cout << "ndc pos: \n";
    // std::cout << v0_ndc_pos << " " << v1_ndc_pos << " " << v2_ndc_pos << std::endl;

    // Viewport Transform
    Vec2f v0_screen_pos = viewport_transform(uniform.viewport_matrix, v0_ndc_pos);
    Vec2f v1_screen_pos = viewport_transform(uniform.viewport_matrix, v1_ndc_pos);
    Vec2f v2_screen_pos = viewport_transform(uniform.viewport_matrix, v2_ndc_pos);

    // std::cout << "screen pos: \n";
    // std::cout << v0_screen_pos << " " << v1_screen_pos << " " << v2_screen_pos << std::endl;

    // LINE
    if (render_state.polygon_mode == LINE)
    {
        draw_line(v0_screen_pos, v1_screen_pos, shader, render_state);
        draw_line(v1_screen_pos, v2_screen_pos, shader, render_state);
        draw_line(v2_screen_pos, v0_screen_pos, shader, render_state);

    } else if (render_state.polygon_mode == FILL)
    {

    }
    // FILL
    // uint32_t min_x = std::max((uint32_t)0, (uint32_t)std::floor(std::min({v0_screen_pos.x_, v1_screen_pos.x_, v2_screen_pos.x_})));
    // uint32_t min_y = std::max((uint32_t)0, (uint32_t)std::floor(std::min({v0_screen_pos.y_, v1_screen_pos.y_, v2_screen_pos.y_})));
    // uint32_t max_x = std::min(uniform.screen_width - 1, (uint32_t)std::ceil(std::max({v0_screen_pos.x_, v1_screen_pos.x_, v2_screen_pos.x_})));
    // uint32_t max_y = std::min(uniform.screen_height - 1, (uint32_t)std::ceil(std::max({v0_screen_pos.y_, v1_screen_pos.y_, v2_screen_pos.y_})));

    // for(uint32_t x = min_x; x < max_x; ++x)
    // {
    //     for(uint32_t y = min_y; y < max_y; ++y)
    //     {
    //         float cx = x + 0.5;
    //         float cy = y + 0.5;
            
    //     }
    // }

    return ;
}

Vec2f Rasterizer::viewport_transform(const Matrix& mat, const Vec4f& v)
{
    Vec4f tmp = mat * v;
    return Vec2f(tmp.x_, tmp.y_);
}

void Rasterizer::draw_line(const Vec2f& v0, const Vec2f& v1, const Shader& shader, const RenderState& render_state)
{
    _draw_line_bresenham(v0, v1, shader, render_state);
    //_draw_line_DDA(v0, v1, shader, render_state);
    return ;
}

void Rasterizer::_draw_line_bresenham(const Vec2f& v0, const Vec2f& v1, const Shader& shader, const RenderState& render_state)
{

    int width = render_state.pTarget_framebuffer->get_width();
    int height = render_state.pTarget_framebuffer->get_height();
    Framebuffer* fb = render_state.pTarget_framebuffer;

    FragmentIn dummy_fragin = FragmentIn();
    Uniform dummy_uniform = Uniform();

    int x0 = int(v0.x_);
    int y0 = int(v0.y_);
    int x1 = int(v1.x_);
    int y1 = int(v1.y_);
    if(x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    int sy = y0 < y1 ? 1 : -1;
    int x = x0, y = y0;
    int cnt = 0;
    int dy = y1 - y0;
    int dx = x1 - x0;

    if(abs(y1 - y0) < abs(x1 - x0)){
        while(x < std::min(x1, width - 1))
        {
            x++;
            cnt += sy * 2 * dy;
            if(cnt >= 2 * dx)
            {
                cnt -= 2 * dx;
            }
            if(cnt >= dx)
            {
                y += sy;
            }
            RGBA color = shader.execute_fragment_shader(dummy_fragin, dummy_uniform);
            fb->set_color(x, y, color);
        }
    } else {
    }

    return ;
}
