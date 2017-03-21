#include "../include/Rect.h"


Rect::Rect(std::string name, int x, int y, int height, int width, int r, int g, int b)
{
    this->name = name;
    this->xPos = x;
    this->yPos = y;
    this->height = height;
    this->width = width;
    this->isAlive = true;
    this->red = r;
    this->green = g;
    this->blue = b;
}

void Rect::draw(SDL_Renderer* dst){
    SDL_Rect rect;
    rect.x = xPos;
    rect.y = yPos;
    rect.h = height;
    rect.w = width;
    SDL_SetRenderDrawColor(dst, this->red , this->green, this->blue, 255);

    SDL_RenderFillRect(dst, &rect);
}

bool Rect::move(int xDiff, int yDiff){
    this->xPos += xDiff;
    this->yPos += yDiff;
}

void Rect::kill(){
    this->isAlive = false;
}

bool Rect::collides(Rect *otherRect){
    int xDiff = this->xPos - otherRect->xPos;
    int yDiff = this->yPos - otherRect->yPos;
    if((xDiff - this->width > -2) || ((xDiff + otherRect->width < 2))) return false;
    if((yDiff - this->height > -2) || ((yDiff + otherRect->height < 2))) return false;
    return true;
}

