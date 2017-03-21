#ifndef TIMER_H
#define TIMER_H

#include <SDL2/SDL.h>

class Timer
{
    // methods
    public:
      Timer();
      float getElapsed(){return fElapsed;}
      void Update();
    private:
      float fElapsed;
      float fCurTime;
      float fLastTime;

};

#endif // RECT_H
