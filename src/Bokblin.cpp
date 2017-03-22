#include "../include/Bokblin.h"

#include <SDL2/SDL_ttf.h>

extern SDL_Renderer* RENDERER;
extern TTF_Font* NAME_FONT;

Bokblin::Bokblin(int x, int y)
: Character(std::string("Bokblin"), x, y, 20, 20, 255, 0, 0, 3, 1)
{

}
