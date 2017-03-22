#ifndef GAME_H
#define GAME_H

#include <list>
#include <SDL2/SDL.h>

#include "../include/Character.h"
#include "../include/Hero.h"

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

        std::list<Character*> enemies;
        Hero *hero;

};

#endif // GAME_H
