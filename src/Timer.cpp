#include "Timer.h"

Timer::Timer()
{
    this->fCurTime = 0.0f;
    this->fLastTime = SDL_GetTicks() / 1000.0f;
    this->fElapsed = 0.0f;
}

void Timer::Update()
{
    fCurTime = SDL_GetTicks() / 1000.0f;
    fElapsed = fCurTime - fLastTime;
    fLastTime = fCurTime;
}
