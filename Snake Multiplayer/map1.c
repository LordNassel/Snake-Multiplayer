#include "menu.h"
#include "map.h"
#include "snake.h"
#include "controls.h"
#include "scoreboard.h"

wall *draw_map1(wall *wall0){
    wall adat;

    ///0
    adat.x0 = 460;
    adat.x1 = 480;
    adat.x2 = 480;
    adat.x3 = 460;
    adat.y0 = 260;
    adat.y1 = 260;
    adat.y2 = 280;
    adat.y3 = 280;

    for(int i=0; i<28; i++){
    adat.y0+=20;
    adat.y1+=20;
    adat.y2+=20;
    adat.y3+=20;
    wall0=draw_map_injection(wall0,adat);
    }

    ///1
    adat.x0 = 1440;
    adat.x1 = 1460;
    adat.x2 = 1460;
    adat.x3 = 1440;
    adat.y0 = 260;
    adat.y1 = 260;
    adat.y2 = 280;
    adat.y3 = 280;

    for(int j=0; j<28; j++){
    adat.y0+=20;
    adat.y1+=20;
    adat.y2+=20;
    adat.y3+=20;
    wall0=draw_map_injection(wall0,adat);
    }

    return wall0;
}

void map1(int users){

///Variables used in this C code
food *lunch = NULL;
wall *wall0;
wall *wall1;

     if(users==1){
            //Generating Wallpaper
            SDL_Texture *picD= IMG_LoadTexture(renderer, "wallpaper1.png");
            if (picD == NULL) {
                SDL_Log("Picture could not be opened: %s", IMG_GetError());
                exit(1);
            }
            //Generating WALL0
            wall0=draw_map0();
            wall1=draw_map1(wall0);

            //Setting Wallpaper
            picture_drawing_BIG(renderer, picD, 0,0);

            //Setting Map
            generate_map0(wall1);

            //Player One
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

            snake* movings = snake_one;

            srand((unsigned) time(&t));
            //Generating Food
            lunch = make_food(lunch, wall1, snake_one);
            //Setting Food
            show_food(lunch);

            int counter=0, move=0;

            ///Idõzítõ hozzáadása///
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

                ///A folyamatos előre léptetésért:
                remove_snake0(snake_one);

                control_snake(snake_one,boss);

                generate_snake0(snake_one);
                SDL_RenderPresent(renderer);

                //SNAKE COLLOSION WITH WALL //IT WORKS!
                if(collosion_detection_wall(snake_one, wall1)==true){
                        single_player_scoretofile(snake_one);
                        quit = true;
                        break;
                }
                //SNAKE COLLOSION DETECTION WITH SNAKE ITSELF //IT WORKS!
                if(collosion_detection_snakeitself(snake_one)==true){
                        single_player_scoretofile(snake_one);
                        quit = true;
                        break;
                }

                //SNAKE COLLOSION WITH FOOD // IT WORKS!
                if(collosion_detection_food(lunch,snake_one)==true){
                    //GROWING SNAKE (+1)
                    snake_one = build_snake_injection(snake_one);
                    //Generating Food
                    lunch = make_food(lunch, wall1, snake_one);
                    //Setting Food
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
            deletingW = wall1;
            while(deletingW!=NULL){
                wall *mostaniW = deletingW->next;
                free(deletingW);
                deletingW=mostaniW;
            }
            wall1=NULL;

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
            //Generating Wallpaper
            SDL_Texture *picD= IMG_LoadTexture(renderer, "wallpaper1.png");
            if (picD == NULL) {
                SDL_Log("Picture could not be opened: %s", IMG_GetError());
                exit(1);
            }
            //Generating WALL0
            wall0=draw_map0();
            wall1=draw_map1(wall0);
            //Setting Wallpaper
            picture_drawing_BIG(renderer, picD, 0,0);

            //Setting Map
            generate_map0(wall1);

            //Player Two
            bool first_left = false;
            bool first_right = false;
            bool first_up = false;
            bool first_down = false;
            snake2();

            //Player One
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

            snake* movings = snake_one;
            snake* movings2 = snake_two;

            srand((unsigned) time(&t));
            //Generating Food
            lunch = make_food_for2(lunch, wall1, snake_one, snake_two);
            //Setting Food
            show_food(lunch);

            int counter=0, move=0;

            ///Idõzítõ hozzáadása///
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
                if(collosion_detection_wall(snake_one, wall1)==true){
                        multi_player_scoretofile(snake_one, snake_two);
                        quit = true;
                        break;
                }

                if(collosion_detection_wall(snake_two, wall1)==true){
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
                if(collosion_detection_othersnake(snake_one,snake_two)==true){ //snake1->snake2
                        multi_player_scoretofile(snake_one, snake_two);
                        quit = true;
                        break;
                }
                if(collosion_detection_othersnake(snake_two,snake_one)==true){ //snake2->snake1
                        multi_player_scoretofile(snake_one, snake_two);
                        quit = true;
                        break;
                }

                ///SNAKE COLLOSION WITH FOOD // IT WORKS!
                if(collosion_detection_food(lunch,snake_one)==true){
                    //GROWING SNAKE (+1)
                    snake_one = build_snake_injection(snake_one);
                    //Generating Food
                    lunch = make_food_for2(lunch, wall1, snake_one,snake_two);
                    //Setting Food
                    show_food(lunch);
                }

                if(collosion_detection_food(lunch,snake_two)==true){
                    //GROWING SNAKE (+1)
                    snake_two = build_snake_injection(snake_two);
                    //Generating Food
                    lunch = make_food_for2(lunch, wall1, snake_one,snake_two);
                    //Setting Food
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
            deletingW = wall1;
            while(deletingW!=NULL){
                wall *mostaniW = deletingW->next;
                free(deletingW);
                deletingW=mostaniW;
            }
            wall0=NULL;
            wall1=NULL;

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
