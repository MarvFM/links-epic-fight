#ifndef GAME_H
#define GAME_H

#include <list>
#include <SDL2/SDL.h>

#include "../include/Character.h"
#include "../include/Hero.h"
#include "../include/World.h"

class Game
{
    // public methods
    public:
        Game();
        //runs the main loop of the Game
        void Run();
    // private methods
    private:
        // check for all objects wether hero collides to enemies
        // and kill them if he do
        // TODO rework: outsourcing to specific objects
        void checkCollisions();
        // calculates x and y offset for an objects,
        // so that this object is in the center of the window
        void calculateOffsets(WorldObject* obj, int* result);

    // private properties
    private:
        // property for leaving the main loop
        bool quit;
        // pointer for the main World of the game
        World* world;
};

#endif // GAME_H
