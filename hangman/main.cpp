#include<iostream>
#include "launch.h"
#include "menu.h"

using namespace std;

int main(int argv, char* args[]){

    Graphics mainGraphic;
    mainGraphic.init();
    TTF_Init();
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        mainGraphic.logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }

    Mix_Music* backGroundMusic = mainGraphic.loadMusic(BACKGROUNDMUSIC);
    mainGraphic.play(backGroundMusic);
    int volume=128;

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
                    if (checkMouse(mouse_x, mouse_y, start)) launch(mainGraphic, done);
                    if (checkMouse(mouse_x, mouse_y, menu)){
                        launchMenu(mainGraphic, done, volume);
                        Mix_VolumeMusic(volume);
                    }

            }

        }

    }

    //launch(mainGraphic);

    Mix_FreeMusic(backGroundMusic);
    backGroundMusic = NULL;

    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    mainGraphic.quit();

    return 0;

}
