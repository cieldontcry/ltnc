#ifndef _GUESS__H
#define _GUESS__H

#include <string>
#include "draw.h"

using namespace std;

//check type of char
int type(const char chr);

//input guessWord
char guessWord(Graphics mainGraphic, SDL_Texture* hangManImage, string blankWord, bool& check);

//check
int checkGuess(const char guess, const string word, const string blankWord);

//update when guessWord correct
void updateBlankWord(const char guess, const string word, string& blankWord);

#endif // _GUESS__H
