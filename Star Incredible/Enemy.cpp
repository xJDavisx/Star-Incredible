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

Enemy::Enemy(SDLGraphics* graphics, int imageX, int imageY, int width, int height, const char* filename, float maxSpeed)
{
    eGraphics = graphics;
    eImageX = imageX;
    eImageY = imageY;
    eWidth = width;
    eHeight = height;
    eMaxSpeed = maxSpeed;
    eCurrentSpeedX = 0.0f;
    eBitmap = eGraphics->loadPNG(filename);
    eX = 0;
    eY = 0;

}

Enemy::~Enemy()
{

    eGraphics->closeImage(eBitmap);

}

void Enemy::update(float deltaTime)
{

    eX += eCurrentSpeedX * deltaTime;
    eY += eCurrentSpeedY * deltaTime;
    if (eHealth <= 0.0)
    {
        eIsAlive = false;
    }
    if (eIsAlive)
    {
        //AI Code
    }
    else
    {
        //Death Animation
        //Delete Object
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