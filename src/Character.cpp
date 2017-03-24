#include "../include/Character.h"

#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <stdlib.h>

extern SDL_Renderer* RENDERER;
extern TTF_Font* NAME_FONT;

Character::Character(std::string name, int x, int y, int width, int height, int r, int g, int b, int livePoints, int attackDamage)
: WorldObject(name, x, y, width, height, r, g, b)
{
    this->isAlive = true;
    this->livePoints = livePoints;
    this->attackDamage = attackDamage;
}

Character::~Character()
{
    
}

int Character::getRandomSingleCoordinate()
{
    time_t t;
    time(&t);
    srand((unsigned int)t);
    int randomMove = rand() % 5 - 2;

    return randomMove;
}

void Character::move(int xDiff, int yDiff){
    this->xPos += xDiff;
    this->yPos += yDiff;
}

void Character::kill(){
    this->isAlive = false;
}
