#include "engine.h"

#include "model_importer.h"

Engine::Engine(uint32_t w, uint32_t h) 
: displayer_(), input_handler_(), resource_manager_(), scene_(), renderer_(), main_framebuffer_(w, h){}

int Engine::start_up(const std::string& model_filepath)
{   
    // if(displayer_.start_up()) return -1;
    // if(input_handler_.start_up()) return -1;
    if(!resource_manager_.initialize())
    {
        std::cout << "Engine::start_up(): ResourceManager initialize failed!\n";
        return -1;
    }
    if(!scene_.initialize()) 
    {
        std::cout << "Engine::start_up(): Scene initialize failed!\n";
        return -1;   
    }
    if(!renderer_.initialize(main_framebuffer_))
    {
        std::cerr << "Engine::start_up(): Renderer initialize failed!\n";
        return -1;
    }
    
    // TODO: Get file extension to specify importer type
    std::unique_ptr<IModelImporter> importer;
    importer = std::make_unique<ObjImporter>();
    Model model = importer->import(model_filepath, resource_manager_);
    scene_.add_model(model);
    //model.print();

    return 0;
}

void Engine::run()
{
    int frame_cnt = 1;
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
        displayer_.clear(16, 0, 16, 255);

        if(frame_cnt > 0) 
        {
            frame_cnt--;
            renderer_.render(scene_);
        }

        displayer_.present(main_framebuffer_);
    }

}

int Engine::shut_down()
{

    return 0;
}