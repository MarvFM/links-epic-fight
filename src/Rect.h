#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>
#include <string>

class Rect
{
    // methods
    public:
        Rect(std::string name, int x, int y, int width, int height, int r, int g, int b);
        ~Rect();
        void draw();
        void move(int xDiff, int yDiff);
        void kill();
        bool collides(Rect *otherRect);

    // properties
    public:
        bool isAlive;
        int red;
        int green;
        int blue;

        // buffer title text of the rectangle
        SDL_Texture *titleTexture;
        int titleTextureWidth;
        int titleTextureHeight;

    private:
        int xPos;
        int yPos;
        int width;
        int height;
        std::string name;
};

#endif // RECT_H
