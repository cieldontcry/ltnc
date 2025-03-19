#ifndef _GUESS__H
#define _GUESS__H

#include <string>

char guessWord(){

    string guess;
    char *composition;
    int cursor;
    int selection_len;

    bool done = false;

    SDL_StartTextInput();
    while(!done){
        SDL_Event event;
        if (SDL_PollEvent(&event)){

            switch (event.type){

                case SDL_TEXTINPUT:
                    guess = event.text.text;
                    break;

                case SDL_TEXTEDITING:
                    composition = event.edit.text;
                    cursor = event.edit.start;
                    selection_len = event.edit.length;
                    break;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RETURN) done= true;
                    break;

            }
        }
    }
    cout << guess[0] << endl;
    return guess[0];

}

int checkGuess(const char guess, const string word, const string blankWord){

    for (int i=0; i<(int)word.length(); i++){
        if (guess== word[i] && blankWord[i]=='-') return 1;
    }
    return 0;

}

void updateBlankWord(const char guess, const string word, string& blankWord){

    for (int i=0; i<(int)blankWord.length(); i++){
        if (blankWord[i]=='-' && word[i]==guess) blankWord[i]=guess;
    }

}

#endif // _GUESS__H
