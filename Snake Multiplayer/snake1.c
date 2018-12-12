#include "menu.h"
#include "map.h"
#include "snake.h"
#include "controls.h"
#include "scoreboard.h"

void control_snake(snake *snake_one, control boss){
    snake *movings = snake_one;
    snake *movings2;
    int counter = 0, move = 0;

        for(movings=snake_one->next, movings2=snake_one; movings!=NULL; /*movings2>!=NULL;*/ movings=movings->next, movings2=movings2->next){

        movings2->x0=movings->x0;
        movings2->x1=movings->x1;
        movings2->x2=movings->x2;
        movings2->x3=movings->x3;

        movings2->y0=movings->y0;
        movings2->y1=movings->y1;
        movings2->y2=movings->y2;
        movings2->y3=movings->y3;

        movings2->dir_u = movings->dir_u;
        movings2->dir_l = movings->dir_l;
        movings2->dir_d = movings->dir_d;
        movings2->dir_r = movings->dir_r;
        }


    {/// DIRECTION FORWARD GIVING - The ways of C works...

    bool up = boss.up;
    bool left = boss.left;
    bool down = boss.down;
    bool right = boss.right;

    ///EZ MINDIG KIADJA A FEJNEK AZ AKTUÁLIS IRÁNYT -- ERRE MINDIG SZÜKSÉG LESZ!
    for(movings=snake_one; movings!=NULL; movings=movings->next){
        counter++;
    }
    for(movings=snake_one; movings!=NULL; movings=movings->next){
        move++;
        if(move==counter){
            movings->dir_u=up;
            movings->dir_l=left;
            movings->dir_d=down;
            movings->dir_r=right;

                if(movings->dir_u == true){
                    movings->y0-=20;
                    movings->y1-=20;
                    movings->y2-=20;
                    movings->y3-=20;
                }

                if(movings->dir_l == true){
                    movings->x0-=20;
                    movings->x1-=20;
                    movings->x2-=20;
                    movings->x3-=20;
                }

                if(movings->dir_d == true){
                    movings->y0+=20;
                    movings->y1+=20;
                    movings->y2+=20;
                    movings->y3+=20;
                }

                if(movings->dir_r == true){
                    movings->x0+=20;
                    movings->x1+=20;
                    movings->x2+=20;
                    movings->x3+=20;
                }
        }
    }

    }
}

void remove_snake0(snake *snake_one){
    snake *moving = snake_one;

for(moving=snake_one; moving!=NULL; moving=moving->next){
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {moving->x0, moving->y0, 20, 20}; /// x, y, width, height
    SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00)); //BLACKOUT
}

SDL_RenderPresent(renderer);
}

void generate_snake0(snake *snake_one){
    snake *moving = snake_one;
for(moving=snake_one; moving!=NULL; moving=moving->next){
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {moving->x0, moving->y0, 20, 20}; /// x, y, width, height
    SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0x00, 0xFF, 0x00));
}

SDL_RenderPresent(renderer);
}

snake *build_snake_injection(snake *begin){
    snake *new_element = (snake*)malloc(sizeof(snake));
    snake *movings = begin;
    movings = movings->next;

    bool dir_d=movings->dir_d;
    bool dir_l=movings->dir_l;
    bool dir_r=movings->dir_r;
    bool dir_u=movings->dir_u;

    if(dir_u){

        new_element->x0=begin->x0;
        new_element->x1=begin->x1;
        new_element->x2=begin->x2;
        new_element->x3=begin->x3;

        new_element->y0=begin->y0+20;
        new_element->y1=begin->y1+20;
        new_element->y2=begin->y2+20;
        new_element->y3=begin->y3+20;
    }

    if(dir_l){

        new_element->x0=begin->x0+20;
        new_element->x1=begin->x1+20;
        new_element->x2=begin->x2+20;
        new_element->x3=begin->x3+20;

        new_element->y0=begin->y0;
        new_element->y1=begin->y1;
        new_element->y2=begin->y2;
        new_element->y3=begin->y3;
    }
    if(dir_d){

        new_element->x0=begin->x0;
        new_element->x1=begin->x1;
        new_element->x2=begin->x2;
        new_element->x3=begin->x3;

        new_element->y0=begin->y0-20;
        new_element->y1=begin->y1-20;
        new_element->y2=begin->y2-20;
        new_element->y3=begin->y3-20;
    }

    if(dir_r){

        new_element->x0=begin->x0-20;
        new_element->x1=begin->x1-20;
        new_element->x2=begin->x2-20;
        new_element->x3=begin->x3-20;

        new_element->y0=begin->y0;
        new_element->y1=begin->y1;
        new_element->y2=begin->y2;
        new_element->y3=begin->y3;
    }

        new_element->dir_d=dir_d;
        new_element->dir_u=dir_u;
        new_element->dir_l=dir_l;
        new_element->dir_r=dir_r;

        new_element->next = begin;

    return new_element;
}

snake *draw_snake_injection(snake *begin, snake atad){
    snake *new_element = (snake*)malloc(sizeof(snake));

    if(atad.dir_u){

        new_element->x0=atad.x0;
        new_element->x1=atad.x1;
        new_element->x2=atad.x2;
        new_element->x3=atad.x3;

        new_element->y0=atad.y0-20;
        new_element->y1=atad.y1-20;
        new_element->y2=atad.y2-20;
        new_element->y3=atad.y3-20;
    }
    if(atad.dir_l){

        new_element->x0=atad.x0-20;
        new_element->x1=atad.x1-20;
        new_element->x2=atad.x2-20;
        new_element->x3=atad.x3-20;

        new_element->y0=atad.y0;
        new_element->y1=atad.y1;
        new_element->y2=atad.y2;
        new_element->y3=atad.y3;
    }
    if(atad.dir_d){

        new_element->x0=atad.x0;
        new_element->x1=atad.x1;
        new_element->x2=atad.x2;
        new_element->x3=atad.x3;

        new_element->y0=atad.y0+20;
        new_element->y1=atad.y1+20;
        new_element->y2=atad.y2+20;
        new_element->y3=atad.y3+20;
    }
    if(atad.dir_r){

        new_element->x0=atad.x0+20;
        new_element->x1=atad.x1+20;
        new_element->x2=atad.x2+20;
        new_element->x3=atad.x3+20;

        new_element->y0=atad.y0;
        new_element->y1=atad.y1;
        new_element->y2=atad.y2;
        new_element->y3=atad.y3;
    }

        new_element->dir_d=atad.dir_d;
        new_element->dir_u=atad.dir_u;
        new_element->dir_l=atad.dir_l;
        new_element->dir_r=atad.dir_r;

        new_element->next = begin;

    return new_element;
}

snake *make_snake(){
    snake *startlist_snake = NULL;
    snake atad;

    atad.x0 = 220;
    atad.x1 = 240;
    atad.x2 = 240;
    atad.x3 = 220;
    atad.y0 = 540;
    atad.y1 = 540;
    atad.y2 = 560;
    atad.y3 = 560;

    atad.dir_u = true;
    atad.dir_d = false;
    atad.dir_l = false;
    atad.dir_r = false;

    for(int i=0; i<20; i++){
    atad.y0+=20;
    atad.y1+=20;
    atad.y2+=20;
    atad.y3+=20;
    startlist_snake=draw_snake_injection(startlist_snake,atad);
    }

    return startlist_snake;
}


void snake1(){
    snake_one = make_snake();
    generate_snake0(snake_one);
}
