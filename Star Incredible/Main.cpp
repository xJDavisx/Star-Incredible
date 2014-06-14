#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "SDLGraphics.h"

using namespace std;

const char *WINDOW_TITLE = "Star Incredible";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

bool g_gameIsRunning = true;
SDLGraphics *g_graphics;

int main(int argc, char *args[]){

    g_graphics = new SDLGraphics(800, 600, WINDOW_TITLE);
    SDL_Surface *germ = g_graphics->loadPNG("resources/germ.png");
    g_graphics->setBackground("resources/background.png");

    while (g_gameIsRunning){
        
        g_graphics->beginScene();
        g_graphics->endScene();

        SDL_Delay(3000);
        g_graphics->setBackground("resources/background1.png");
        g_graphics->beginScene();
        g_graphics->drawSprite(germ, 0, 0, 50, 50, 160, 166);
        g_graphics->endScene();
        SDL_Delay(3000);
        g_gameIsRunning = false;
        
        }

    delete g_graphics;
    
    return 0;
    
    }