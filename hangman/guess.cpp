#include "guess.h"

//check type of char
int type(const char chr){

    if ('a'<= chr && chr<='z') return 1;
    if ('A'<= chr && chr<='Z') return 2;
    return 0;

}

//input guessWord
char guessWord(Graphics mainGraphic, SDL_Texture* hangManImage, string blankWord, bool& check){

    string guess;

    bool done = false;

    //build font and color
    TTF_Font* Sans = TTF_OpenFont(fontFile, fontSize);
    SDL_Color White = {255,255,255};

    SDL_StartTextInput();
    //done = true -> out
    while(!done){
        SDL_Event event;
        if (SDL_PollEvent(&event)){

            switch (event.type){

                case SDL_TEXTINPUT:{
                    //text input -> guess
                    guess = event.text.text;

                    //UPPERCASE
                    if (type(guess[0]) == 1) guess[0]+='A'-'a';

                    //clear present screen
                    SDL_RenderClear(mainGraphic.renderer);

                    // print what you input & present hangManImage what was cleared be4
                    renderText(mainGraphic, Sans, White, blankWord.c_str(),
                               blankWord_x, blankWord_y, blankWord_h, 1);
                    mainGraphic.renderTexture(hangManImage, hangMan_x, hangMan_y, hangMan_w, hangMan_h);
                    renderText(mainGraphic, Sans, White, guess.c_str(), chr_x, chr_y, chr_h, 1);

                    //warning some strange char
                    if(type(guess[0]) == 0)
                       renderText(mainGraphic, Sans, White, WARN.c_str(), warn_x, warn_y, warn_h, 0);

                    mainGraphic.presentScene();
                    break;
                }

                //press ENTER to get text input and end the loop
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RETURN) done= true;
                    break;

                //press X in the window to turn off the game
                case SDL_QUIT:
                    check = true;
                    done = true;
                    break;

            }


        }
    }
    //lowercase and return
    return guess[0]-'A'+'a';

}

//check
int checkGuess(const char guess, const string word, const string blankWord){

    for (int i=0; i<(int)word.length(); i++){
        if (guess== word[i] && blankWord[i]=='-') return 1;
    }
    return 0;

}

//update when guessWord correct
void updateBlankWord(const char guess, const string word, string& blankWord){

    for (int i=0; i<(int)blankWord.length(); i++){
        if (blankWord[i]=='-' && word[i]==guess) blankWord[i]=guess;
    }

}

