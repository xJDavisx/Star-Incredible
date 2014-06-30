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

void mainMenu();
void levelOne();
void handleKeyboardInput();

int main(int argc, char *args[])
{
    mainMenu();

    levelOne();

    return 0;
}
