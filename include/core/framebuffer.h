#ifndef __FRAMEBUFFER_HPP__
#define __FRAMEBUFFER_HPP__

#include "vector.hpp"

class Framebuffer
{
public:
    Framebuffer(uint32_t w, uint32_t h);

    void resize(uint32_t w, uint32_t h);
    void clear();

    Color get_color(uint32_t index);
    void set_color(uint32_t index, const Color&);

private:
    std::vector<Color> color_buffer_;
    std::vector<double> depth_buffer_;
};

#endif