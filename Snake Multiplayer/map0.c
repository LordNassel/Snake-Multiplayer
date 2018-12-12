#include "menu.h"
#include "map.h"
#include "snake.h"
#include "controls.h"
#include "scoreboard.h"


void picture_drawing_BIG(SDL_Renderer *renderer, SDL_Texture *picture, int x, int y){
    SDL_Rect src  = {0,0,1920,1080};
    SDL_Rect dest = {x,y,1920,1080};
    SDL_RenderCopy(renderer, picture, &src, &dest);
    SDL_RenderPresent(renderer);
}

wall *draw_map0(){
    wall *startlist = NULL;
    wall adat;

    ///0
    adat.x0 = 0;
    adat.x1 = 20;
    adat.x2 = 20;
    adat.x3 = 0;
    adat.y0 = -20;
    adat.y1 = -20;
    adat.y2 = 0;
    adat.y3 = 0;

    for(int i=0; i<54; i++){
    adat.y0+=20;
    adat.y1+=20;
    adat.y2+=20;
    adat.y3+=20;
    startlist=draw_map_injection(startlist, adat);
    }
    ///1
    adat.x0 = 0;
    adat.x1 = 20;
    adat.x2 = 20;
    adat.x3 = 0;
    adat.y0 = 0;
    adat.y1 = 0;
    adat.y2 = 20;
    adat.y3 = 20;

    for(int j=0; j<96; j++){
    adat.x0+=20;
    adat.x1+=20;
    adat.x2+=20;
    adat.x3+=20;
    startlist=draw_map_injection(startlist,adat);
    }

    ///2
    adat.x0 = 1900;
    adat.x1 = 1920;
    adat.x2 = 1920;
    adat.x3 = 1900;
    adat.y0 = 0;
    adat.y1 = 0;
    adat.y2 = 20;
    adat.y3 = 20;

    for(int i=0; i<54; i++){
    adat.y0+=20;
    adat.y1+=20;
    adat.y2+=20;
    adat.y3+=20;
    startlist=draw_map_injection(startlist,adat);
    }

    ///3
    adat.x0 = 0;
    adat.x1 = 20;
    adat.x2 = 20;
    adat.x3 = 0;
    adat.y0 = 1060;
    adat.y1 = 1080;
    adat.y2 = 1060;
    adat.y3 = 1080;

    for(int j=0; j<96; j++){
    adat.x0+=20;
    adat.x1+=20;
    adat.x2+=20;
    adat.x3+=20;
    startlist=draw_map_injection(startlist,adat);
    }

    return startlist;
}

wall *draw_map_injection(wall *begin, wall adat){

    wall *new_element = (wall*)malloc(sizeof(wall));
        new_element->x0=adat.x0;
        new_element->x1=adat.x1;
        new_element->x2=adat.x2;
        new_element->x3=adat.x3;
        new_element->y0=adat.y0;
        new_element->y1=adat.y1;
        new_element->y2=adat.y2;
        new_element->y3=adat.y3;

        new_element->next=begin;

    return new_element;
}

void generate_map0(wall *wall0){
    wall *moving = wall0;

for(moving=wall0; moving!=NULL; moving=moving->next){
    SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
    SDL_Rect rect = {moving->x0, moving->y0, 20, 20}; /// x, y, width, height
    SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));
}

SDL_RenderPresent(renderer);
}

food* make_food(food *lunch, wall *wall0, snake *snake_one){

    food *startlist_food = NULL;
    int xcoord, ycoord;
    wall *movingw;
    snake *movings;
    bool utkozes=true;

    while(utkozes){
        ///We only move on 20x20 Matrix
        xcoord = 20 * (rand() % 96);
        ycoord = 20 * (rand() % 54);

        utkozes=false;
        ///SNAKE Collosion with Wall
        for(movingw=wall0; movingw!=NULL; movingw=movingw->next){
            if((movingw->x0 == xcoord) && (movingw->y0 == ycoord)) utkozes=true;
        }
        ///SNAKE Collosion with Food
        for(movings=snake_one; movings!=NULL; movings=movings->next){
            if((movings->x0 == xcoord) && (movings->y0 == ycoord)) utkozes=true;
        }

    }
    startlist_food = generate_food_injection(lunch, xcoord, ycoord);
    return startlist_food;
}

food* make_food_for2(food* lunch, wall *wall0, snake *snake_one,snake *snake_two){

    food *startlist_food = NULL;
    int xcoord, ycoord;
    wall *movingw;
    snake *movings;
    snake *movings2;
    bool utkozes=true;

    while(utkozes){
        ///We only move on 20x20 Matrix
        xcoord = 20 * (rand() % 96);
        ycoord = 20 * (rand() % 54);

        utkozes=false;
        ///SNAKE Collosion with Wall
        for(movingw=wall0; movingw!=NULL; movingw=movingw->next){
            if((movingw->x0 == xcoord) && (movingw->y0 == ycoord)) utkozes=true;
        }
        ///SNAKE1 Collosion with Food
        for(movings=snake_one; movings!=NULL; movings=movings->next){
            if((movings->x0 == xcoord) && (movings->y0 == ycoord)) utkozes=true;
        }
        ///SNAKE2 Collosion with Food
        for(movings2=snake_two; movings2!=NULL; movings2=movings2->next){
            if((movings2->x0 == xcoord) && (movings2->y0 == ycoord)) utkozes=true;
        }
    }
    startlist_food = generate_food_injection(lunch, xcoord, ycoord);
    return startlist_food;

}

food* generate_food_injection(food *begin, int xcoord, int ycoord){

    food *new_element = (food*)malloc(sizeof(food));

        new_element->x=xcoord;
        new_element->y=ycoord;

        new_element->next=begin;

    return new_element;
}

void show_food(food* lunch){
SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
SDL_Rect rect = {lunch->x, lunch->y, 20, 20}; /// x, y, width, height
SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0x00));
SDL_RenderPresent(renderer);
}

bool collosion_detection_wall(snake *snake_one, wall *wall0){
    wall *movingw;
    snake *movings, *snake_last;
    bool collosion=false;
    for(movings=snake_one; movings!=NULL; movings=movings->next){
        snake_last = movings;
    }
    for(movingw=wall0; movingw!=NULL; movingw=movingw->next){
         if((movingw->x0 == snake_last->x0) && (movingw->y0 == snake_last->y0)) collosion=true;
        }
    return collosion;
}

bool collosion_detection_snakeitself(snake *snake_one){
    snake *movings, *snake_last;
    int i=0, j;
    bool collosion=false;
    for(movings=snake_one; movings!=NULL; movings=movings->next){
        snake_last = movings; i++;
    }
    for(movings=snake_one, j=0; movings!=NULL, j<i-1; movings=movings->next, j++){
         if((movings->x0 == snake_last->x0) && (movings->y0 == snake_last->y0)) collosion=true;
        }
    return collosion;
}

bool collosion_detection_othersnake(snake *snake_one, snake *snake_two){
    snake *movings, *snake_last;
    bool collosion = false;
    for(movings=snake_one; movings!=NULL; movings=movings->next){
        snake_last = movings;
    }
    for(movings=snake_two; movings!=NULL; movings=movings->next){
         if((movings->x0 == snake_last->x0) && (movings->y0 == snake_last->y0)) collosion=true;
        }
    return collosion;
}

bool collosion_detection_food(food *lunch, snake *snake_one){
    snake *movings, *snake_last;
    bool collosion = false;
    for(movings=snake_one; movings!=NULL; movings=movings->next){
        snake_last = movings;
    }
    if((snake_last->x0 == lunch->x) && (snake_last->y0 == lunch->y)) collosion=true;
    return collosion;
}

void single_player_scoretofile(snake *snake_one){
    snake *movings;
    int length_of_snake=0;
    for(movings=snake_one; movings!=NULL; movings=movings->next)length_of_snake++;

    length_of_snake-=20; ///Snakes will be always the min. length of 20
    int gamenum = countlines("results.txt");

    FILE *fp = fopen("results.txt","a");
    if (fp == NULL) printf("\nError at opening file!");
    fprintf(fp, "\n%d %d %d",gamenum, length_of_snake, 0);
    fclose(fp);
}

void multi_player_scoretofile(snake *snake_one, snake *snake_two){
    snake *movings;
    int length_of_snake1=0, length_of_snake2=0;
    int gamenum=0;
    for(movings=snake_one; movings!=NULL; movings=movings->next)length_of_snake1++;
    for(movings=snake_two; movings!=NULL; movings=movings->next)length_of_snake2++;
    length_of_snake1-=20; ///Snakes will be always the min. length of 20
    length_of_snake2-=20;
    gamenum = countlines("results.txt");

    FILE *fp = fopen("results.txt","a");
    if (fp == NULL) printf("\nError at opening file!");
    fprintf(fp, "\n%d %d %d",gamenum, length_of_snake1, length_of_snake2);
    fclose(fp);
}

Uint32 idozit(Uint32 ms, void *param) {
    SDL_Event ev;
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
    return ms;  ///Wait again
}

void map0(int users){

///Variables used in this C code
food *lunch = NULL;
wall *wall0;

    if(users==1){
            ///Generating Wallpaper
            SDL_Texture *picD= IMG_LoadTexture(renderer, "wallpaper0.png");
            if (picD == NULL) {
                SDL_Log("Picture could not be opened: %s", IMG_GetError());
                exit(1);
            }
            ///Generating WALL0
            wall0=draw_map0();

            ///Setting Wallpaper
            picture_drawing_BIG(renderer, picD, 0,0);

            ///Setting Map
            generate_map0(wall0);

            ///Player One
            bool second_left = false;
            bool second_right = false;
            bool second_up = false;
            bool second_down = false;
            snake1();


            bool quit = false;
            time_t t;

            control boss;
            boss.down=false;
            boss.up=true;
            boss.left=false;
            boss.right=false;

            srand((unsigned) time(&t));
            ///Generating Food
            lunch = make_food(lunch, wall0, snake_one);
            ///Setting Food
            show_food(lunch);

            ///Give Timing///
            SDL_TimerID id = SDL_AddTimer(1000, idozit, NULL);

                while (!quit) {
                SDL_Event event;
                SDL_WaitEvent(&event);

                ///SNAKE IN GAME MANIPULATION BEGINS!!!

                if(second_up){
                    boss.down=false;
                    boss.up=true;
                    boss.left=false;
                    boss.right=false;
                }
                if(second_left){
                    boss.down=false;
                    boss.up=false;
                    boss.left=true;
                    boss.right=false;
                }
                if(second_down){
                    boss.down=true;
                    boss.up=false;
                    boss.left=false;
                    boss.right=false;
                }
                if(second_right){
                    boss.down=false;
                    boss.up=false;
                    boss.left=false;
                    boss.right=true;
                }

                ///For the continuous  moving:
                remove_snake0(snake_one);

                control_snake(snake_one,boss);

                generate_snake0(snake_one);
                SDL_RenderPresent(renderer);

                ///SNAKE COLLOSION WITH WALL //IT WORKS!
                if(collosion_detection_wall(snake_one, wall0)==true){
                        single_player_scoretofile(snake_one);
                        quit = true;
                        break;
                }
                ///SNAKE COLLOSION DETECTION WITH SNAKE ITSELF //IT WORKS!
                if(collosion_detection_snakeitself(snake_one)==true){
                        single_player_scoretofile(snake_one);
                        quit = true;
                        break;
                }

                ///SNAKE COLLOSION WITH FOOD // IT WORKS!
                if(collosion_detection_food(lunch,snake_one)==true){
                    ///GROWING SNAKE (+1)
                    snake_one = build_snake_injection(snake_one);
                    ///Generating Food
                    lunch = make_food(lunch, wall0, snake_one);
                    ///Setting Food
                    show_food(lunch);
                }

                ///SNAKE IN GAME MANIPULATION ENDS!!!

                switch (event.type) {
                    case SDL_USEREVENT:
                    break;

                    case SDL_KEYUP:
                        switch (event.key.keysym.sym) {
                            case SDLK_w: second_up = false; break;
                            case SDLK_a: second_left = false; break;
                            case SDLK_s: second_down = false; break;
                            case SDLK_d: second_right = false; break;

                            case SDLK_F1: quit = true; break;
                        }
                        break;

                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym) {
                            case SDLK_w: second_up = true; break;
                            case SDLK_a: second_left = true; break;
                            case SDLK_s: second_down = true; break;
                            case SDLK_d: second_right = true; break;

                            case SDLK_F1: quit = false; break;
                        }
                        break;

                    case SDL_QUIT:
                        quit = true;
                        break;
                }
            }

            ///Closing Staff///
            wall *deletingW;
            deletingW = wall0;
            while(deletingW!=NULL){
                wall *mostaniW = deletingW->next;
                free(deletingW);
                deletingW=mostaniW;
            }
            wall0=NULL;

            snake *deletingS;
            deletingS = snake_one;
            while(deletingS!=NULL){
                snake *mostaniS=deletingS->next;
                free(deletingS);
                deletingS=mostaniS;
            }
            snake_one=NULL;

            food *deletingF;
            deletingF = lunch;
            while(deletingF!=NULL){
                food *mostaniF = deletingF->next;
                free(deletingF);
                deletingF=mostaniF;
            }
            lunch=NULL;

            SDL_DestroyTexture(picD);
            SDL_RemoveTimer(id);
        }

    if(users==2){
            ///Generating Wallpaper
            SDL_Texture *picD= IMG_LoadTexture(renderer, "wallpaper0.png");
            if (picD == NULL) {
                SDL_Log("Picture could not be opened: %s", IMG_GetError());
                exit(1);
            }
            ///Generating WALL0
            wall0=draw_map0();

            ///Setting Wallpaper
            picture_drawing_BIG(renderer, picD, 0,0);

            ///Setting Map
            generate_map0(wall0);

            ///Player Two
            bool first_left = false;
            bool first_right = false;
            bool first_up = false;
            bool first_down = false;
            snake2();

            ///Player One
            bool second_left = false;
            bool second_right = false;
            bool second_up = false;
            bool second_down = false;
            snake1();

            bool quit = false;
            time_t t;

            control boss, boss2;
            boss.down=false;
            boss.up=true;
            boss.left=false;
            boss.right=false;

            boss2.down=false;
            boss2.up=true;
            boss2.left=false;
            boss2.right=false;

            srand((unsigned) time(&t));
            ///Generating Food
            lunch = make_food_for2(lunch, wall0, snake_one, snake_two);
            ///Setting Food
            show_food(lunch);

            ///Give Timing///
            SDL_TimerID id = SDL_AddTimer(1000, idozit, NULL);

                while (!quit) {
                SDL_Event event;
                SDL_WaitEvent(&event);

                ///SNAKE IN GAME MANIPULATION BEGINS!!!

                if(second_up){
                    boss.down=false;
                    boss.up=true;
                    boss.left=false;
                    boss.right=false;
                }
                if(second_left){
                    boss.down=false;
                    boss.up=false;
                    boss.left=true;
                    boss.right=false;
                }
                if(second_down){
                    boss.down=true;
                    boss.up=false;
                    boss.left=false;
                    boss.right=false;
                }
                if(second_right){
                    boss.down=false;
                    boss.up=false;
                    boss.left=false;
                    boss.right=true;
                }


                if(first_up){
                    boss2.down=false;
                    boss2.up=true;
                    boss2.left=false;
                    boss2.right=false;

                }
                if(first_left){
                    boss2.down=false;
                    boss2.up=false;
                    boss2.left=true;
                    boss2.right=false;

                }
                if(first_down){
                    boss2.down=true;
                    boss2.up=false;
                    boss2.left=false;
                    boss2.right=false;
                }
                if(first_right){
                    boss2.down=false;
                    boss2.up=false;
                    boss2.left=false;
                    boss2.right=true;
                }

                ///A folyamatos előre léptetésért:
                remove_snake0(snake_one);
                remove_snake0(snake_two);
                control_snake(snake_one,boss);
                control_snake2(snake_two, boss2);

                generate_snake0(snake_one);
                generate_snake0(snake_two);
                SDL_RenderPresent(renderer);

                ///SNAKE COLLOSION WITH WALL //IT WORKS!
                if(collosion_detection_wall(snake_one, wall0)==true){
                        multi_player_scoretofile(snake_one, snake_two);
                        quit = true;
                        break;
                }

                if(collosion_detection_wall(snake_two, wall0)==true){
                        multi_player_scoretofile(snake_one, snake_two);
                        quit = true;
                        break;
                }

                ///SNAKE COLLOSION DETECTION WITH SNAKE ITSELF
                if(collosion_detection_snakeitself(snake_one)==true){
                        multi_player_scoretofile(snake_one, snake_two);
                        quit = true;
                        break;
                }
                if(collosion_detection_snakeitself(snake_two)==true){
                        multi_player_scoretofile(snake_one, snake_two);
                        quit = true;
                        break;
                }
                ///SNAKE COLLOSION DETECTION WITH OTHER SNAKE
                if(collosion_detection_othersnake(snake_one,snake_two)==true){ ///snake1->snake2
                        multi_player_scoretofile(snake_one, snake_two);
                        quit = true;
                        break;
                }
                if(collosion_detection_othersnake(snake_two,snake_one)==true){ ///snake2->snake1
                        multi_player_scoretofile(snake_one, snake_two);
                        quit = true;
                        break;
                }

                ///SNAKE COLLOSION WITH FOOD // IT WORKS!
                if(collosion_detection_food(lunch,snake_one)==true){
                    ///GROWING SNAKE (+1)
                    snake_one = build_snake_injection(snake_one);
                    ///Generating Food
                    lunch = make_food_for2(lunch, wall0, snake_one, snake_two);
                    ///Setting Food
                    show_food(lunch);
                }

                if(collosion_detection_food(lunch,snake_two)==true){
                    ///GROWING SNAKE (+1)
                    snake_two = build_snake_injection(snake_two);
                    ///Generating Food
                    lunch = make_food_for2(lunch, wall0, snake_one, snake_two);
                    ///Setting Food
                    show_food(lunch);
                }

                ///SNAKE IN GAME MANIPULATION ENDS!!!

                switch (event.type) {
                    case SDL_USEREVENT:
                    break;

                    case SDL_KEYUP:
                        switch (event.key.keysym.sym) {
                            case SDLK_KP_8: first_up = false; break;
                            case SDLK_KP_4: first_left = false; break;
                            case SDLK_KP_5: first_down = false; break;
                            case SDLK_KP_6: first_right = false; break;

                            case SDLK_w: second_up = false; break;
                            case SDLK_a: second_left = false; break;
                            case SDLK_s: second_down = false; break;
                            case SDLK_d: second_right = false; break;

                            case SDLK_F1: quit = true; break;
                        }
                        break;

                    case SDL_KEYDOWN:
                        switch (event.key.keysym.sym) {
                            case SDLK_KP_8: first_up = true; break;
                            case SDLK_KP_4: first_left = true; break;
                            case SDLK_KP_5: first_down = true; break;
                            case SDLK_KP_6: first_right = true; break;

                            case SDLK_w: second_up = true; break;
                            case SDLK_a: second_left = true; break;
                            case SDLK_s: second_down = true; break;
                            case SDLK_d: second_right = true; break;

                            case SDLK_F1: quit = false; break;
                        }
                        break;

                    case SDL_QUIT:
                        quit = true;
                        break;
                }
            }

            ///Closing Staff///
            wall *deletingW;
            deletingW = wall0;
            while(deletingW!=NULL){
                wall *mostaniW = deletingW->next;
                free(deletingW);
                deletingW=mostaniW;
            }
            wall0=NULL;

            snake *deletingS;
            deletingS = snake_one;
            while(deletingS!=NULL){
                snake *mostaniS=deletingS->next;
                free(deletingS);
                deletingS=mostaniS;
            }
            snake_one=NULL;

            deletingS = snake_two;
            while(deletingS!=NULL){
                snake *mostaniS=deletingS->next;
                free(deletingS);
                deletingS=mostaniS;
            }
            snake_two=NULL;

            food *deletingF;
            deletingF = lunch;
            while(deletingF!=NULL){
                food *mostaniF = deletingF->next;
                free(deletingF);
                deletingF=mostaniF;
            }
            lunch=NULL;

            SDL_DestroyTexture(picD);
            SDL_RemoveTimer(id);
        }
}
