#include "CApp.h"

bool CApp::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;

    Window = SDL_CreateWindow(WindowTitle,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              w_w, w_h,
                              SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL);
    if (Window == nullptr)
        return false;

    Surface = SDL_GetWindowSurface(Window);

    if (Surface == nullptr)
        return false;

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    // Black background
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(Renderer);
    return true;
}
