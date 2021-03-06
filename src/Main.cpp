#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>   // sudo apt-get install libsdl2-ttf-dev
#include <SDL2/SDL_image.h> // sudo apt-get install libsdl2-image-dev

#include <string>

#include "../include/Game.h"
#include "../include/Timer.h"

// need the renderer in a lot of places
SDL_Renderer* RENDERER;
Timer* TIMER;
int SCREEN_HEIGHT = 600;
int SCREEN_WIDTH = 1200;
// define font for names globally
TTF_Font* NAME_FONT;

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);
    NAME_FONT = TTF_OpenFont("assets/sans.ttf", 24);
    SDL_Window *gameWindow = SDL_CreateWindow("The Legend of Zelda: Links epic Fight", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //SDL_Surface *gameSurface = SDL_GetWindowSurface(gameWindow);
    RENDERER = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    TIMER = new Timer();

    Game game = Game();
    game.Run();

    TTF_Quit();
    SDL_Quit();
    return 0;
}
