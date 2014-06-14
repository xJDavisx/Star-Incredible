#include "Player.h"

Player::Player(SDLGraphics* graphics,
    int imageX, int imageY,
    int width, int height,
    const char* bitmapFileName,
    float x, float y,
    float maxSpeed, Input* input) : m_graphics(graphics),
    m_imageX(imageX), m_imageY(imageY),
    m_width(width), m_height(height),
    m_x(x), m_y(y),
    m_maxSpeed(maxSpeed),
    m_currentSpeedX(0.0f){

    g_input = input;
    m_bitmap = m_graphics->loadPNG(bitmapFileName);

}

Player::~Player(){

    m_graphics->closeImage(m_bitmap);

}

void Player::update(float deltaTime){

    handleKeyboardInput();
    m_x += m_currentSpeedX * deltaTime;
    m_y += m_currentSpeedY * deltaTime;
    draw();

}

void Player::draw(){

    m_graphics->drawSprite(m_bitmap,
        m_imageX, m_imageY,
        m_x, m_y,
        m_width, m_height);

}

void Player::moveLeft(){

    m_currentSpeedX = -m_maxSpeed;

}

void Player::moveRight(){

    m_currentSpeedX = m_maxSpeed;

}
void Player::moveUp(){

    m_currentSpeedY = -m_maxSpeed;

}

void Player::moveDown(){

    m_currentSpeedY = m_maxSpeed;

}

void Player::stopMoving(){

    m_currentSpeedX = 0.0f;
    m_currentSpeedY = 0.0f;

}

void Player::handleKeyboardInput(){

    bool* keysHeld = g_input->getInput();
    bool isKeyHeld = false;

    if (keysHeld[SDLK_LEFT]){

        moveLeft();
        isKeyHeld = true;

    }
    if (keysHeld[SDLK_UP]){

        moveUp();
        isKeyHeld = true;

    }
    if (keysHeld[SDLK_DOWN]){

        moveDown();
        isKeyHeld = true;

    }

    if (keysHeld[SDLK_RIGHT]){

        moveRight();
        isKeyHeld = true;

    }
    if (!isKeyHeld){

        stopMoving();

    }

}