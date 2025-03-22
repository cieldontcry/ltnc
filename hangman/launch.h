#ifndef _LAUNCH__H
#define _LAUNCH__H

#include<iostream>

#include "create.h"
#include "draw.h"
#include "guess.h"
#include "defs.h"

using namespace std;

//main function
void launch(Graphics& mainGraphic){

    SDL_RenderClear(mainGraphic.renderer);

    string word;
    string blankWord;
    int badGuessCount = 0;

    TTF_Font* Sans = TTF_OpenFont(fontFile, fontSize);
    SDL_Color White = {255,255,255};

    //creat a image with no thing
    SDL_Texture* hangManImage = mainGraphic.loadTexture(findImage(badGuessCount).c_str());
    mainGraphic.renderTexture(hangManImage, hangMan_x, hangMan_y, hangMan_w, hangMan_h);
    mainGraphic.presentScene();

    //creat word
    word = createWord();
    blankWord= creatBlankWord((int)word.length(), '-');

    bool done = false;

    while (badGuessCount != 7){

        SDL_RenderClear(mainGraphic.renderer);

        char guess = guessWord(mainGraphic, hangManImage, blankWord);

        if (checkGuess(guess, word, blankWord) == 0){
            badGuessCount++;
            SDL_RenderClear(mainGraphic.renderer);
            draw(badGuessCount, mainGraphic, &hangManImage);
            renderText(mainGraphic, Sans, White, blankWord.c_str(),
                       blankWord_x, blankWord_y, blankWord_h, 1);
            mainGraphic.presentScene();
        }

        else {
            SDL_RenderClear(mainGraphic.renderer);
            mainGraphic.renderTexture(hangManImage, hangMan_x, hangMan_y, hangMan_w, hangMan_h);
            updateBlankWord(guess, word, blankWord);
            renderText(mainGraphic, Sans, White, blankWord.c_str(),
                       blankWord_x, blankWord_y, blankWord_h, 1);
            mainGraphic.presentScene();
            if (blankWord == word){
                SDL_RenderClear(mainGraphic.renderer);
                renderText(mainGraphic, Sans, White, win, 0, result_y, result_h, 1);
                mainGraphic.presentScene();
                mainGraphic.pressAnyKeyToContinue();
                return;
            }
        }

    }
    SDL_RenderClear(mainGraphic.renderer);
    renderText(mainGraphic, Sans, White, lose, 0, result_y, result_h, 1);
    mainGraphic.presentScene();
    mainGraphic.pressAnyKeyToContinue();

    cout << word <<'\n';

}

#endif // _LAUNCH__H
