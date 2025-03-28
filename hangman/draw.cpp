#include "draw.h"

//image link
string findImage(const int badGuess){

    return "image\\hangman\\" + std::to_string(badGuess) + ".jpg";

}

//render hangman
void draw(const int badGuess, Graphics& mainGraphic, SDL_Texture** hangManImage){

    *hangManImage = mainGraphic.loadTexture(findImage(badGuess).c_str());
    mainGraphic.renderTexture(*hangManImage, hangMan_x, hangMan_y, hangMan_w, hangMan_h);
    mainGraphic.presentScene();

}
