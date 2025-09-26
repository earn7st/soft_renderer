#include "engine.h"

Engine::Engine(uint32_t w, uint32_t h) 
: displayer_(), input_handler_(), resource_manager_(), scene_(), renderer_(), main_framebuffer_(w, h){}

int Engine::start_up()
{   
    // if(displayer_.start_up()) return -1;
    // if(input_handler_.start_up()) return -1;
    if(!resource_manager_.initialize()) return -1;
    std::cout << "Engine::start_up(): ResourceManager initialized successful!\n";
    if(!scene_.initialize()) return -1;
    std::cout << "Engine::start_up(): Scene initialized successful!\n";
    if(!renderer_.initialize(main_framebuffer_)) return -1;
    std::cout << "Engine::start_up(): Renderer initialized successful!\n";

    return 0;
}

void Engine::run()
{
    // Main Loop!
    bool running = true;

    while(running)
    {
        // Handle Input
        while(input_handler_.poll_event())
        {
            if(!input_handler_.handle_event())
            {
                running = false;
            }
        }
        displayer_.clear(0, 0, 0, 255);

        renderer_.render(scene_);

        displayer_.present(main_framebuffer_);
    }

}

int Engine::shut_down()
{

    return 0;
}