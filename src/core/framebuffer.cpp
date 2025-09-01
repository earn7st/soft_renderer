#include "framebuffer.h"

Framebuffer::Framebuffer(uint32_t w, uint32_t h)
{
    color_buffer_.resize(w * h, Color(0));
    depth_buffer_.resize(w * h, 0.0f);
}

void Framebuffer::resize(uint32_t w, uint32_t h)
{
    color_buffer_.resize(w * h, Color(0));
    depth_buffer_.resize(w * h, 0.0f);
}

void Framebuffer::clear()
{
    std::fill(color_buffer_.begin(), color_buffer_.end(), Color(0));
    std::fill(depth_buffer_.begin(), depth_buffer_.end(), 0.0f);
}

Color Framebuffer::get_color(uint32_t index)
{
    return color_buffer_[index];
}

void Framebuffer::set_color(uint32_t index, const Color& col)
{
    color_buffer_[index] = col;
}