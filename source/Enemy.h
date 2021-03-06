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

        //holds a pointer to the graphics object but will not destroy it
        Enemy(SDLGraphics *graphics,
              int imageX, int imageY,
              int width, int height,
              const char *filename,
              int maxSpeed);

        ~Enemy();

        //this must be called each frame
        void update(float deltaTime);

        void takeDamage(float dmgAmount);

        void draw();

        void setPosition(int x, int y);

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

        int eMaxSpeed;
        int eCurrentSpeedX;
        int eCurrentSpeedY;

        float eHealth;

        bool eIsAlive;
};
