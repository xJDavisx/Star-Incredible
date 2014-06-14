#pragma once
#include <SDL.h>
#include <iostream>
#include <string>

#include "SDLGraphics.h"
#include "Input.h"

class Player{

public:
    //this class holds a pointer to the graphics object but will not destroy it
    Player(SDLGraphics *graphics,
        int imageX, int imageY,
        int width, int height,
        const char *bitmapFileName,
        float x, float y,
        float maxSpeed, Input *g_input);

    ~Player();

    //this must be called each frame
    void update(float deltaTime);

    void draw();

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopMoving();
    void handleKeyboardInput();

private:
    SDLGraphics *m_graphics;
    SDL_Surface *m_bitmap;
    Input *g_input;

    float m_x;
    float m_y;
    float m_width;
    float m_height;

    float m_imageX;
    float m_imageY;

    float m_maxSpeed;
    float m_currentSpeedX;
    float m_currentSpeedY;

};