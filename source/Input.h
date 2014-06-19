#pragma once

#include <SDL.h>
#include <iostream>
#include <string>

class Input
{

    public:
        Input();
        ~Input();

        //call this before any other methods
        void readInput();

        bool *getInput();

        //check this each frame
        bool windowClosed();

    private:
        SDL_Event m_event;
        bool m_keysHeld[323];
        bool m_windowClosed;
};
