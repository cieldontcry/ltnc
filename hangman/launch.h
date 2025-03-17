#ifndef _LAUNCH__H
#define _LAUNCH__H

#include<iostream>

#include "create.h"
#include "draw.h"
#include "guess.h"
#include "defs.h"

using namespace std;

void launch(){

    string word;
    string blankWord;
    int badGuessCount;

    word = createWord();
    blankWord= creatBlankWord((int)word.length(), '-');

    while (badGuessCount != 7){

        char guess = guessWord();
        if (checkGuess(guess, word, blankWord) == 0){
            badGuessCount++;
            draw(badGuessCount);
        }

        else {
            updateBlankWord(guess, word, blankWord);
            cout << blankWord <<'\n';
            if (blankWord == word){
                cout << "You won" <<'\n';
                return;
            }
        }

    }
    cout << "You lose" <<'\n';

}

#endif // _LAUNCH__H
