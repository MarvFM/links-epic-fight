#include "../include/Game.h"

#include "../include/Rect.h"

Game::Game()
{
    this->gameWindow = SDL_CreateWindow("The Legend of Zelda: Links epic Fight", 100, 100, 1200, 900, SDL_WINDOW_SHOWN);
    this->gameSurface = SDL_GetWindowSurface(this->gameWindow);
    this->gameRenderer = SDL_CreateRenderer(this->gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    this->quit = false;

    this->hero = new Rect(std::string("Link"), 50, 50, 20, 20, 0, 0, 255);
    Rect *enemy = new Rect(std::string("Ganon"), 400, 400, 20, 20, 255, 0, 0);
    Rect *enemy2 = new Rect(std::string("Ganon2"), 500, 500, 20, 20, 255, 0, 0);
    this->enemies.push_front(enemy);
    this->enemies.push_front(enemy2);
}

void Game::Run()
{
    SDL_Event e;
    while(!this->quit){
        SDL_SetRenderDrawColor(this->gameRenderer, 0, 255, 0, 255);
        SDL_RenderClear(this->gameRenderer);
        int speed = 2;

        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT) quit = true;
        }

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_LSHIFT]) speed *= 2;
        if(state[SDL_SCANCODE_W]) hero->move(0, -speed);
        if(state[SDL_SCANCODE_A]) hero->move(-speed,0);
        if(state[SDL_SCANCODE_S]) hero->move(0,speed);
        if(state[SDL_SCANCODE_D]) hero->move(speed,0);

        this->CheckCollisions();
        this->DrawWindow();
    }
}

void Game::DrawWindow()
{
    for(Rect *enemy : enemies){
        if(enemy->isAlive) enemy->draw(this->gameRenderer);
    }
    this->hero->draw(this->gameRenderer);
    SDL_RenderPresent(this->gameRenderer);
    return;
}

void Game::CheckCollisions()
{
    for(Rect *enemy : enemies){
        if(this->hero->collides(enemy)) enemy->kill();
    }
}
