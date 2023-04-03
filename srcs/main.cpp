#include <iostream>
#include<SDL2/SDL.h>

#include "RenderWindow.hpp"


int main (int argc, char *argv[])
{
    

    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
        std::cout << "SDL could initialize! SDL_ERROR: " << SDL_GetError() << "\n";


    RenderWindow window("game",1280,720);

    bool running = true;

    SDL_Event event;
    while (running)
        while(SDL_PollEvent) if(event.type == SDL_QUIT) running = false;

    window.clean_up();
    SDL_Quit();

    return 0;
}
