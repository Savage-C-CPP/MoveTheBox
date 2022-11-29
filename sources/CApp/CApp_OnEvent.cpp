#include "CApp.hpp"

void CApp::OnEvent(SDL_Event *Event)
{
    if (Event->type == SDL_QUIT)
    {
        running = false;
    }
    if (Event->type == SDL_KEYDOWN)
        switch (Event->key.keysym.sym)
        {
        case SDLK_ESCAPE:
            running = false;
            break;

        case SDLK_w:
            break;

        case SDLK_s:
            break;

        case SDLK_a:
            break;

        case SDLK_d:
            break;

        case SDLK_0:
        case SDLK_KP_0:
            break;

        case SDLK_PLUS:
        case SDLK_KP_PLUS:
            break;

        case SDLK_MINUS:
        case SDLK_KP_MINUS:
            break;

        case SDLK_UP:
            break;

        case SDLK_DOWN:
            break;

        case SDLK_RIGHT:
            break;

        case SDLK_LEFT:
            break;
        }
}
