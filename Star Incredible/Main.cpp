#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "SDLGraphics.h"
#include "Player.h"
#include "Input.h"
#include "Timer.h"
#include "Enemy.h"

using namespace std;

const char *WINDOW_TITLE = "Star Incredible";
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const char* PLAYER_SHIP_FILENAME = "resources/player-ship.png";
const float PLAYER_START_X = 0;
const float PLAYER_START_Y = 500;
const int PLAYER_IMAGE_X = 0;
const int PLAYER_IMAGE_Y = 0;
const int PLAYER_IMAGE_WIDTH = 50;
const int PLAYER_IMAGE_HEIGHT = 100;
const float PLAYER_SPEED = 300.0;

bool g_gameIsRunning = true;
Player* player_ship = NULL;
SDLGraphics* g_graphics = NULL;
Input* g_input = NULL;
Timer* g_timer = NULL;

void handleKeyboardInput();

int main(int argc, char *args[]){
    
    g_graphics = new SDLGraphics(800, 600, WINDOW_TITLE);
    g_graphics->setBackground("resources/background.png");
    g_input = new Input();

    player_ship = new Player(g_graphics,
        PLAYER_IMAGE_X, PLAYER_IMAGE_Y,
        PLAYER_IMAGE_WIDTH, PLAYER_IMAGE_HEIGHT,
        PLAYER_SHIP_FILENAME,
        PLAYER_START_X, PLAYER_START_Y,
        PLAYER_SPEED, g_input);

    g_timer = new Timer();

    while (g_gameIsRunning){

        float deltaTime = g_timer->timeSinceLastFrame();

        // Handle input
        g_input->readInput();

        if (g_input->windowClosed())
        {
            g_gameIsRunning = false;
        }

        handleKeyboardInput();


        // Draw the scene
        g_graphics->beginScene();

        /*g_graphics->drawText("Star Fucking Incredible",
            12, 250, 100,
            200, 0, 0,
            0, 0, 0);*/
        
        // Handle game logic
        player_ship->update(deltaTime);


        g_graphics->endScene();
        
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