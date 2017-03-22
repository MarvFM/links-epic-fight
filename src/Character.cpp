#include "../include/Character.h"

#include <SDL2/SDL_ttf.h>

extern SDL_Renderer* RENDERER;
extern TTF_Font* NAME_FONT;

Character::Character(std::string name, int x, int y, int width, int height, int livePoints, int attackDamage)
: WorldObject(name, x, y, width, height)
{
  this->isAlive = true;
  this->livePoints = livePoints;
  this->attackDamage = attackDamage;
}

Character::Character(std::string name, int x, int y, int width, int height, int r, int g, int b, int livePoints, int attackDamage)
: WorldObject(name, x, y, width, height, r, g, b)
{
    this->isAlive = true;
    this->livePoints = livePoints;
    this->attackDamage = attackDamage;
}

void Character::move(int xDiff, int yDiff){
    this->xPos += xDiff;
    this->yPos += yDiff;
}

void Character::kill(){
    this->isAlive = false;
}
