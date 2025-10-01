#ifndef __RENDER_STATE_H__
#define __RENDER_STATE_H__

#include "framebuffer.h"

enum PolygonMode {
    POINT,
    LINE,
    FILL
};

enum ShaderType
{
    BLINN_PHONG,
    PBR
};

struct RenderState
{
    Framebuffer* pTarget_framebuffer;
    PolygonMode polygon_mode = LINE;

    ShaderType shader_type;
};
/*
参考 by deepseek
struct RenderState {
    // 混合状态
    BlendMode blendMode = BlendMode::None;
    glm::vec4 blendColor = glm::vec4(0.0f);
    
    // 深度测试状态
    DepthTestMode depthTest = DepthTestMode::Less;
    bool depthWrite = true;
    float depthRangeNear = 0.0f;
    float depthRangeFar = 1.0f;
    
    // 面剔除状态
    CullMode cullMode = CullMode::Back;
    FrontFace frontFace = FrontFace::CounterClockwise;
    
    // 多边形模式
    PolygonMode polygonMode = PolygonMode::Fill;
    
    // 模板测试状态
    bool stencilTest = false;
    StencilOp stencilOp = StencilOp::Keep;
    CompareFunc stencilFunc = CompareFunc::Always;
    uint32_t stencilRef = 0;
    uint32_t stencilMask = 0xFF;
    
    // 其他固定功能状态
    bool scissorTest = false;
    glm::ivec4 scissorRect = glm::ivec4(0);
};
*/

struct ClearStates
{
    bool color_flag = false;
    bool depth_flag = false;
    Vec3f clear_color = Vec3f(0.0f);
    double clear_depth = 0.0f;
};

#endif
