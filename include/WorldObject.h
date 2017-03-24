#ifndef WorldObject_H
#define WorldObject_H

#include <SDL2/SDL.h>
#include <string>

#include "../include/Texture.h"

class WorldObject
{
    // public methods
    public:
        WorldObject(std::string name, int x, int y, int width, int height, int r, int g, int b);
        ~WorldObject();
        void loadTexture(std::string path, int x, int y);
        // renders the object on the window on its coordinates
        void draw(int xOffset = 0, int yOffset = 0);
        // checks for a collision to another object
        bool collides(WorldObject *otherRect);
        // getter methods
        int getRed(){return red;}
        int getGreen(){return green;}
        int getBlue(){return blue;}
        int getHeight(){return height;}
        int getWidth(){return width;}
        int getXPos(){return xPos;}
        int getYPos(){return yPos;}
        std::string getName(){return name;}
        SDL_Rect getRect(){SDL_Rect rect = {this->xPos, this->yPos, this->width, this->height}; return rect;}
    // protected properties
    protected:
        // coordinates in the world
        int xPos;
        int yPos;
        // width and height for an rectangle
        int width;
        int height;
        // name/label for this object
        std::string name;
        // RGB values
        int red;
        int green;
        int blue;

        // buffer title text of the rectangle
        SDL_Texture *titleTexture;
        int titleTextureWidth;
        int titleTextureHeight;

        Texture* texture;
};

#endif // WorldObject_H
