#include "SDLGraphics.h"

SDLGraphics::SDLGraphics(int windowWidth, int windowHeight, 
                         const char *windowTitle){

    SDL_Init(SDL_INIT_VIDEO);

    TTF_Init();

    m_screen = SDL_SetVideoMode(windowWidth, windowHeight,
        0, SDL_SWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption(windowTitle, 0);

}

SDLGraphics::~SDLGraphics(){

    SDL_FreeSurface(background);
    SDL_FreeSurface(m_screen);
    TTF_Quit();
    SDL_Quit();

}

SDL_Surface *SDLGraphics::loadPNG(const char *filename){

    SDL_Surface *image = IMG_Load(filename);

    image = SDL_DisplayFormatAlpha(image);

    return image;

}

//CHA-CHING!
void SDLGraphics::setBackground(const char *filename)
{
    background = loadPNG(filename);
}

SDL_Surface *SDLGraphics::getScreen(){
    
    return m_screen;
    
    }

void SDLGraphics::closeImage(SDL_Surface *image){

    SDL_FreeSurface(image);

}

void SDLGraphics::beginScene(){

    SDL_BlitSurface(background, NULL, m_screen, NULL);

}

//this displays the screen
void SDLGraphics::endScene(){

    SDL_Flip(m_screen);

}

void SDLGraphics::drawSprite(SDL_Surface *imageSurface,
    int srcX, int srcY,
    int dstX, int dstY,
    int width, int height){

    SDL_Rect srcRect;
    srcRect.x = srcX;
    srcRect.y = srcY;
    srcRect.w = width;
    srcRect.h = height;

    SDL_Rect dstRect;
    dstRect.x = dstX;
    dstRect.y = dstY;
    dstRect.w = width;
    dstRect.h = height;

    SDL_BlitSurface(imageSurface, &srcRect, m_screen, &dstRect);

}

void SDLGraphics::drawText(const char *string,
    int size,
    int x, int y,
    int fR, int fG, int fB,
    int bR, int bG, int bB){

    TTF_Font *font = TTF_OpenFont("FreeSerif.ttf", size);

    SDL_Color foregroundColor = { fR, fG, fB };
    SDL_Color backgroundColor = { bR, bG, bB };

    SDL_Surface *textSurface = TTF_RenderText_Shaded(font, string,
        foregroundColor, backgroundColor);

    SDL_Rect textLocation = { x, y, 0, 0 };

    SDL_BlitSurface(textSurface, NULL, m_screen, &textLocation);

    SDL_FreeSurface(textSurface);

    TTF_CloseFont(font);

}