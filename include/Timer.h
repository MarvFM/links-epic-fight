#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

class Timer
{
    public:
        Timer();
        void Update();
        float getElapsed(){return fElapsed;}
    private:
        float fElapsed;
        float fCurTime;
        float fLastTime;
};

#endif // TIMER_H
