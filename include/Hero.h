#ifndef Hero_H
#define Hero_H

#include <SDL2/SDL.h>
#include <string>

#include "../include/Character.h"
#include "../include/Texture.h"

class Hero : public Character
{
    // methods
    public:
        Hero(int x, int y);

    protected:
        static Texture* texture;

};

#endif // Character_H
