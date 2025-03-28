#include "launch.h"

//main function
void launch(Graphics& mainGraphic, bool& done){

    SDL_RenderClear(mainGraphic.renderer);

    string word;
    string blankWord;
    int badGuessCount = 0;

    TTF_Font* Sans = TTF_OpenFont(fontFile, fontSize);
    SDL_Color White = {255,255,255};

    //creat word
    word = createWord();
    blankWord= creatBlankWord((int)word.length(), '-');

    //creat a image with badGuessCount = 0
    SDL_Texture* hangManImage = mainGraphic.loadTexture(findImage(badGuessCount).c_str());
    mainGraphic.renderTexture(hangManImage, hangMan_x, hangMan_y, hangMan_w, hangMan_h);
    renderText(mainGraphic, Sans, White, blankWord.c_str(),blankWord_x, blankWord_y, blankWord_h, 1);
    mainGraphic.presentScene();

    while (badGuessCount != 7 && !done){

        SDL_RenderClear(mainGraphic.renderer);

        char guess = guessWord(mainGraphic, hangManImage, blankWord, done);

        //if wrong guess
        if (checkGuess(guess, word, blankWord) == 0){
            badGuessCount++;
            SDL_RenderClear(mainGraphic.renderer);

            //draw hangman corresponding to badGuessCount
            draw(badGuessCount, mainGraphic, &hangManImage);

            //print blankWord
            renderText(mainGraphic, Sans, White, blankWord.c_str(),
                       blankWord_x, blankWord_y, blankWord_h, 1);
            mainGraphic.presentScene();
        }

        //if right guess
        else {
            SDL_RenderClear(mainGraphic.renderer);

            //print present hangman which was cleared
            mainGraphic.renderTexture(hangManImage, hangMan_x, hangMan_y, hangMan_w, hangMan_h);
            updateBlankWord(guess, word, blankWord);

            //print blankWord
            renderText(mainGraphic, Sans, White, blankWord.c_str(),
                       blankWord_x, blankWord_y, blankWord_h, 1);
            mainGraphic.presentScene();

            //if your word was true
            if (blankWord == word){
                SDL_RenderClear(mainGraphic.renderer);

                //print you won & word
                renderText(mainGraphic, Sans, White, WIN, 0, result_y, result_h, 1);
                renderText(mainGraphic, Sans, White, word.c_str(), 0, blankWord_y, blankWord_h, 1);

                mainGraphic.presentScene();
                mainGraphic.pressAnyKeyToContinue();
                return;
            }
        }

    }

    if (done) return;

    //if your word was false
    SDL_RenderClear(mainGraphic.renderer);

    //print you lose & word
    renderText(mainGraphic, Sans, White, LOSE, 0, result_y, result_h, 1);
    renderText(mainGraphic, Sans, White, word.c_str(), 0, blankWord_y, blankWord_h, 1);

    mainGraphic.presentScene();
    mainGraphic.pressAnyKeyToContinue();

}
