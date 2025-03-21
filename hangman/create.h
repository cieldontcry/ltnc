#ifndef _CREATE__H
#define _CREATE__H

#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define FILE "word.txt"

using namespace std;

//number lines of file
int fileNumberOfLines(const string fileName){

    int number=0;
    ifstream fin(fileName);
    while (!fin.eof()){
        string line;
        getline(fin, line);
        number++;
    }
    fin.close();
    return number;

}

//random line of file
int rand(const int maxNum){

    return rand() % maxNum;

}

//get random word from fileName
string randomWord(const string fileName){

    srand(time(0));
    int maxNum= fileNumberOfLines(fileName);
    int wordNumber = rand(maxNum);

    ifstream fin(fileName);
    string word;

    for (int i=0; i<wordNumber; i++){
        getline(fin, word);
    }
    fin.close();
    return word;

}

string createWord(){

    return randomWord(FILE);

}

string creatBlankWord(const int a, const char c){

    string res ="";
    for (int i=0; i<a; i++) res= res+c;
    return res;

}

#endif // _CREATE__H
