#ifndef WorldObject_H
#define WorldObject_H

#include <SDL2/SDL.h>
#include <string>

class WorldObject
{
    // methods
    public:
        WorldObject(std::string name, int x, int y, int width, int height);
        WorldObject(std::string name, int x, int y, int width, int height, int r, int g, int b);
        ~WorldObject();
        void draw();
        bool collides(WorldObject *otherRect);
        int getRed(){return red;}
        int getGreen(){return green;}
        int getBlue(){return blue;}
        int getHeight(){return height;}
        int getWidth(){return width;}
        int getXPos(){return xPos;}
        int getYPos(){return yPos;}
        std::string getName(){return name;}
    // properties
    protected:
        int xPos;
        int yPos;
        int width;
        int height;
        std::string name;
        int red;
        int green;
        int blue;

        // buffer title text of the rectangl
        SDL_Texture *titleTexture;
        int titleTextureWidth;
        int titleTextureHeight;

};

#endif // WorldObject_H
