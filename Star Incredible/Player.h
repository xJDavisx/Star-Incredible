#pragma once
#include <SDL.h>
#include <iostream>
#include <string>

#include "SDLGraphics.h"
#include "Input.h"
#include "Point.h"


class Player
{

    public:
        //this class holds a pointer to the graphics object but will not destroy it
        Player(SDLGraphics *graphics,
               int imageX, int imageY,
               int width, int height,
               const char *filename,
               Point location,
               float maxSpeed, Input *g_input);

        ~Player();

        //this must be called each frame
        void update(float deltaTime);

        void draw();

        Point getLocation();

        void handleKeyboardInput();

    private:
        SDLGraphics *pGraphics;
        SDL_Surface *pBitmap;
        Input *pInput;

        float pX;
        float pY;
        float pWidth;
        float pHeight;

        float pImageX;
        float pImageY;

        float pMaxSpeed;
        float pCurrentSpeedX;
        float pCurrentSpeedY;

};