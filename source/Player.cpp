#include "Player.h"

Player::Player(SDLGraphics *graphics,
               int imageX, int imageY,
               int width, int height,
               const char *filename,
               Point location,
               float maxSpeed, Input *input) : pGraphics(graphics),
                                               pImageX(imageX), pImageY(imageY),
                                               pWidth(width), pHeight(height),
                                               pMaxSpeed(maxSpeed),
                                               pCurrentSpeedX(0.0f)
{

    pX = location.pX;
    pY = location.Y;
    pInput = input;
    pBitmap = pGraphics->loadPNG(filename);
}

Player::~Player()
{
    pGraphics->closeImage(pBitmap);
}

void Player::update(float deltaTime)
{
    handleKeyboardInput();
    pX += pCurrentSpeedX * deltaTime;
    pY += pCurrentSpeedY * deltaTime;

    //collide with edges of screen
    if (pX > 750)
    {
        pX = 750;
    }

    if (pX < 0)
    {
        pX = 0;
    }

    if (pY > 550)
    {
        pY = 550;
    }

    if (pY < 0)
    {
        pY = 0;
    }

    draw();
}

void Player::draw()
{
    pGraphics->drawSprite(pBitmap,
                          pImageX, pImageY,
                          pX, pY,
                          pWidth, pHeight);
}

Point Player::getLocation()
{
    return Point(pX, pY);
}

void Player::handleKeyboardInput()
{
    bool* keysHeld = pInput->getInput();

    if (keysHeld[SDLK_a])
    {
        //move left
        pCurrentSpeedX = -pMaxSpeed;
    }

    if (keysHeld[SDLK_w])
    {
        //move up
        pCurrentSpeedY = -pMaxSpeed;
    }

    if (keysHeld[SDLK_s])
    {
        //move down
        pCurrentSpeedY = pMaxSpeed;
    }

    if (keysHeld[SDLK_d])
    {
        //move right
        pCurrentSpeedX = pMaxSpeed;
    }

    if (!keysHeld[SDLK_w] && !keysHeld[SDLK_s])
    {
        pCurrentSpeedY = 0.0f;
    }

    if (!keysHeld[SDLK_a] && !keysHeld[SDLK_d])
    {
        pCurrentSpeedX = 0.0f;
    }
}
