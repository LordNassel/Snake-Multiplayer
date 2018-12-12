#include "menu.h"
#include "map.h"
#include "snake.h"
#include "controls.h"
#include "scoreboard.h"

SDL_Color blck = {0, 0, 0};

int countlines(char *filename){
  FILE *fp = fopen(filename,"r");
  int ch=0;
  int lines=0;

  if (fp == NULL) printf("\n File could not be opened!");

  lines++;
  while ((ch = fgetc(fp)) != EOF)
    {
      if (ch == '\n')
    lines++;
    }
  return lines+1;
}

void linestoarray(char* filename, int lines, int* tomb){

    double num_game, first_score, second_score;
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) printf("\n File could not be opened!");

    int counter=0;

    if(fp){
    while(fscanf(fp,"%lf %lf %lf",&num_game, &first_score, &second_score)==3){
        tomb[(3*counter)]=(int)num_game;
        tomb[(3*counter)+1]=(int)first_score;
        tomb[(3*counter)+2]=(int)second_score;
        counter++;
        }
    }
    fclose(fp);
}

void blended_text_blck(SDL_Renderer *renderer, int whereX, int whereY, const char* title, int meret){
    TTF_Init();
    TTF_Font *font = TTF_OpenFont("LiberationSerif-Regular.ttf", meret); ///Text hight
    if (!font) {
        SDL_Log("Font could not be opened! %s\n", TTF_GetError());
        exit(1);
    }

    SDL_Surface *felirat;
    SDL_Texture *felirat_t;
    SDL_Rect hova = { 0, 0, 0, 0 };

    felirat = TTF_RenderUTF8_Blended(font, title, blck);
    felirat_t = SDL_CreateTextureFromSurface(renderer, felirat);
    hova.x = (whereX - felirat->w) / 2;
    hova.y = whereY;
    hova.w = felirat->w;
    hova.h = felirat->h;
    SDL_RenderCopy(renderer, felirat_t, NULL, &hova);
    SDL_FreeSurface(felirat);
    SDL_DestroyTexture(felirat_t);
    TTF_CloseFont(font);
}

void show_scoreboard(){
    ///Loading Logos
    SDL_Texture *logo_UL= IMG_LoadTexture(renderer, "snake_up_left.png");
    if (logo_UL == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *logo_UR= IMG_LoadTexture(renderer, "snake_up_right.png");
    if (logo_UR == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *logo_DR= IMG_LoadTexture(renderer, "snake_down_right.png");
    if (logo_DR == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }
    SDL_Texture *logo_DL= IMG_LoadTexture(renderer, "snake_down_left.png");
    if (logo_DL == NULL) {
        SDL_Log("Picture could not be opened: %s", IMG_GetError());
        exit(1);
    }

    ///Drawing Picture
    boxRGBA(renderer, 0, 0, 1920, 1080, 0xFF, 0xFF, 0xFF, 0xFF); ///RGBA Colors
    ///Title
    blended_text_blck(renderer,1920,50,"SCOREBOARD",64);
    logo_drawing(renderer, logo_UL, 0,0);
    logo_drawing(renderer, logo_UR, 1720,0);
    logo_drawing(renderer, logo_DR, 1720,880);
    logo_drawing(renderer, logo_DL, 0,880);



    /// Nth Game || Player One  |Player Two
    blended_text_blck(renderer,960,300,"Nth Game",32);
    blended_text_blck(renderer,1920,300,"Player One",32);
    blended_text_blck(renderer,2880,300,"Player Two",32);


    int lines = countlines("results.txt");
    int t[(3*lines)], rowlength=0;
    linestoarray("results.txt",lines,t);
    char nth_game[12], player_one[12], player_two[12]; ///All numbers that are representable by int will fit in a 12-char-array without overflow
    for(int i=(lines-2); i>=(lines-11); i--)
    {
        sprintf(nth_game, "%d", t[(3*i)]);
        sprintf(player_one, "%d", t[(3*i)+1]);
        sprintf(player_two, "%d", t[(3*i)+2]);

        blended_text_blck(renderer,960,(350+50*rowlength),nth_game,32);
        blended_text_blck(renderer,1920,(350+50*rowlength),player_one,32);
        blended_text_blck(renderer,2880,(350+50*rowlength),player_two,32);
        rowlength++;
    }
    ///Press F1 to Resume
    blended_text_blck(renderer,1920,1000,"Press F1 to Resume",32);
    SDL_RenderPresent(renderer);

    bool quit=false;
    while (!quit){
        SDL_Event event;
        SDL_WaitEvent(&event);

        switch (event.type) {
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_F1: quit = true; break;
                }
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_F1: quit = false; break;
                }
                break;

            case SDL_QUIT:
                quit = true;
                break;
        }
    }

    SDL_DestroyTexture(logo_UL);
    SDL_DestroyTexture(logo_UR);
    SDL_DestroyTexture(logo_DR);
    SDL_DestroyTexture(logo_DL);
}
/*For the brave souls who get this far: You are the chosen ones,
the valiant knights of programming who toil away, without rest,
fixing our most awful code. To you, true saviors, kings of men,
I say this: never gonna give you up, never gonna let you down,
never gonna run around and desert you. Never gonna make you cry,
never gonna say goodbye. Never gonna tell a lie and hurt you.*/
