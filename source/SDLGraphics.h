#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

class SDLGraphics
{
    public:
        //this creates a window and initializes the graphics object
        //the last three parameters are the desired background color
        //call setBackgroundColor() to change this later
        SDLGraphics(int windowWidth, int windowHeight,
                    const char *windowTitle);
        ~SDLGraphics();
        SDL_Surface *loadPNG(const char *filename);
        SDL_Surface *getScreen();
        void closeImage(SDL_Surface *image);

        void beginScene();
        void setBackground(const char *filename);
        void endScene();

        void drawSprite(SDL_Surface *imageSurface,
                        int srcX, int srcY,
                        int dstX, int dstY,
                        int width, int height);

        void drawText(const char *string,
            int size,
            int x, int y,
            int R, int G, int B);

        void setBackgroundColor(int r, int g, int b);

    private:
        SDL_Surface *m_screen;
        SDL_Surface *background;

        int m_backgroundColorRed;
        int m_backgroundColorGreen;
        int m_backgroundColorBlue;
};
