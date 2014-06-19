#pragma once

#include <SDL.h>
#include <iostream>
#include <string>

class Timer
{
    public:
        Timer();
        ~Timer();

        //returns the number of milliseconds since object was created
        float timeSinceCreation();

        //returns number of milliseconds since last called
        float timeSinceLastFrame();

    private:
        //stores the time of that last call to timeSinceLastFrame()
        float m_timeOfLastCall;
};
