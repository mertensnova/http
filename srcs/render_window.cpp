#include <SDL2/SDL.h>
#include <iostream>
#include "RenderWindow.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

RenderWindow::RenderWindow(const char* p_title,int p_w,int p_h)
    :window(NULL),renderer(NULL)
{
    
    window = SDL_CreateWindow("Game",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN);
        
    if(window == NULL) std::cout << "Window could not be created! SDL_ERROR: " << SDL_GetError() << "\n";

    renderer = SDL_CreateRenderer(window,-1,NULL);

}

void RenderWindow::clean_up()
{
    SDL_DestroyWindow(window);
}
