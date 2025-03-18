#ifndef _DRAW__H
#define _DRAW__H

#include<iostream>
#include<string>

#include "graphics.h"
#include "defs.h"

using namespace std;

string findImage(int a){

    return "image\\hangman\\" + std::to_string(a) + ".jpg";

}

void draw(int a, Graphics& mainGraphics){

    SDL_Texture* hangManImage = mainGraphics.loadTexture(findImage(a).c_str());
    mainGraphics.renderTexture(hangManImage, 0, 0);

}

#endif // _DRAW__H
