#include<iostream>
#include "create.h"
#include "draw.h"
#include "guess.h"
#include "defs.h"
#include "launch.h"
#include "graphics.h"

using namespace std;

int main(int argv, char* args[]){

    Graphics mainGraphic;
    mainGraphic.init();

    launch(mainGraphic);

    mainGraphic.quit();

    return 0;

}
