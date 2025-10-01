#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "displayer.h"
#include "input_handler.h"
#include "resource_manager.h"
#include "scene.h"
#include "renderer.h"

class Engine
{
public:
    Engine(uint32_t w = DEFAULT_DISPLAYER_WIDTH, uint32_t h = DEFAULT_DISPLAYER_HEIGHT);
    int start_up(const std::string& model_filepath);
    void run();
    int shut_down();

private:
    Displayer displayer_;
    InputHandler input_handler_;
    ResourceManager resource_manager_;
    Scene scene_;
    Renderer renderer_;

    Framebuffer main_framebuffer_;
};

#endif