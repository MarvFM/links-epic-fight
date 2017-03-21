#ifndef GAME_H
#define GAME_H

#include <list>
#include <SDL2/SDL.h>
#include "Rect.h"

class Game
{
    public:
        Game();
        void Run();
    protected:
    private:
        void DrawWindow();
        void CheckCollisions();

        SDL_Window *gameWindow;
        SDL_Surface *gameSurface;
        SDL_Renderer *gameRenderer;
        bool quit;
        std::list<Rect> enemies;
        Rect *hero;

};

#endif // GAME_H
