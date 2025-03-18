#ifndef _DRAW__H
#define _DRAW__H

#include<iostream>
#include<string>

#include "graphics.h"
#include "defs.h"

using namespace std;

string findImage(const int badGuess){

    return "image\\hangman\\" + std::to_string(badGuess) + ".jpg";

}

void draw(const int badGuess, Graphics& mainGraphic){

    SDL_Texture* hangManImage = mainGraphic.loadTexture(findImage(badGuess).c_str());
    mainGraphic.renderTexture(hangManImage, 0, 0);
    SDL_DestroyTexture(hangManImage);
    hangManImage = NULL;

}

#endif // _DRAW__H
