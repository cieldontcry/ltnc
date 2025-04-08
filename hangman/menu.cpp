#include "menu.h"
#include <iostream>
using namespace std;

int blackVolumeW(int mouse_x){

    int w = mouse_x - volume_x;
    if (w < 0 ) return 0;
    if (w > volume_w) return volume_w;
    return w;

}

void launchMenu(Graphics& mainGraphic, bool& done, int& volume){

    TTF_Font* Sans = TTF_OpenFont(fontFile, fontSize);
    SDL_Color White = {255,255,255};

    SDL_RenderClear(mainGraphic.renderer);

    bool done1= false;
    bool check= false;

    SDL_Event event;

    rect volumeBox;
    volumeBox.x = volume_x;
    volumeBox.y = volume_y;
    volumeBox.w = volume_w;
    volumeBox.h = volume_h;

    SDL_Texture* volumeBarBlack = mainGraphic.loadTexture(VOLUMEBLACK);
    SDL_Texture* volumeBarWhite = mainGraphic.loadTexture(VOLUMEWHITE);

    int mouse_x, mouse_y;
    int tempVolume = volume*volume_w / 128;

    while (!done1){

        while (SDL_PollEvent(&event)){

            SDL_RenderClear(mainGraphic.renderer);
            SDL_GetMouseState(&mouse_x, &mouse_y);
            mainGraphic.renderTexture(volumeBarWhite, volume_x-2, volume_y-2, volume_w+4, volume_h+4);
            renderText(mainGraphic, Sans, White, TEXTVOLUME, 0, textVolume_y, textVolume_h, 1);

            if (check){
                tempVolume = blackVolumeW(mouse_x);
            }

            mainGraphic.renderTexture(volumeBarBlack, volume_x, volume_y, tempVolume, volume_h);
            rect okRect = textBox(mainGraphic, Sans, White, OK, 0, ok_y, ok_h, 1);

            if (checkMouse(mouse_x, mouse_y, okRect)) renderText(mainGraphic, Sans, White, CHOSENOK, 0, ok_y, ok_h, 1);
            else renderText(mainGraphic, Sans, White, OK, 0, ok_y, ok_h, 1);

            mainGraphic.presentScene();

            switch (event.type){
                case SDL_MOUSEBUTTONDOWN:
                    if (checkMouse(mouse_x, mouse_y, volumeBox)) check = true;
                    if (checkMouse(mouse_x, mouse_y, okRect)) done1= true;
                    break;

                case SDL_MOUSEBUTTONUP:
                    check = false;
                    break;

                case SDL_QUIT:
                    done1= true;
                    done = true;
                    break;

            }

        }

    }

    volume = (int) (tempVolume *128 / volume_w);

}
