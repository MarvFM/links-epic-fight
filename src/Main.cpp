#include <SDL2/SDL.h>
#include <string>

#include "../include/Rect.h"
#include "../include/Game.h"

int main(){
    SDL_Init(SDL_INIT_VIDEO);
    Game game = Game();
    game.Run();
    SDL_Quit();
    return 0;
}
