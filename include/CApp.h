#ifndef _CAPP_H_
#define _CAPP_H_

#include <SDL.h>
#include "CDraw.h"

class CApp
{
private:
    int w_w = 700,
        w_h = 700;

    bool running;
    const char *WindowTitle = "Title";

    SDL_Window *Window;
    SDL_Surface *Surface;
    SDL_Renderer *Renderer;

public:
    CApp();

    int OnExecute();
    bool OnInit();
    void OnLoop();
    void OnEvent(SDL_Event *);
    void OnRender();
    void OnCleanup();
};

#endif // _CAPP_H_
