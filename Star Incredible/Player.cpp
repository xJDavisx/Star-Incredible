// Player.cpp

#include "Player.h"

Player::Player(SDLGraphics* graphics,
    int imageX, int imageY,
    int width, int height,
    int transparentR, int transparentG, int transparentB,
    const char* bitmapFileName,
    float x, float y,
    float maxSpeed) : m_graphics(graphics),
    m_imageX(imageX), m_imageY(imageY),
    m_width(width), m_height(height),
    m_x(x), m_y(y),
    m_maxSpeed(maxSpeed),
    m_currentSpeedX(0.0f){

    m_bitmap = m_graphics->loadPNG(bitmapFileName);

}

Player::~Player(){

    m_graphics->closeImage(m_bitmap);

}

void Player::update(float deltaTime){

    m_x += m_currentSpeedX * deltaTime;

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

void Player::stopMoving(){

    m_currentSpeedX = 0.0f;

}