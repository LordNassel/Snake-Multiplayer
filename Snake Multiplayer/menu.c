#include "menu.h"
#include "map.h"
#include "snake.h"
#include "controls.h"
#include "scoreboard.h"

SDL_Color black = {0, 0, 0}, red = {255, 0, 0}, white = {255,255,255};


void logo_drawing(SDL_Renderer *renderer, SDL_Texture *logo, int x, int y){
    SDL_Rect src  = {0,0,200,200};
    SDL_Rect dest = {x,y,200,200};
    SDL_RenderCopy(renderer, logo, &src, &dest);
}

void picture_drawing(SDL_Renderer *renderer, SDL_Texture *picture, int x, int y){
    SDL_Rect src  = {0,0,640,400};
    SDL_Rect dest = {x,y,640,400};
    SDL_RenderCopy(renderer, picture, &src, &dest);
    SDL_RenderPresent(renderer);
}

void shaded_text_red(SDL_Renderer *renderer, int where, const char* title){
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("LiberationSerif-Regular.ttf", 64); ///Text hight = 64
    if (!font) {
        SDL_Log("Font could not be opened! %s\n", TTF_GetError());
        exit(1);
    }
    SDL_Surface *felirat;
    SDL_Texture *felirat_t;
    SDL_Rect hova = { 0, 0, 0, 0 };

    felirat = TTF_RenderUTF8_Shaded(font, title, black,red);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = (1920 - felirat->w) / 2;
    hova.y = where;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);
    TTF_CloseFont(font);
}

void shaded_text_white(SDL_Renderer *renderer, int where, const char* title){
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("LiberationSerif-Regular.ttf", 64); ///Text hight = 64
    if (!font) {
        SDL_Log("Font could not be opened! %s\n", TTF_GetError());
        exit(1);
    }
    SDL_Surface *felirat;
    SDL_Texture *felirat_t;
    SDL_Rect hova = { 0, 0, 0, 0 };

    felirat = TTF_RenderUTF8_Shaded(font, title, black,white);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = (1920 - felirat->w) / 2;
    hova.y = where;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);
    TTF_CloseFont(font);
}

void draw_all(){
    ///Draws everything into default set

    ///Loading Logos
    SDL_Texture *logo_UL= IMG_LoadTexture(renderer, "snake_up_left.png");
    if (logo_UL == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *logo_UR= IMG_LoadTexture(renderer, "snake_up_right.png");
    if (logo_UR == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *logo_DR= IMG_LoadTexture(renderer, "snake_down_right.png");
    if (logo_DR == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *logo_DL= IMG_LoadTexture(renderer, "snake_down_left.png");
    if (logo_DL == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }

    ///Choosing map
    SDL_Texture *picA= IMG_LoadTexture(renderer, "minidone0.png");
    if (picA == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *picB= IMG_LoadTexture(renderer, "minidone1.png");
    if (picB == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *picC= IMG_LoadTexture(renderer, "minidone2.png");
    if (picC == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }

    ///Drawing Picture
    boxRGBA(renderer, 0, 0, 1920, 1080, 0xFF, 0xFF, 0xFFF, 0xFF); //RGBA Colors
    logo_drawing(renderer, logo_UL, 0,0);
    logo_drawing(renderer, logo_UR, 1720,0);
    logo_drawing(renderer, logo_DR, 1720,880);
    logo_drawing(renderer, logo_DL, 0,880);

    ///Welcome Text
    shaded_text_red(renderer,50,"SNAKE MULTIPLAYER");

    ///Start Picture
    picture_drawing(renderer, picA, 640,164);

    ///L
    filledTrigonRGBA(renderer, 490, 364, 590, 314, 590, 414, 0xFF, 0x00, 0x00, 0xFF);
    ///R
    filledTrigonRGBA(renderer, 1430, 364, 1330, 314, 1330, 414, 0xFF, 0x00, 0x00, 0xFF);


    ///Middle Text
    shaded_text_red(renderer, 614, "Single Player");
    shaded_text_white(renderer, 728, "Multi Player");
    shaded_text_white(renderer, 842, "Scoreboard");
    shaded_text_white(renderer, 956, "Controls");

    ///Exit Text
    blended_text_blck(renderer,1920,1048,"Press F1 for EXIT",16);

    SDL_RenderPresent(renderer);
}

void sdl_start_menu(){

    ///Loading Logos
    SDL_Texture *logo_UL= IMG_LoadTexture(renderer, "snake_up_left.png");
    if (logo_UL == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *logo_UR= IMG_LoadTexture(renderer, "snake_up_right.png");
    if (logo_UR == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *logo_DR= IMG_LoadTexture(renderer, "snake_down_right.png");
    if (logo_DR == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *logo_DL= IMG_LoadTexture(renderer, "snake_down_left.png");
    if (logo_DL == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }

    ///Choosing map
    SDL_Texture *picA= IMG_LoadTexture(renderer, "minidone0.png");
    if (picA == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *picB= IMG_LoadTexture(renderer, "minidone1.png");
    if (picB == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *picC= IMG_LoadTexture(renderer, "minidone2.png");
    if (picC == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }

    ///
    draw_all();
    ///

    ///Bool Declaration
    bool quit = false;
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool enter = false;
    bool numpad_enter = false;
    bool rajz = true;

    ///Struct "todo" Declaration
    todo visszater;
    visszater.vertical=0;
    visszater.horisontal=0;
    visszater.exit=false;

    ///Other Declaration
    int horisontal_counter=0, vertical_counter=0;

    while (!quit) {

        if (rajz) {
            if (left){
                filledTrigonRGBA(renderer, 490, 364, 590, 314, 590, 414, 0x00, 0xC0, 0x00, 0xFF);
                horisontal_counter = horisontal_counter - 1;
            }
            else filledTrigonRGBA(renderer, 490, 364, 590, 314, 590, 414, 0xFF, 0x00, 0x00, 0xFF);

            if (right){
                filledTrigonRGBA(renderer, 1430, 364, 1330, 314, 1330, 414, 0x00, 0xC0, 0x00, 0xFF);
                horisontal_counter = horisontal_counter + 1;
            }
            else filledTrigonRGBA(renderer, 1430, 364, 1330, 314, 1330, 414, 0xFF, 0x00, 0x00, 0xFF);


            if (up) vertical_counter = vertical_counter - 1;
            if (down) vertical_counter = vertical_counter + 1;


            if(vertical_counter==0) vertical_counter=4;
            if(vertical_counter>=4) vertical_counter=0;
            if(horisontal_counter==0) horisontal_counter=3;
            if(horisontal_counter>=3) horisontal_counter=0;

            ///Single Player
            if(vertical_counter==0){
            shaded_text_red(renderer, 614, "Single Player");
            shaded_text_white(renderer, 728, "Multi Player");
            shaded_text_white(renderer, 842, "Scoreboard");
            shaded_text_white(renderer, 956, "Controls");
            visszater.vertical=0;
                if(enter || numpad_enter){
                visszater.exit=true;
            }
            }

            ///Multi Player
            if(vertical_counter==1){
            shaded_text_white(renderer, 614, "Single Player");
            shaded_text_red(renderer, 728, "Multi Player");
            shaded_text_white(renderer, 842, "Scoreboard");
            shaded_text_white(renderer, 956, "Controls");
            visszater.vertical=1;
                if(enter || numpad_enter){
                visszater.exit=true;
            }
            }

            ///Scoreboard
            if(vertical_counter==2){
            shaded_text_white(renderer, 614, "Single Player");
            shaded_text_white(renderer, 728, "Multi Player");
            shaded_text_red(renderer, 842, "Scoreboard");
            shaded_text_white(renderer, 956, "Controls");
            visszater.vertical=2;
            if(enter || numpad_enter){
                show_scoreboard();
                draw_all();
                horisontal_counter=0;
                vertical_counter=0;
                enter=false;
                numpad_enter=false;
            }
            }

            ///Controls
            if(vertical_counter==3){
            shaded_text_white(renderer, 614, "Single Player");
            shaded_text_white(renderer, 728, "Multi Player");
            shaded_text_white(renderer, 842, "Scoreboard");
            shaded_text_red(renderer, 956, "Controls");
            visszater.vertical=3;
            if(enter || numpad_enter){
                show_controls();
                draw_all();
                horisontal_counter=0;
                vertical_counter=0;
                enter=false;
                numpad_enter=false;
            }
            }

            ///Map 0
            if(horisontal_counter==0){
            picture_drawing(renderer, picA, 640,164);
            visszater.horisontal=0;
            }

            ///Map 1
            if(horisontal_counter==1){
            picture_drawing(renderer, picB, 640,164);
            visszater.horisontal=1;
            }

            ///Map 2
            if(horisontal_counter==2){
            picture_drawing(renderer, picC, 640,164);
            visszater.horisontal=2;
            }
            SDL_RenderPresent(renderer);
            rajz = false;
        }

        while(visszater.exit){
        ///Single player & MAP0
        if(visszater.horisontal==0 && visszater.vertical==0){
            map0(1);
            show_scoreboard();
            draw_all();
            visszater.vertical=0;
            visszater.horisontal=0;
            enter=false;
            numpad_enter=false;
            visszater.exit=false;
            }
        ///Single player & MAP1
        if(visszater.horisontal==1 && visszater.vertical==0){
            map1(1);
            show_scoreboard();
            draw_all();
            visszater.vertical=0;
            visszater.horisontal=0;
            enter=false;
            numpad_enter=false;
            visszater.exit=false;
            }
        ///Single player & MAP2
        if(visszater.horisontal==2 && visszater.vertical==0){
            map2(1);
            show_scoreboard();
            draw_all();
            visszater.vertical=0;
            visszater.horisontal=0;
            enter=false;
            numpad_enter=false;
            visszater.exit=false;
            }
        ///Multi player & MAP0
        if(visszater.horisontal==0 && visszater.vertical==1){
            map0(2);
            show_scoreboard();
            draw_all();
            visszater.vertical=0;
            visszater.horisontal=0;
            enter=false;
            numpad_enter=false;
            visszater.exit=false;
            }
        ///Multi player & MAP1
        if(visszater.horisontal==1 && visszater.vertical==1){
            map1(2);
            show_scoreboard();
            draw_all();
            visszater.vertical=0;
            visszater.horisontal=0;
            enter=false;
            numpad_enter=false;
            visszater.exit=false;
            }
        ///Multi player & MAP2
        if(visszater.horisontal==2 && visszater.vertical==1){
            map2(2);
            show_scoreboard();
            draw_all();
            visszater.vertical=0;
            visszater.horisontal=0;
            enter=false;
            numpad_enter=false;
            visszater.exit=false;
            }
        }

        SDL_Event event;
        SDL_WaitEvent(&event);

        switch (event.type) {
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT: left = false; rajz = true; break;
                    case SDLK_RIGHT: right = false; rajz = true; break;
                    case SDLK_UP: up = false; rajz = true; break;
                    case SDLK_DOWN: down = false; rajz = true; break;
                    case SDLK_RETURN: enter=false; rajz = true; break;
                    case SDLK_KP_ENTER: numpad_enter=false; rajz=true; break;
                    case SDLK_F1: quit = true; break;
                }
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT: left = true; rajz = true; break;
                    case SDLK_RIGHT: right = true; rajz = true; break;
                    case SDLK_UP: up = true; rajz = true; break;
                    case SDLK_DOWN: down = true; rajz = true; break;
                    case SDLK_RETURN: enter=true; rajz = true; break;
                    case SDLK_KP_ENTER: numpad_enter=true; rajz=true; break;
                    case SDLK_F1: quit = false; break;
                }
                break;

            case SDL_QUIT:
                visszater.exit=false;
                quit = true;
                break;
        }
    }
    ///Cleaning Memory
    SDL_DestroyTexture(logo_UL);
    SDL_DestroyTexture(logo_UR);
    SDL_DestroyTexture(logo_DR);
    SDL_DestroyTexture(logo_DL);

    SDL_DestroyTexture(picA);
    SDL_DestroyTexture(picB);
    SDL_DestroyTexture(picC);
}
