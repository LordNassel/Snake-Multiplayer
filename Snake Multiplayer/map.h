#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
///#include "debugmalloc.h"

#include "menu.h"
#include "snake.h"
#include "controls.h"
#include "scoreboard.h"

typedef struct food{
    int x,y;
    struct food *next;
}food;


typedef struct wall{
    int x0,x1,x2,x3;
    int y0,y1,y2,y3;
    struct wall *next; ///One Direction
}wall;


///Setting Wallpaper
void picture_drawing_BIG(SDL_Renderer *renderer, SDL_Texture *picture, int x, int y);

///Maps
void map0(int users);
void map1(int users);
void map2(int users);

wall *draw_map0();
wall *draw_map1(wall *wall0);
wall *draw_map2(wall *wall0);

wall *draw_map_injection(wall *begin, wall adat);

void generate_map0(wall *wall0);
void generate_map1(wall *wall1);
void generate_map2(wall *wall2);

food* make_food(food *lunch, wall *wall0, snake *snake_one);
food* make_food_for2(food* lunch, wall *wall0, snake *snake_one,snake *snake_two);
food* generate_food_injection(food *begin, int xcoord, int ycoord);
void show_food(food* lunch);

bool collosion_detection_wall(snake *snake_one, wall *wall0);
bool collosion_detection_food(food *lunch, snake *snake_one);
bool collosion_detection_snakeitself(snake *snake_one);
bool collosion_detection_othersnake(snake *snake_one, snake *snake_two);


///Score save to file
void single_player_scoretofile(snake *snake_one);
void multi_player_scoretofile(snake *snake_one, snake *snake_two);


///Timing
Uint32 idozit(Uint32 ms, void *param);

#endif // MAP_H
