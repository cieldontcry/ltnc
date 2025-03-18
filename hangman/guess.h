#ifndef _GUESS__H
#define _GUESS__H

char guessWord(){

    char guess;
    cin >> guess;
    return guess;

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
