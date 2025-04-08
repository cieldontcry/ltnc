#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<string>
#include "defs.h"

struct Graphics {

    //main renderer and window
    SDL_Renderer *renderer;
    SDL_Window *window;

    //Message when logError
    void logErrorAndExit(const char* msg, const char* error);

    //init after declare graphic
    void init();

    //render background
    void prepareScene(SDL_Texture * background);

    //present the present sence
    void presentScene();
    //build texture from image
    SDL_Texture *loadTexture(const char *filename);

    //build texture from text
    SDL_Texture *loadSurface(TTF_Font *Font, const char* text, SDL_Color Color);

    //render texture
    void renderTexture(SDL_Texture *texture,const int x,const int y, const int w, const int h);

    // Quit SDL
    void quit();

    void pressAnyKeyToContinue();

    //music
    Mix_Music *loadMusic(const char* path);
    void play(Mix_Music *gMusic);

    //sound effect
    Mix_Chunk* loadSound(const char* path);
    void play(Mix_Chunk* gChunk);

};

//struct textBox
struct rect{

    int x, y, w, h;

};

//render text
void renderText(Graphics mainGraphic, TTF_Font* Font, SDL_Color Color,
                const char* text, const int x, const int y, const int h, const int center);

//find textBox of text
rect textBox(Graphics mainGraphic, TTF_Font* Font, SDL_Color Color,
              const char* text, const int x, const int y, const int h, const int center);

//check mouse in textBox or not
int checkMouse(int x, int y, rect textBox);

#endif // _GRAPHICS__H
