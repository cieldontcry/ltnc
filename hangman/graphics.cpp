#include "graphics.h"

//Graphics function

    //Message when logError
    void Graphics::logErrorAndExit(const char* msg, const char* error){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "%s: %s", msg, error);
        SDL_Quit();
    }

    //init after declare graphic
    void Graphics::init() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());
        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr)
            logErrorAndExit("CreateWindow", SDL_GetError());
        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());
        renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED |
                                      SDL_RENDERER_PRESENTVSYNC);
        //renderer =
            SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
        if (renderer == nullptr)
            logErrorAndExit("CreateRenderer", SDL_GetError());
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    }

    //render background
    void Graphics::prepareScene(SDL_Texture * background){
        SDL_RenderClear(renderer);
        SDL_RenderCopy( renderer, background, NULL, NULL);
    }

    //present the present sence
    void Graphics::presentScene(){
        SDL_RenderPresent(renderer);
    }

    //build texture from image
    SDL_Texture* Graphics::loadTexture(const char *filename){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                       "Loading %s", filename);
        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
                SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                               "Load texture %s", IMG_GetError());
        return texture;
    }

    //build texture from text
    SDL_Texture* Graphics::loadSurface(TTF_Font *Font, const char* text, SDL_Color Color){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO,
                       "Loading %s", text);
        SDL_Surface *surface = TTF_RenderText_Solid(Font, text, Color);
        if (surface == NULL)
                SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                               "Load surface %s", IMG_GetError());
        SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surface);

        return message;
    }

    //render texture
    void Graphics::renderTexture(SDL_Texture *texture,const int x,const int y, const int w, const int h){
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        dest.w = w;
        dest.h = h;
        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }

    // Quit SDL
    void Graphics::quit(){
        IMG_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void Graphics::pressAnyKeyToContinue(){

        bool done = false;
        while (!done){
            SDL_Event event;
            while (SDL_PollEvent(&event))
                switch (event.type){
                    case SDL_KEYDOWN:
                        done = true;
                        break;
                }
        }

    }

    Mix_Music* Graphics::loadMusic(const char* path)
    {
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                           "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }
    void Graphics::play(Mix_Music *gMusic)
    {
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ) {
            Mix_ResumeMusic();
        }
    }

    Mix_Chunk* Graphics::loadSound(const char* path) {
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
        return gChunk;
    }

    void Graphics::play(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }


//render text
void renderText(Graphics mainGraphic, TTF_Font* Font, SDL_Color Color,
                const char* text, const int x, const int y, const int h, const int center){

    SDL_Surface *surface = TTF_RenderText_Solid(Font, text, Color);
    SDL_Texture *message = SDL_CreateTextureFromSurface(mainGraphic.renderer, surface);

    int w= (int)((float)surface->w / (float)surface->h * h);

    int col = x;
    //center = 1 -> print center
    if (center == 1) col= (SCREEN_WIDTH-w)/2;

    mainGraphic.renderTexture(message, col, y, w, h);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(message);
    message=NULL;

}

//find textBox of text
rect textBox(Graphics mainGraphic, TTF_Font* Font, SDL_Color Color,
              const char* text, const int x, const int y, const int h, const int center){
    SDL_Surface *surface = TTF_RenderText_Solid(Font, text, Color);

    int w= (int)((float)surface->w / (float)surface->h * h);

    int col = x;
    if (center == 1) col= (SCREEN_WIDTH-w)/2;

    rect res;
    res.x = col;
    res.y = y;
    res.w = w;
    res.h = h;
    return res;

}

//check mouse in textBox or not
int checkMouse(int x, int y, rect textBox){

    if (x<textBox.x || x>= textBox.x + textBox.w) return 0;
    if (y<textBox.y || y>= textBox.y + textBox.h) return 0;
    return 1;

}
