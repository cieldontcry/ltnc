#include<iostream>
#include "create.h"
#include "draw.h"
#include "guess.h"
#include "defs.h"
#include "launch.h"
#include "graphics.h"
#include "menu.h"

using namespace std;

int main(int argv, char* args[]){

    Graphics mainGraphic;
    mainGraphic.init();
    TTF_Init();

    bool done = false;

    TTF_Font* Sans = TTF_OpenFont(fontFile, fontSize);
    SDL_Color White = {255,255,255};

    SDL_Event event;
    int mouse_x, mouse_y;

    renderText(mainGraphic, Sans, White, startText, 0, start_y, start_h, 1);
    mainGraphic.presentScene();

    while (!done){

        while (SDL_PollEvent(&event)){

            SDL_RenderClear(mainGraphic.renderer);
            SDL_GetMouseState(&mouse_x, &mouse_y);

            rect start = textBox(mainGraphic, Sans, White, startText, 0, start_y, start_h, 1);
            rect menu = textBox(mainGraphic, Sans, White, menuText, 0, menu_y, menu_h, 1);

            if (checkMouse(mouse_x, mouse_y, start)){
                renderText(mainGraphic, Sans, White, startChosed, 0, start_y, start_h, 1);
                renderText(mainGraphic, Sans, White, menuText, 0, menu_y, menu_h, 1);
                mainGraphic.presentScene();
            }
            else {
                renderText(mainGraphic, Sans, White, startText, 0, start_y, start_h, 1);
                if (checkMouse(mouse_x, mouse_y, menu)){
                    renderText(mainGraphic, Sans, White, menuChosed, 0, menu_y, menu_h, 1);
                    mainGraphic.presentScene();
                }
                else {
                    renderText(mainGraphic, Sans, White, menuText, 0, menu_y, menu_h, 1);
                    mainGraphic.presentScene();
                }
            }

            switch(event.type){

                case SDL_QUIT:
                    done= true;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (checkMouse(mouse_x, mouse_y, start)) launch(mainGraphic);
                    //if (checkMouse(mouse_x, mouse_y, menu))

            }

        }


    }

    //launch(mainGraphic);

    mainGraphic.quit();

    return 0;

}
