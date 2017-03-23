
#include "../include/Game.h"
#include "../include/Character.h"
#include "../include/Timer.h"
#include "../include/Hero.h"
#include "../include/Bokblin.h"

extern SDL_Renderer* RENDERER;
extern Timer* TIMER;

Game::Game()
{
    this->quit = false;

    this->hero = new Hero(50, 50);
    Character *enemy = new Bokblin(400, 400);
    Character *enemy2 = new Bokblin(500, 500);
    this->enemies.push_front(enemy);
    this->enemies.push_front(enemy2);
}

void Game::Run()
{
    // Main Loop
    SDL_Event e;
    while(!this->quit){
        SDL_SetRenderDrawColor(RENDERER, 0, 255, 0, 255);
        SDL_RenderClear(RENDERER);
        TIMER->Update();
        int speed = 200 * TIMER->getElapsed();

        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT) quit = true;
        }

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_LSHIFT]) speed *= 2;
        if(state[SDL_SCANCODE_W]) hero->move(0, -speed);
        if(state[SDL_SCANCODE_A]) hero->move(-speed,0);
        if(state[SDL_SCANCODE_S]) hero->move(0,speed);
        if(state[SDL_SCANCODE_D]) hero->move(speed,0);

        for(Character *enemy : enemies){

            enemy->move(enemy->getRandomSingleCoordinate(),enemy->getRandomSingleCoordinate());
        }
        this->checkCollisions();
        this->draw();
    }
}

void Game::draw()
{
    for(Character *enemy : enemies){
        if(enemy->getIsAlive()) enemy->draw();
    }
    this->hero->draw();
    SDL_RenderPresent(RENDERER);
    return;
}

void Game::checkCollisions()
{
    for(Character *enemy : enemies){
        if(this->hero->collides(enemy)) enemy->kill();
    }
}
