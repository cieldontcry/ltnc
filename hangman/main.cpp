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

    while (!done){

        while (SDL_PollEvent(&event)){

            SDL_RenderClear(mainGraphic.renderer);
            renderText(mainGraphic, Sans, White, NAME, 0, name_y, name_h, 1);
            SDL_GetMouseState(&mouse_x, &mouse_y);

            rect start = textBox(mainGraphic, Sans, White, START, 0, start_y, start_h, 1);
            rect menu = textBox(mainGraphic, Sans, White, SETTING, 0, menu_y, menu_h, 1);

            if (checkMouse(mouse_x, mouse_y, start)){
                renderText(mainGraphic, Sans, White, STARTC, 0, start_y, start_h, 1);
                renderText(mainGraphic, Sans, White, SETTING, 0, menu_y, menu_h, 1);
                mainGraphic.presentScene();
            }
            else {
                renderText(mainGraphic, Sans, White, START, 0, start_y, start_h, 1);
                if (checkMouse(mouse_x, mouse_y, menu)){
                    renderText(mainGraphic, Sans, White, SETTINGC, 0, menu_y, menu_h, 1);
                    mainGraphic.presentScene();
                }
                else {
                    renderText(mainGraphic, Sans, White, SETTING, 0, menu_y, menu_h, 1);
                    mainGraphic.presentScene();
                }
            }

            switch(event.type){

                case SDL_QUIT:
                    done= true;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (checkMouse(mouse_x, mouse_y, start)) launch(mainGraphic);
                    if (checkMouse(mouse_x, mouse_y, menu)) launchMenu(mainGraphic);

            }

        }


    }

    //launch(mainGraphic);

    mainGraphic.quit();

    return 0;

}
