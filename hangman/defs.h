#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* WINDOW_TITLE = "Hello World!";

//hangman image position
const int hangMan_x = 600;
const int hangMan_y = 0;
const int hangMan_w = 200;
const int hangMan_h = 350;

//warning position
const char* warn = "Warning: Turn off Vietkey";
const int warn_x = 0;
const int warn_y = 0;
const int warn_h = 25;

//char input position
const int chr_x = 350;
const int chr_y = 250;
const int chr_h = 100;

//blank word positon
const int blankWord_x = 0;
const int blankWord_y = 100;
const int blankWord_h = 50;

//Start button position
const char* startChosed = ">START";
const char* startText = "START";
const int start_y = 350;
const int start_h = 25;

//Menu button position
const char* menuChosed = ">MENU";
const char* menuText = "MENU";
const int menu_y = 400;
const int menu_h = 25;

//Font
const char* fontFile = "Lato-Black.ttf";
const int fontSize = 72;

//Result position
const char* win = "YOU WON";
const char* lose = "YOU LOSED";
const int result_y = 250;
const int result_h = 100;

#endif // _DEFS__H
