#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>
#include <list>

#include "../include/WorldObject.h"
#include "../include/Character.h"
#include "../include/Hero.h"

class World
{
    //public methods
    public:
        World();
        ~World();
        void draw(int xOffset = 0, int yOffset = 0);
        //getter methods
        Hero* getHero(){return this->hero;}
        std::list<Character*> getEnemies(){return this->enemies;}
        std::list<WorldObject*> getObjects(){return this->objects;}
        //setter methods
        void addEnemy(Character* enemy){this->enemies.push_front(enemy); return;}
        void addObject(WorldObject* obj){this->objects.push_front(obj); return;}
        //old hero will be deleted
        void setHero(Hero* hero);
    //private methods
    private:
        void drawWorld(int xOffset = 0, int yOffset = 0);
        void drawCharacters(int xOffset = 0, int yOffset = 0);
        void drawObjects(int xOffset = 0, int yOffset = 0);
    //private variables
    private:
        WorldObject* worldBorder;
        std::list<Character*> enemies;
        std::list<WorldObject*> objects;
        Hero* hero;
};

#endif // TIMER_H
