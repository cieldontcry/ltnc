#ifndef _DRAW__H
#define _DRAW__H

#include<iostream>
#include<string>

#include "graphics.h"

using namespace std;

//image link
string findImage(const int badGuess);

//render hangman
void draw(const int badGuess, Graphics& mainGraphic, SDL_Texture** hangManImage);

#endif // _DRAW__H
