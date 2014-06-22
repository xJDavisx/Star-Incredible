#include <iostream>
#include <string>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "SDLGraphics.h"
#include "Player.h"
#include "Input.h"
#include "Timer.h"
#include "Enemy.h"

using namespace std;

bool g_gameIsRunning = true;

Input *g_input = new Input();

void handleKeyboardInput();
void levelOne();

int main(int argc, char *args[])
{
    levelOne();

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

void levelOne()
{
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
    const float PLAYER_SPEED = 600.0;

    const char *ENEMY_SHIP_FILENAME = "resources/enemy-ship.png";
    const int ENEMY_IMAGE_X = 0;
    const int ENEMY_IMAGE_Y = 0;
    const int ENEMY_IMAGE_WIDTH = 50;
    const int ENEMY_IMAGE_HEIGHT = 100;
    const int ENEMY_SPEED = 10;
    const int ENEMY_CAPACITY = 50;

    Player *player_ship = NULL;
    SDLGraphics *g_graphics = NULL;
    Timer *g_timer = NULL;
    Enemy *enemies[ENEMY_CAPACITY];

    //set array of enemies
    for (int i = 0; i < ENEMY_CAPACITY + 1; i++)
    {
        enemies[i] = new Enemy[ENEMY_CAPACITY + 1];
    }

    g_graphics = new SDLGraphics(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    g_graphics->setBackground("resources/background.png");

    player_ship = new Player(g_graphics,
                             PLAYER_IMAGE_X, PLAYER_IMAGE_Y,
                             PLAYER_IMAGE_WIDTH, PLAYER_IMAGE_HEIGHT,
                             PLAYER_SHIP_FILENAME,
                             Point(PLAYER_START_X,PLAYER_START_Y),
                             PLAYER_SPEED, g_input);

    //initialize enemies
    for (int i = 0; i < ENEMY_CAPACITY + 1; i++)
    {
        enemies[i] =  new Enemy(g_graphics,
                                ENEMY_IMAGE_X, ENEMY_IMAGE_Y,
                                ENEMY_IMAGE_WIDTH, ENEMY_IMAGE_HEIGHT,
                                ENEMY_SHIP_FILENAME,
                                ENEMY_SPEED);
    }

    //spawn lines of enemies with holes to navigate through
    for (int i = 0; i <= 50; i++)
    {
        if (i != 6 && i != 17 && i != 32 && i != 47)
        {
            if (i <= 13)
            {
                enemies[i]->setPosition(i * 60, -1300);
            }
            else if (i <= 26)
            {
                enemies[i]->setPosition((i - 13) * 60, -1700);
            }
            else if (i <= 39)
            {
                enemies[i]->setPosition((i - 26) * 60, -2100);
            }
            else if (i >= 40)
            {
                enemies[i]->setPosition((i - 39) * 60, -2500);
            }
        }
    }

    g_timer = new Timer();

    while (g_gameIsRunning)
    {
        float deltaTime = g_timer->timeSinceLastFrame();

        g_input->readInput();

        if (g_input->windowClosed())
        {
            g_gameIsRunning = false;
        }

        handleKeyboardInput();

        //draw scene
        g_graphics->beginScene();

        player_ship->update(deltaTime);

        for (int i = 0; i < ENEMY_CAPACITY + 1; i++)
        {
            enemies[i]->update(deltaTime);
        }

        g_graphics->endScene();
    }

    delete g_graphics;
}
