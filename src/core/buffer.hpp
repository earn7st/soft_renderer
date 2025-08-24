#ifndef __BUFFER_HPP__
#define __BUFFER_HPP__

#include "vector.hpp"

enum class BufferType
{
    COLOR,
    DEPTH,
    SHADOW_MAP
};

struct BufferDesc
{
    BufferType type;
    uint32_t width;
    uint32_t height;
};

class IRenderBuffer
{
public:
    virtual ~IRenderBuffer() = default;
    virtual void clear();
    virtual void resize();
};

class ColorBuffer : public IRenderBuffer
{
public:
    ColorBuffer(uint32_t width, uint32_t height)
    {
        desc_.type = BufferType::COLOR;
        desc_.width = width;
        desc_.height = height;
    }

    void clear();
    void resize();

private:
    BufferDesc desc_;
    std::vector<Color> data_;

};

class DepthBuffer : public IRenderBuffer
{
private:
    BufferDesc desc_;
    std::vector<float> data_;
};

#endif