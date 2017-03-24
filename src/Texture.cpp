#include "../include/Texture.h"

#include <SDL2/SDL_image.h>

extern SDL_Renderer* RENDERER;

Texture::Texture(std::string path)
{
    SDL_Surface* loadedSurface = IMG_Load(path.c_str(), int x, int y);
    if(loadedSurface != NULL) this->texture = SDL_CreateTextureFromSurface(RENDERER, loadedSurface);
    this->xPos = x;
    this->yPos = y;
    this->width = loadedSurface->w;
    this->height = loadedSurface->h;
    SDL_FreeSurface(loadedSurface);
}

Texture::~Texture()
{
    if(this->texture != NULL) SDL_DestroyTexture(this->texture);
}

void Texture::loadTexture(std::string path, int x, int y)
{
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface != NULL){
        if(this->texture != NULL) SDL_DestroyTexture(this->texture);
        this->texture = SDL_CreateTextureFromSurface(RENDERER, loadedSurface);

    }
    this->xPos = x;
    this->yPos = y;
    this->width = loadedSurface->w;
    this->height = loadedSurface->h;
    SDL_FreeSurface(loadedSurface);
}

void Texture::drawTexture(WorldObject* obj, int xOffset, int yOffset)
{
    const SDL_Rect dRect = obj->getRect();
    const SDL_Rect sRect = {this->xPos + xOffset, this->yPos + yOffset, 16, 16};
    SDL_RenderCopy(RENDERER, this->texture, &sRect, &dRect);
}
