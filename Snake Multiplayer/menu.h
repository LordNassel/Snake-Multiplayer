#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
///#include "debugmalloc.h"

SDL_Window *window;
SDL_Renderer *renderer;

typedef struct todo{
    int vertical;       ///Choosing Menu Status
    int horisontal;     ///Choosing Map
    bool exit;
}todo;


void logo_drawing(SDL_Renderer *renderer, SDL_Texture *logo, int x, int y);
void picture_drawing(SDL_Renderer *renderer, SDL_Texture *picture, int x, int y);
void shaded_text_red(SDL_Renderer *renderer, int where, const char* title);
void shaded_text_white(SDL_Renderer *renderer, int where, const char* title);
void draw_all();

void sdl_start_menu();



#endif // MENU_H
