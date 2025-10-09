#include "displayer.h"

Displayer::Displayer()
{
    init_SDL();
}

Displayer::Displayer(uint32_t w, uint32_t h) : width_(w), height_(h)
{
    init_SDL();
}

Displayer::~Displayer()
{
    if (texture_) {
        SDL_DestroyTexture(texture_);
    }
    if (renderer_) {
        SDL_DestroyRenderer(renderer_);
    }
    if (window_) {
        SDL_DestroyWindow(window_);
    }
    SDL_Quit();
}

int Displayer::init_SDL()
{
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL Init Failed: %s", SDL_GetError());
        return -1;
    }

    window_ = SDL_CreateWindow("SCRNE_Displayer", width_, height_, SDL_WINDOW_RESIZABLE);
    if (!window_)
    {
        SDL_Log("SDL Create Window Failed: %s\n", SDL_GetError());
        return -1;
    }
    SDL_SetWindowPosition(window_, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    renderer_ = SDL_CreateRenderer(window_, nullptr);
    if (!renderer_) {
        SDL_Log("SDL Create Renderer Failed: %s\n", SDL_GetError());
        return -1;
    }
    
    texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STREAMING, width_, height_);
    if (!texture_)
    {
        SDL_Log("SDL Create Texture Failed: %s\n", SDL_GetError());
        return -1;
    }
    
    return 0;
}

bool Displayer::present(const Framebuffer& fb)
{
    if(!check_framebuffer_size(fb))
    {
        std::cerr << "Displayer::present(): Main Framebuffer size doesn't match displayer's size\n";
        return false;
    }
    const uint32_t* pixels = fb.get_pixels();
    if (!pixels || !texture_ || !renderer_) {
        SDL_Log("Displayer::present(): SDL::Invalid pixel data or SDL objects.");
        return false;
    }

    SDL_UpdateTexture(texture_, nullptr, pixels, fb.get_width() * sizeof(uint32_t));
    SDL_RenderTexture(renderer_, texture_, nullptr, nullptr);
    SDL_RenderPresent(renderer_);

    return true;
}

bool Displayer::check_framebuffer_size(const Framebuffer& fb)
{
    return (width_ == fb.get_width() && height_ == fb.get_height());
}