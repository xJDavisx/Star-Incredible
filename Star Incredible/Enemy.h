#pragma once
#include <SDL.h>
#include <iostream>
#include <string>

#include "SDLGraphics.h"
#include "Input.h"

class Enemy
{

    public:
        Enemy();
        //this class holds a pointer to the graphics object but will not destroy it
        Enemy(SDLGraphics *graphics,
              int imageX, int imageY,
              int width, int height,
              const char *filename,
              float maxSpeed);

        ~Enemy();

        //this must be called each frame
        void update(float deltaTime);

        void takeDamage(float dmgAmount);

        void draw();

        //static Enemy[] AddEnemy(Enemy[]);


    private:
        SDLGraphics *eGraphics;
        SDL_Surface *eBitmap;

        float eX;
        float eY;
        float eWidth;
        float eHeight;

        float eImageX;
        float eImageY;

        float eMaxSpeed;
        float eCurrentSpeedX;
        float eCurrentSpeedY;

        float eHealth;

        bool eIsAlive;

};