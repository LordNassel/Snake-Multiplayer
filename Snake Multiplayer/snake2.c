#include "menu.h"
#include "map.h"
#include "snake.h"
#include "controls.h"
#include "scoreboard.h"

void control_snake2(snake *snake_two,control boss2){
    snake *movings = snake_two;
    snake *movings2;
    int counter = 0, move = 0;

        for(movings=snake_two->next, movings2=snake_two; movings!=NULL; /*movings2>!=NULL;*/ movings=movings->next, movings2=movings2->next){

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

    bool up = boss2.up;
    bool left = boss2.left;
    bool down = boss2.down;
    bool right = boss2.right;

    ///EZ MINDIG KIADJA A FEJNEK AZ AKTUÁLIS IRÁNYT -- ERRE MINDIG SZÜKSÉG LESZ!
    for(movings=snake_two; movings!=NULL; movings=movings->next){
        counter++;
    }
    for(movings=snake_two; movings!=NULL; movings=movings->next){
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
snake *make_snake2(){
    snake *startlist_snake = NULL;
    snake atad;

    atad.x0 = 1680;
    atad.x1 = 1700;
    atad.x2 = 1700;
    atad.x3 = 1680;
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

void snake2(){
    snake_two = make_snake2();
    generate_snake0(snake_two);
}
