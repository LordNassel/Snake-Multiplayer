#include "menu.h"
#include "map.h"
#include "snake.h"
#include "controls.h"
#include "scoreboard.h"

SDL_Color fekete = {0, 0, 0};

void blended_text_black(SDL_Renderer *renderer, int whereX, int whereY, const char* title, int meret){
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("LiberationSerif-Regular.ttf", meret); //Text hight
    if (!font) {
        SDL_Log("Font could not be opened! %s\n", TTF_GetError());
        exit(1);
    }

    SDL_Surface *felirat;
    SDL_Texture *felirat_t;
    SDL_Rect hova = { 0, 0, 0, 0 };

    felirat = TTF_RenderUTF8_Blended(font, title, fekete);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = (whereX - felirat->w) / 2;
    hova.y = whereY;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);
    TTF_CloseFont(font);
}

void show_controls(){

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

    ///Drawing Picture
    boxRGBA(renderer, 0, 0, 1920, 1080, 0xFF, 0xFF, 0xFF, 0xFF); ///RGBA Colors
    ///Title
    blended_text_black(renderer,1920,50,"CONTROLS",64);
    logo_drawing(renderer, logo_UL, 0,0);
    logo_drawing(renderer, logo_UR, 1720,0);
    logo_drawing(renderer, logo_DR, 1720,880);
    logo_drawing(renderer, logo_DL, 0,880);
    SDL_RenderPresent(renderer);



    ///Player One
    bool first_left = false;
    bool first_right = false;
    bool first_up = false;
    bool first_down = false;
    blended_text_black(renderer, 540*2,460,"Player One",32);

    ///Player Two
    bool second_left = false;
    bool second_right = false;
    bool second_up = false;
    bool second_down = false;
    blended_text_black(renderer,(540+880)*2,460,"Player Two",32);

    ///WASD
    blended_text_black(renderer,320*2,460,"W",32);
    blended_text_black(renderer,540*2,240,"A",32);
    blended_text_black(renderer,760*2,460,"S",32);
    blended_text_black(renderer,540*2,680,"D",32);

    ///NUM_8, NUM_4, NUM_5, NUM_6
    blended_text_black(renderer,(320+880)*2,460,"4",32);
    blended_text_black(renderer,(540+880)*2,240,"8",32);
    blended_text_black(renderer,(760+880)*2,460,"6",32);
    blended_text_black(renderer,(540+880)*2,680,"5",32);

    ///Press F1 to Resume
    blended_text_black(renderer,1920,1000,"Press F1 to Resume",32);

    bool quit = false;
    bool rajz = true;

    while (!quit) {
        if (rajz) {

            if (first_up)       filledTrigonRGBA(renderer, 540+880, 280, 490+880, 380, 590+880, 380, 0x00, 0xC0, 0x00, 0xFF);
            else                filledTrigonRGBA(renderer, 540+880, 280, 490+880, 380, 590+880, 380, 0x00, 0x00, 0xFF, 0xFF);

            if (first_left)     filledTrigonRGBA(renderer, 440+880, 430, 340+880, 480, 440+880, 530, 0x00, 0xC0, 0x00, 0xFF);
            else                filledTrigonRGBA(renderer, 440+880, 430, 340+880, 480, 440+880, 530, 0x00, 0x00, 0xFF, 0xFF);

            if (first_down)     filledTrigonRGBA(renderer, 490+880, 580, 540+880, 680, 590+880, 580, 0x00, 0xC0, 0x00, 0xFF);
            else                filledTrigonRGBA(renderer, 490+880, 580, 540+880, 680, 590+880, 580, 0x00, 0x00, 0xFF, 0xFF);

            if (first_right)    filledTrigonRGBA(renderer, 640+880, 430, 740+880, 480, 640+880, 530, 0x00, 0xC0, 0x00, 0xFF);
            else                filledTrigonRGBA(renderer, 640+880, 430, 740+880, 480, 640+880, 530, 0x00, 0x00, 0xFF, 0xFF);




            if (second_up)       filledTrigonRGBA(renderer, 540, 280, 490, 380, 590, 380, 0x00, 0xC0, 0x00, 0xFF);
            else                 filledTrigonRGBA(renderer, 540, 280, 490, 380, 590, 380, 0xFF, 0x00, 0x00, 0xFF);

            if (second_left)     filledTrigonRGBA(renderer, 440, 430, 340, 480, 440, 530, 0x00, 0xC0, 0x00, 0xFF);
            else                 filledTrigonRGBA(renderer, 440, 430, 340, 480, 440, 530, 0xFF, 0x00, 0x00, 0xFF);

            if (second_down)     filledTrigonRGBA(renderer, 490, 580, 540, 680, 590, 580, 0x00, 0xC0, 0x00, 0xFF);
            else                 filledTrigonRGBA(renderer, 490, 580, 540, 680, 590, 580, 0xFF, 0x00, 0x00, 0xFF);

            if (second_right)    filledTrigonRGBA(renderer, 640, 430, 740, 480, 640, 530, 0x00, 0xC0, 0x00, 0xFF);
            else                 filledTrigonRGBA(renderer, 640, 430, 740, 480, 640, 530, 0xFF, 0x00, 0x00, 0xFF);



            SDL_RenderPresent(renderer);
            rajz = false;
        }

        SDL_Event event;
        SDL_WaitEvent(&event);

        switch (event.type) {
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_KP_8: first_up = false; rajz = true; break;
                    case SDLK_KP_4: first_left = false; rajz = true; break;
                    case SDLK_KP_5: first_down = false; rajz = true; break;
                    case SDLK_KP_6: first_right = false; rajz = true; break;

                    case SDLK_w: second_up = false; rajz = true; break;
                    case SDLK_a: second_left = false; rajz = true; break;
                    case SDLK_s: second_down = false; rajz = true; break;
                    case SDLK_d: second_right = false; rajz = true; break;

                    case SDLK_F1: quit = true; break;
                }
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_KP_8: first_up = true; rajz = true; break;
                    case SDLK_KP_4: first_left = true; rajz = true; break;
                    case SDLK_KP_5: first_down = true; rajz = true; break;
                    case SDLK_KP_6: first_right = true; rajz = true; break;

                    case SDLK_w: second_up = true; rajz = true; break;
                    case SDLK_a: second_left = true; rajz = true; break;
                    case SDLK_s: second_down = true; rajz = true; break;
                    case SDLK_d: second_right = true; rajz = true; break;
                    case SDLK_F1: quit = false; break;
                }
                break;

            case SDL_QUIT:
                quit = true;
                break;
        }
    }


    SDL_DestroyTexture(logo_UL);
    SDL_DestroyTexture(logo_UR);
    SDL_DestroyTexture(logo_DR);
    SDL_DestroyTexture(logo_DL);
}
/*For the brave souls who get this far: You are the chosen ones,
the valiant knights of programming who toil away, without rest,
fixing our most awful code. To you, true saviors, kings of men,
I say this: never gonna give you up, never gonna let you down,
never gonna run around and desert you. Never gonna make you cry,
never gonna say goodbye. Never gonna tell a lie and hurt you.*/
