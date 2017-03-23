#ifndef Character_H
#define Character_H

#include <SDL2/SDL.h>
#include <string>

#include "../include/WorldObject.h"

class Character : public WorldObject
{
    // methods
    public:
        Character(std::string name, int x, int y, int width, int height, int livePoints, int attackDamage);
        Character(std::string name, int x, int y, int width, int height, int r, int g, int b, int livePoints, int attackDamage);
        ~Character();

        bool getIsAlive(){return isAlive;}
        int getRandomSingleCoordinate();
        void move(int xDiff, int yDiff);
        void kill();

    protected:
        bool isAlive;
        int livePoints;
        int attackDamage;

};

#endif // Character_H
