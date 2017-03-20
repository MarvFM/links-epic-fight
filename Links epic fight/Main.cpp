#include <SDL2/SDL.h>
#include <string>

#include "Rect.h"

int main(){
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("The Legend of Zelda: Links epic Fight", 100, 100, 1200, 900, SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);
    SDL_Renderer *r = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);

    SDL_Event e;
    bool quit = false;

    Rect hero = Rect(std::string("Link"), 50, 50, 20, 20, 0, 0, 255);
    Rect enemy = Rect(std::string("Ganon"), 400, 400, 20, 20, 255, 0, 0);

    while(!quit){
        SDL_SetRenderDrawColor(r, 0, 255, 0, 255);
        SDL_RenderClear(r);
        int speed = 2;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT) quit = true;

        }

        const Uint8 *state = SDL_GetKeyboardState(NULL);
        if(state[SDL_SCANCODE_LSHIFT]) speed *= 2;
        if(state[SDL_SCANCODE_W]) hero.move(0, -speed);
        if(state[SDL_SCANCODE_A]) hero.move(-speed,0);
        if(state[SDL_SCANCODE_S]) hero.move(0,speed);
        if(state[SDL_SCANCODE_D]) hero.move(speed,0);
        if(hero.collides(&enemy)) enemy.kill();

        if(enemy.isAlive) enemy.draw(r);
        hero.draw(r);

        SDL_RenderPresent(r);
    }

    SDL_Quit();
    return 0;

}
