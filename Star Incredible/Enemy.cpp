/*
	**************************************************************************************************************************
	Class:		Enemy
	Purpose:	To add "Bad-guy" or "Enemy" functionality to the game. This class will encapsulate a basic "Galaga" like
				movement and approach.
	Version:	0.0.0.2
	Author:		Jesse Davis
	Date:		6/14/2014
	**************************************************************************************************************************
*/

#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(SDLGraphics* graphics, int imageX, int imageY, int width, int height, const char* filename, int maxSpeed)
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
    eY = 0;
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
        int i = rand() % 2;
        if (i)
        {
            eX += rand() % 100 * deltaTime;
        }
        else
        {
            eX -= rand() % 100 * deltaTime;
        }
        eY += rand() % eMaxSpeed * deltaTime;
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