#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "SDLGraphics.h"
#include "Player.h"
#include "Input.h"
#include "Timer.h"

using namespace std;

const char *WINDOW_TITLE = "Star Incredible";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const char* DOOMGUY_BITMAP_FILE_NAME = "resources/player-pet.png";
const char* DOOMGUY2_BITMAP_FILE_NAME = "plate3.bmp";
const float DOOMGUY_START_X = 250.0f;
const float DOOMGUY_START_Y = 150.0f;
const int DOOMGUY_IMAGE_X = 0;
const int DOOMGUY_IMAGE_Y = 0;
const int DOOMGUY_IMAGE_WIDTH = 160;
const int DOOMGUY_IMAGE_HEIGHT = 160;
const float DOOMGUY_SPEED = 100.0;

bool g_gameIsRunning = true;
Player* player_ship = NULL;
SDLGraphics* g_graphics = NULL;
Input* g_input = NULL;
Timer* g_timer = NULL;

void handleKeyboardInput();

int main(int argc, char *args[]){
    
    g_graphics = new SDLGraphics(800, 600, WINDOW_TITLE);
    SDL_Surface *germ = g_graphics->loadPNG("resources/germ.png");
    g_graphics->setBackground("resources/background.png");
    g_input = new Input();

    player_ship = new Player(g_graphics,
        DOOMGUY_IMAGE_X, DOOMGUY_IMAGE_Y,
        DOOMGUY_IMAGE_WIDTH, DOOMGUY_IMAGE_HEIGHT,
        DOOMGUY_BITMAP_FILE_NAME,
        DOOMGUY_START_X, DOOMGUY_START_Y,
        DOOMGUY_SPEED, g_input);

    g_timer = new Timer();

    while (g_gameIsRunning){

        float deltaTime = g_timer->timeSinceLastFrame();
        
        g_input->readInput();
        handleKeyboardInput();
        g_graphics->beginScene();
        player_ship->update(deltaTime);
        g_graphics->endScene();
        handleKeyboardInput();
        
        }

    delete g_graphics;
    
    return 0;
    
    }

void handleKeyboardInput(){

    bool* keysHeld = g_input->getInput();

    if (keysHeld[SDLK_ESCAPE]){

        g_gameIsRunning = false;

    }

}