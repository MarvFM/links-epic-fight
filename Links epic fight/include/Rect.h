#ifndef RECT_H
#define RECT_H
#include <SDL2/SDL.h>
#include <string>

class Rect
{
    public:
        bool isAlive;
        int red;
        int green;
        int blue;

        Rect(std::string name, int x, int y, int height, int width, int r, int g, int b);
        void draw(SDL_Renderer* dst);
        bool move(int xDiff, int yDiff);
        void kill();
        bool collides(Rect *otherRect);
    private:
        int xPos;
        int yPos;
        int height;
        int width;
        std::string name;
};

#endif // RECT_H

