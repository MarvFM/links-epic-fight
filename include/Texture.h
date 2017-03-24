#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>
#include <string>

#include "../include/WorldObject.h"

class Texture
{
    public:
        Texture(std::string path, int x = 0, int y = 0);
        ~Texture();
        void loadTexture(std::string path, int x = 0, int y = 0);
        void drawTexture(WorldObject* obj, int xOffset = 0, int yOffset = 0);
    private:
        SDL_Texture* texture;
        int xPos;
        int yPos;
        int width;
        int height;
};

#endif // TEXTURE_H
