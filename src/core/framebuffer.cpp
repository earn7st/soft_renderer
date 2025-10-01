#include "framebuffer.h"

Framebuffer::Framebuffer(uint32_t w, uint32_t h)
{
    initialized = true;
    width_ = w, height_ = h;
    color_buffer_.resize(w * h, RGBA(0));
    depth_buffer_.resize(w * h, 0.0f);
}

void Framebuffer::resize(uint32_t w, uint32_t h)
{
    width_ = w, height_ = h;
    color_buffer_.resize(w * h, RGBA(0));
    depth_buffer_.resize(w * h, 0.0f);
}

void Framebuffer::clear()
{
    std::fill(color_buffer_.begin(), color_buffer_.end(), RGBA(0));
    std::fill(depth_buffer_.begin(), depth_buffer_.end(), 0.0f);
}
const uint32_t* Framebuffer::get_pixels() const 
{
    return reinterpret_cast<const uint32_t*> (color_buffer_.data());
}

bool Framebuffer::set_color(uint32_t x, uint32_t y, RGBA color)
{
    if(x < width_ && y < height_)
    {
        color_buffer_[y * width_ + x] = color;
        return true;
    }
    return false;
}

void Framebuffer::print()
{
    std::cout << "Framebuffer Info:" << std::endl;
    std::cout << width_ << " " << height_ << std::endl;
}