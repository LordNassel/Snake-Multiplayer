#ifndef CONTROLS_H
#define CONTROLS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
///#include "debugmalloc.h"

void blended_text_black(SDL_Renderer *renderer, int whereX, int whereY, const char* title, int meret);
void show_controls();


#endif // CONTROLS_H
