#pragma once
#include <SDL2/SDL.h>


class RenderWindow
{
public:
    RenderWindow(const char *p_title, int p_w, int p_h)
private:
    SDL_Window *window;
    SDL_Render* renderer;

};

