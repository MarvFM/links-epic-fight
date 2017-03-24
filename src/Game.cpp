#include <iostream>

#include "../include/Game.h"
#include "../include/Character.h"
#include "../include/Timer.h"
#include "../include/Hero.h"
#include "../include/Bokblin.h"
#include "../include/World.h"


extern SDL_Renderer* RENDERER;
extern Timer* TIMER;
extern int SCREEN_HEIGHT;
extern int SCREEN_WIDTH;

Game::Game()
{
    this->quit = false;
    this->world = new World();
}

void Game::Run()
{
    // Main Loop
    SDL_Event e;
    while(!this->quit){
        TIMER->Update();
        int speed = 200 * TIMER->getElapsed();

        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT) quit = true;
        }

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_LSHIFT]) speed *= 2;
        if(state[SDL_SCANCODE_W]) this->world->getHero()->move(0, -speed);
        if(state[SDL_SCANCODE_A]) this->world->getHero()->move(-speed,0);
        if(state[SDL_SCANCODE_S]) this->world->getHero()->move(0,speed);
        if(state[SDL_SCANCODE_D]) this->world->getHero()->move(speed,0);

        /*for(Character *enemy : enemies){

            enemy->move(enemy->getRandomSingleCoordinate(),enemy->getRandomSingleCoordinate());
        }*/
        this->checkCollisions();
        int offsets[2] = {};
        this->calculateOffsets(this->world->getHero(), offsets);
        this->world->draw(offsets[0], offsets[1]);

        SDL_RenderPresent(RENDERER);
    }
}


void Game::checkCollisions()
{
    for(Character *enemy : this->world->getEnemies()){
        if(this->world->getHero()->collides(enemy)) enemy->kill();
    }
}

/*  calculates x and y offset for an objects,
    so that this object is in the center of the window
    1. arg: the object that will be the center
    2. arg: int array of size 2 for the result
      array-slot 1: xOffset
      array-slot 2: yOffset
*/
void Game::calculateOffsets(WorldObject* obj, int* result)
{
    int centerXPos = (SCREEN_WIDTH / 2) - (obj->getWidth() / 2);
    int centerYPos = (SCREEN_HEIGHT / 2) - (obj->getHeight() / 2);
    result[0] = centerXPos - obj->getXPos();
    result[1] = centerYPos - obj->getYPos();
    return;
}
