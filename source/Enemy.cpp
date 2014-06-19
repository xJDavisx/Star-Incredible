/*
	***************************************************************************
	Class:		Enemy
	Purpose:	To add "Bad-guy" or "Enemy" functionality to the game.
                This class will encapsulate a basic "Galaga" like
				movement and approach.
	Version:	0.0.0.2
	Author:		Jesse Davis
	Date:		6/14/2014
	***************************************************************************
*/

#include "Enemy.h"
#include <time.h>

Enemy::Enemy()
{
}

Enemy::Enemy(SDLGraphics *graphics,
             int imageX, int imageY,
             int width, int height,
             const char *filename, int maxSpeed)
{
    eGraphics = graphics;
    eImageX = imageX;
    eImageY = imageY;
    eWidth = width;
    eHeight = height;
    eMaxSpeed = maxSpeed;
    eCurrentSpeedX = 100;
    eCurrentSpeedY = 100;
    eBitmap = eGraphics->loadPNG(filename);
    eX =  rand() % 800;
    eY = (rand() % 2400) - 3200;//spawn spread and out of player's view
    eIsAlive = true;
    eHealth = 100;
}

Enemy::~Enemy()
{
    eGraphics->closeImage(eBitmap);
}

void Enemy::update(float deltaTime)
{
    if (eHealth <= 0.0)
    {
        eIsAlive = false;
    }

    if (eIsAlive)
    {
        srand(time(NULL));

        if (rand() % 2)
        {
            eX += rand() % 100 * deltaTime;
        }

        else
        {
            eX -= rand() % 100 * deltaTime;
        }

        eY += rand() % eMaxSpeed * 60 * deltaTime;

        //enemies collide with edges of screen
        if (eX > 750)
        {
            eX = 750;
        }

        if (eX < 0)
        {
            eX = 0;
        }
    }
    else
    {
        //Death Animation
        //Delete Object
    }

    if (eY > 600)
    {
        eIsAlive = false;
    }
    draw();
}


void Enemy::takeDamage(float dmgAmount)
{
    eHealth -= dmgAmount;
}

void Enemy::draw()
{
    eGraphics->drawSprite(eBitmap,
                          eImageX, eImageY,
                          eX, eY,
                          eWidth, eHeight);
}
