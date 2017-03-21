#ifndef GAME_H
#define GAME_H

#include <list>
#include <SDL2/SDL.h>
#include "Rect.h"

class Game
{
    // methods
    public:
        Game();
        void Run();

    private:
        void draw();
        void checkCollisions();

    // properties
    private:
        bool quit;

        std::list<Rect*> enemies;
        Rect *hero;

};

#endif // GAME_H
