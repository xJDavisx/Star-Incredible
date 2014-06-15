#include "Player.h"

Player::Player(SDLGraphics* graphics,
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
        //Move Left
        pCurrentSpeedX = -pMaxSpeed;

    }
    if (keysHeld[SDLK_w])
    {
        //Move Up
        pCurrentSpeedY = -pMaxSpeed;

    }
    if (keysHeld[SDLK_s])
    {
        //Move Down
        pCurrentSpeedY = pMaxSpeed;

    }

    if (keysHeld[SDLK_d])
    {
        //Move Right
        pCurrentSpeedX = pMaxSpeed;

    }
    if (!keysHeld[SDLK_w] && !keysHeld[SDLK_s])
    {
        //Check if Up and Down keys are not held. If true, stop all vertical movment.
        pCurrentSpeedY = 0.0f;

    }
    if (!keysHeld[SDLK_a] && !keysHeld[SDLK_d])
    {
        //Check if Left and Right keys are not held. If true, stop all horizontal movment.
        pCurrentSpeedX = 0.0f;

    }

}