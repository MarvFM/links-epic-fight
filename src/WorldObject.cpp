#include "../include/WorldObject.h"

#include <SDL2/SDL_ttf.h>

extern SDL_Renderer* RENDERER;
extern TTF_Font* NAME_FONT;

WorldObject::WorldObject(std::string name, int x, int y, int width, int height, int r, int g, int b)
{
  this->name = name;
  this->xPos = x;
  this->yPos = y;
  this->width = width;
  this->height = height;
  this->red = r;
  this->green = g;
  this->blue = b;

  // create title text in the most fancy way, this is costly so we do it only once
  // first temporary surface
  SDL_Surface *s = TTF_RenderText_Blended(NAME_FONT, name.c_str(), {255, 255, 255});
  // texture from this (more efficient)
  this->titleTexture = SDL_CreateTextureFromSurface(RENDERER, s);
  // also get dimensions from this
  this->titleTextureWidth = s->w;
  this->titleTextureHeight = s->h;
  // free temp surface (actual memory leak)
  SDL_FreeSurface(s);
}

WorldObject::~WorldObject()
{
    // must free this, or memory leak
    SDL_DestroyTexture(this->titleTexture);
}

void WorldObject::draw(){
    SDL_Rect rect = {this->xPos, this->yPos, this->height, this->width};
    int titleRectXPos = this->xPos + this->width/2 - this->titleTextureWidth/2;
    int titleRectYPos = this->yPos - 3 - this->titleTextureHeight;
    SDL_Rect titleRect = {titleRectXPos, titleRectYPos, this->titleTextureWidth, this->titleTextureHeight};

    SDL_RenderCopy(RENDERER, titleTexture, NULL, &titleRect);
    SDL_SetRenderDrawColor(RENDERER, this->red , this->green, this->blue, 255);
    SDL_RenderFillRect(RENDERER, &rect);
}


bool WorldObject::collides(WorldObject *otherRect){
    int xDiff = this->xPos - otherRect->xPos;
    int yDiff = this->yPos - otherRect->yPos;
    if((xDiff - this->width > -2) || ((xDiff + otherRect->width < 2))) return false;
    if((yDiff - this->height > -2) || ((yDiff + otherRect->height < 2))) return false;
    return true;
}
