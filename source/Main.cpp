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

const char *PLAYER_SHIP_FILENAME = "resources/player-ship1.png";
const float PLAYER_START_X = 0;
const float PLAYER_START_Y = 500;
const int PLAYER_IMAGE_X = 0;
const int PLAYER_IMAGE_Y = 0;
const int PLAYER_IMAGE_WIDTH = 50;
const int PLAYER_IMAGE_HEIGHT = 100;
const float PLAYER_SPEED = 300.0;

const char *ENEMY_SHIP_FILENAME = "resources/enemy-ship.png";
const int ENEMY_IMAGE_X = 0;
const int ENEMY_IMAGE_Y = 0;
const int ENEMY_IMAGE_WIDTH = 50;
const int ENEMY_IMAGE_HEIGHT = 100;
const int ENEMY_SPEED = 20;
const int ENEMY_CAPACITY = 50;

bool g_gameIsRunning = true;
Player *player_ship = NULL;
SDLGraphics *g_graphics = NULL;
Input *g_input = NULL;
Timer *g_timer = NULL;
Enemy *enemies[ENEMY_CAPACITY];

void handleKeyboardInput();

int main(int argc, char *args[])
{
    for (int i = 0; i < ENEMY_CAPACITY + 1; i++)
    {
        enemies[i] = new Enemy[ENEMY_CAPACITY + 1];
    }
    g_graphics = new SDLGraphics(800, 600, WINDOW_TITLE);
    g_graphics->setBackground("resources/background.png");
    g_input = new Input();

    player_ship = new Player(g_graphics,
                             PLAYER_IMAGE_X, PLAYER_IMAGE_Y,
                             PLAYER_IMAGE_WIDTH, PLAYER_IMAGE_HEIGHT,
                             PLAYER_SHIP_FILENAME,
                             Point(PLAYER_START_X,PLAYER_START_Y),
                             PLAYER_SPEED, g_input);

    for (int i = 0; i < ENEMY_CAPACITY + 1; i++)
    {
        enemies[i] =  new Enemy(g_graphics,
                           ENEMY_IMAGE_X, ENEMY_IMAGE_Y,
                           ENEMY_IMAGE_WIDTH, ENEMY_IMAGE_HEIGHT,
                           ENEMY_SHIP_FILENAME,
                           ENEMY_SPEED);
    }
    /*enemies = new Enemy(g_graphics,
                    ENEMY_IMAGE_X, ENEMY_IMAGE_Y, ENEMY_IMAGE_WIDTH,
                    ENEMY_IMAGE_HEIGHT, ENEMY_SHIP_FILENAME, ENEMY_SPEED);*/

    g_timer = new Timer();

    while (g_gameIsRunning)
    {
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

        // Handle game logic
        player_ship->update(deltaTime);
        for (int i = 0; i < ENEMY_CAPACITY + 1; i++)
        {
            enemies[i]->update(deltaTime);
        }
        //enemies->update(deltaTime);

        g_graphics->endScene();
    }

    delete g_graphics;

    return 0;
}

void handleKeyboardInput()
{
    bool* keysHeld = g_input->getInput();

    if (keysHeld[SDLK_ESCAPE])
    {
        g_gameIsRunning = false;
    }
}
