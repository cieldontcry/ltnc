#ifndef _CREATE__H
#define _CREATE__H

#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define FILE "word.txt"

using namespace std;

//number lines of file
int fileNumberOfLines(const string fileName);

//random line of file
int rand(const int maxNum);

//get random word from fileName
string randomWord(const string fileName);

string createWord();

string creatBlankWord(const int a, const char c);

#endif // _CREATE__H
