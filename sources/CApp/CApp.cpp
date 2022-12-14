#include "CApp.hpp"

CApp::CApp()
{
    Window = nullptr;
    Surface = nullptr;

    w_w = 800;
    w_h = 600;

    running = true;
}

int CApp::OnExecute()
{
    if (OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while (running)
    {
        while (SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }
    OnCleanup();
    return 0;
}
