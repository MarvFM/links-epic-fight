#include "../include/Hero.h"

#include <SDL2/SDL_ttf.h>

extern SDL_Renderer* RENDERER;
extern TTF_Font* NAME_FONT;

Hero::Hero(int x, int y)
: Character(std::string("Link"), x, y, 20, 20, 0, 0, 255, 3, 1)
{

}
