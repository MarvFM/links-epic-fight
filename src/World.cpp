#include "../include/World.h"
#include <iostream>

#include "../include/Hero.h"
#include "../include/Bokblin.h"
#include "../include/Character.h"

extern SDL_Renderer* RENDERER;

World::World()
{
    this->hero = new Hero(50, 50);
    Character *enemy = new Bokblin(100, 100);
    Character *enemy2 = new Bokblin(200, 200);
    this->enemies.push_front(enemy);
    this->enemies.push_front(enemy2);

}

World::~World()
{
    if(this->hero != NULL) delete this->hero;
    if(this->worldBorder != NULL) delete this->worldBorder;
    for(Character* enemy : this->enemies){
        if(enemy != NULL) delete enemy;
    }
    for(WorldObject* obj : this->objects){
        if(obj != NULL) delete obj;
    }
    return;
}

void World::drawWorld(int xOffset, int yOffset)
{
    SDL_SetRenderDrawColor(RENDERER, 0, 255, 0, 255);
    return;
}

void World::drawCharacters(int xOffset, int yOffset)
{
    std::cout << enemies.size() << std::endl;
    for(Character* enemy : this->enemies){
        if(enemy->getIsAlive()) enemy->draw(xOffset, yOffset);
    }
    this->hero->draw(xOffset, yOffset);
    return;
}

void World::drawObjects(int xOffset, int yOffset)
{
    for(WorldObject* obj : this->objects){
        obj->draw(xOffset, yOffset);
    }
    return;
}

void World::draw(int xOffset, int yOffset)
{
    SDL_RenderClear(RENDERER);
    this->drawWorld(xOffset, yOffset);
    this->drawObjects(xOffset, yOffset);
    this->drawCharacters(xOffset, yOffset);
    return;
}

void World::setHero(Hero* hero)
{
    if(this->hero != NULL) delete this->hero;
    this->hero = hero;
    return;
}
