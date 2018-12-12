#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
///#include "debugmalloc.h"

void blended_text_blck(SDL_Renderer *renderer, int whereX, int whereY, const char* title, int meret);
void linestoarray(char* filename, int lines, int* tomb);
void show_scoreboard();

#endif // SCOREBOARD_H
