#ifndef SNAKE_H
#define SNAKE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///#include "debugmalloc.h"

#include "menu.h"
#include "map.h"
#include "controls.h"
#include "scoreboard.h"

typedef struct control{
bool up, left, down, right;
}control;


typedef struct snake{
    bool dir_u, dir_d, dir_l, dir_r;
    int x0,x1,x2,x3;
    int y0,y1,y2,y3;
    struct snake *next;
}snake;

snake *snake_one;
snake *snake_two;

snake *make_snake();
snake *make_snake2();


void generate_snake0(snake *snake_one);
void remove_snake0(snake *snake_one);
void snake1();
void snake2();
void control_snake(snake *snake_one, control boss);

snake *draw_snake_injection(snake *begin, snake atad);
snake *build_snake_injection(snake *snake_one);

#endif // SNAKE_H


