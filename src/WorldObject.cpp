#include "../include/WorldObject.h"

#include <SDL2/SDL_ttf.h>
#include <iostream>

extern SDL_Renderer* RENDERER;
extern TTF_Font* NAME_FONT;

/* Constructor of WorldObject
  1. arg: name of object (label for rendering)
  2. arg: x coordinate of object in the world
  3. arg: y coordinate of object in the world
  4. arg: width of the rectangle for collision detecting and rendering
  5. arg: height of the rectangle for collision detecting and rendering
  6. arg: RGB-value for red
  7. arg: RGB-value for green
  8. arg: RGB-value for blue
*/
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

// Deconstructor
WorldObject::~WorldObject()
{
    // must free this, or memory leak
    SDL_DestroyTexture(this->titleTexture);
}

/* renders the specific object with the global Renderer
  1. arg: xOffset for rendering -> default: 0
  2. arg: yOffset for rendering -> default: 0
*/
void WorldObject::draw(int xOffset, int yOffset){
    // create ractangle for the name-label
    SDL_Rect rect = {this->xPos + xOffset, this->yPos + yOffset, this->height, this->width};
    int titleRectXPos = (this->xPos + xOffset) + this->width/2 - this->titleTextureWidth/2;
    int titleRectYPos = (this->yPos + yOffset) - 3 - this->titleTextureHeight;
    SDL_Rect titleRect = {titleRectXPos, titleRectYPos, this->titleTextureWidth, this->titleTextureHeight};

    //renders rectangle for the object and the label
    SDL_RenderCopy(RENDERER, titleTexture, NULL, &titleRect);
    SDL_SetRenderDrawColor(RENDERER, this->red , this->green, this->blue, 255);
    SDL_RenderFillRect(RENDERER, &rect);
    return;
}

/* detects a collision to another WorldObject
  1. arg: WorldObject for collision detecting
  return: bool value if there is a collision or not
*/
bool WorldObject::collides(WorldObject *otherRect){
    int xDiff = this->xPos - otherRect->xPos;
    int yDiff = this->yPos - otherRect->yPos;
    if((xDiff - this->width > -2) || ((xDiff + otherRect->width < 2))) return false;
    if((yDiff - this->height > -2) || ((yDiff + otherRect->height < 2))) return false;
    return true;
}
