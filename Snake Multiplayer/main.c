///Snake Multiplayer with SDL2 Graphics
///Author: Gabor Levai

///When I wrote this, only God and I understood what I was doing
///Now, God only knows


#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "menu.h"
#include "map.h"
#include "snake.h"
#include "controls.h"
#include "scoreboard.h"
#include "debugmalloc.h"

#define _CRT_SECURE_NO_WARNINGS

///Initializing Program Window
void sdl_init(const char* title, int szeles, int magas, SDL_Window **pwindow, SDL_Renderer **prenderer){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("SDL opening failed: %s", SDL_GetError());
        exit(1);
    }
    SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, szeles, magas, 0);
    if (window == NULL) {
        SDL_Log("Window opening failed: %s", SDL_GetError());
        exit(1);
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_Log("Rendered opening failed: %s", SDL_GetError());
        exit(1);
    }
    SDL_RenderClear(renderer);

    *pwindow = window;
    *prenderer = renderer;
}


///Main Program
int main(int argc, char *argv[]){

    printf("\nWelcome!");

    ///Creating Window
    sdl_init("Snake Multiplayer", 1920, 1080, &window, &renderer); ///1920 1080 "Snake Multiplayer",
    sdl_start_menu();

    printf("\nThank you for playing Snake Multiplayer!\n");


    ///Close for RightUp X
    /*SDL_Event ev;
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {
    }*/
    SDL_Quit();
    return 0;
}

/*Imperial-class Star Destroyer*/
/*
                  _        .                          .            +
                 (_)        .       .                                     .
  .        ____.--^.
   .      /:  /    |                               +           .         .
         /:  `--=--'   .                                                .
        /: __[\==`-.___          *           .
       /__|\ _~~~~~~   ~~--..__            .             .
       \   \|::::|-----.....___|~--.                                 .
        \ _\_~~~~~-----:|:::______//---...___
    .   [\  \  __  --     \       ~  \_      ~~~===------==-...____
        [============================================================-
        /         __/__   --  /__    --       /____....----''''~~~~      .
  *    /  /   ==           ____....=---='''~~~~ .
      /____....--=-''':~~~~                      .                .
      .       ~--~         Kuat Drive Yard's Imperial-class Star Destroyer

*/
