#ifndef _DEFS__H
#define _DEFS__H

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
#define WINDOW_TITLE "Hello World!"

//hangman image position
const int hangMan_x = 600;
const int hangMan_y = 0;
const int hangMan_w = 200;
const int hangMan_h = 350;

//warning position
#define WARN "Warning: Turn off Vietkey"s
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
#define STARTC ">START"
#define START "START"
const int start_y = 300;
const int start_h = 25;

//Menu button position
#define SETTINGC ">SETTING"
#define SETTING "SETTING"
const int menu_y = 350;
const int menu_h = 25;

//Font
#define fontFile "Lato-Black.ttf"
const int fontSize = 72;

//Result position
#define WIN "YOU WON"
#define LOSE "YOU LOSED"
const int result_y = 250;
const int result_h = 100;

//resultWord position
const int word_y = 375;
const int word_h = 50;

//mainMenuName
#define NAME "HANG MAN"
const int name_y = 150;
const int name_h = 100;

#endif // _DEFS__H
