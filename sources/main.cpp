#define SDL_MAIN_HANDLED
#include "CApp.hpp"

int main(int argc, char **argv)
{
    CApp app;
    exit(app.OnExecute());
}
