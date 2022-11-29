#include "CApp.hpp"

void CApp::OnRender()
{
    // SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0xFF);
    // SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
    SDL_Delay((1.0 / 60) * 1000);
}
