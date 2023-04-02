#include <iostream>
#include<SDL2/SDL.h>

#include "RenderWindow.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main (int argc, char *argv[])
{
    
    SDL_Window *window = NULL;
    SDL_Surface *screen_surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
        std::cout << "SDL could initialize! SDL_ERROR: " << SDL_GetError() << "\n";


    RenderWindow window("game",1280,720);
    return 0;
}
