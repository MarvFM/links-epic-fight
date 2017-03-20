#ifndef RECT_H
#define RECT_H
#include <SDL2/SDL.h>
#include <string>

class Rect
{
    public:
        int xPos;
        int yPos;
        int height;
        int width;
        bool isAlive;
        int red;
        int green;
        int blue;

        std::string name;
        Rect(std::string name, int x, int y, int height, int width, int r, int g, int b);
        void draw(SDL_Renderer* dst);
        bool move(int xDiff, int yDiff);
        void kill();
        bool collides(Rect *otherRect);
    private:
};

#endif // RECT_H

