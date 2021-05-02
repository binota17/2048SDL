#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Variables.h"
#include "Board.h"
#include "Check.h"
#include "Texture.h"

using namespace std;


//bool Gameover;


void createtab ();
int Taoso();
void randomnumber();
void copytab(int tab1[4][4], int tab2[4][4]);
int check(int tab1[4][4],int tab2[4][4]);
int gameover();
int win();

void trai();
void phai();
void len();
void xuong();
int highscore();

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);


int main(int argc, char *argv[])
{
    int cop[4][4], tmp = 0;
    int highsc = highscore();;

    SDL_Event e;
    SDL_Texture *texture = NULL;
    TTF_Font *font = NULL;

    initSDL(window, renderer);
    if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		return -1;
	}

    SDL_Texture *background = loadTexture("images/background.bmp", renderer);


    if (background == nullptr){
        SDL_DestroyTexture(background);
        quitSDL(window, renderer);
    }
//    SDL_RenderClear(renderer);
    font = TTF_OpenFont("visitor1.ttf", 30);

//    string score = "Diem: " + to_string(diem);

    bool quit = false, quitGame = false;
    while(!quit)
    {
        int menuOption = Menu(texture);
        switch (menuOption)
        {
        case NewGame:
            {
                SDL_RenderClear(renderer);
                renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
//                SDL_RenderPresent(renderer);
                diem = 0;
                string score = "Diem: " + to_string(diem);
                string hscore = "Ki luc: " + to_string(highsc);

                drawtext(texture, renderer, 335, 67, score, {0,0,0}, font);
                drawtext(texture, renderer, 335, 115, hscore, {0,0,0}, font);

                createtab();

                board(window, renderer, tab);
                quitGame = false;
                SDL_RenderPresent(renderer);


            while (!quitGame)
            {
                while (!quitGame)
                {
                SDL_RenderClear(renderer);
                renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

                if ( SDL_WaitEvent(&e) == 0) continue;

                if (e.type == SDL_QUIT) break;

                copytab(tab, cop);

                if (e.type == SDL_KEYDOWN) {

                    if (e.key.keysym.sym == SDLK_ESCAPE) quitGame = true;
                    if (e.key.keysym.sym == SDLK_n) {
                        for (int i=0; i<4; i++)
                            for (int j=0; j<4; j++) tab[i][j] = 0;
                        diem = 0;
                        randomnumber();
                    }

                    if (e.key.keysym.sym == SDLK_LEFT) trai();
                    if (e.key.keysym.sym == SDLK_RIGHT) phai();
                    if (e.key.keysym.sym == SDLK_DOWN) xuong();
                    if (e.key.keysym.sym == SDLK_UP) len();

                    if (!check(tab, cop)) randomnumber();

                    board(window, renderer, tab);
                    score = "Diem: " + to_string(diem);
                    drawtext(texture, renderer, 335, 67, score, {0,0,0}, font);

                    highsc = highscore();
                    string hscore = "Ki luc: " + to_string(highsc);
                    drawtext(texture, renderer, 335, 115, hscore, {0,0,0}, font);

                    if (tmp == 0) {
                        renderwin(window, renderer);
                        tmp = 1;
                    }
                    renderlose(window, renderer);
                    SDL_RenderPresent(renderer);
                    }
                }
            }
            break;
        }
        case Exit:
            quit = true;
            break;
        }
    }

    quitSDL(window, renderer);

    return 0;
}

void createtab ()
{

    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++) {
            tab[i][j] = 0;
        }
    }
    int a = rand() % 4, b = rand() % 4;
    tab[a][b] = 2;
    do {
        a = rand() % 4;
        b = rand() % 4;
    }
    while (tab[a][b] != 0);
    tab[a][b] = 2;
}

int Taoso()
{
    int x = rand() %20;
    if (x) return 2;
    return 4;
}

void randomnumber()
{
    int a,b;
    do {
        a = rand() % 4;
        b = rand() % 4;
    }
    while ( tab[a][b] != 0);
    tab[a][b] = Taoso();
}

void copytab(int tab1[4][4], int tab2[4][4])
{
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++) {
            tab2[i][j] = tab1[i][j];
        }
    }
}

int check(int tab1[4][4],int tab2[4][4]) {
    int n = 1;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++) {
             if(tab2[i][j] != tab1[i][j]) {
                n = 0; break;
             }
        }
    }
    return n;
}



void trai() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (tab[i][j] == 0) {
                for (int h = j+1; h<4; h++) {
                    if(tab[i][h] != 0) {
                        tab[i][j] = tab[i][h];
                        tab[i][h] = 0;
                        break;
                    }
                }
            }
        }
    }
   for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            if (tab[i][j] == tab[i][j+1]) {
                tab[i][j] = tab[i][j] * 2;
                diem += tab[i][j];
                tab[i][j+1] = 0;
                for (int h = j+1; h<3; h++) {
                    tab[i][h] = tab[i][h+1];
                }
            }
        }
    }
}

void phai() {
    for (int i=0; i<4; i++) {
        for (int j=3; j>=0; j--) {
            if (tab[i][j] == 0) {
                for (int h = j-1; h>=0; h--) {
                    if(tab[i][h] != 0) {
                        tab[i][j] = tab[i][h];
                        tab[i][h] = 0;
                        break;
                    }
                }

            }
        }
    }
   for (int i=0; i<4; i++) {
        for (int j=3; j>0; j--) {
            if (tab[i][j] == tab[i][j-1]) {
                tab[i][j] = tab[i][j] * 2;
                diem += tab[i][j];
                tab[i][j-1] = 0;
                for (int h = j-1; h>0; h--) {
                    tab[i][h] = tab[i][h-1];
                }
            }
        }
    }
}

void len() {
    for (int j=0; j<4; j++) {
        for (int i=0; i<4; i++) {
            if (tab[i][j] == 0) {
                for (int h = i+1; h<4; h++) {
                    if(tab[h][j] != 0) {
                        tab[i][j] = tab[h][j];
                        tab[h][j] = 0;
                        break;
                    }
                }

            }
        }
    }
   for (int j=0; j<4; j++) {
        for (int i=0; i<3; i++) {
            if (tab[i][j] == tab[i+1][j]) {
                tab[i][j] = tab[i][j] * 2;
                diem += tab[i][j];
                tab[i+1][j] = 0;
                for (int h = i+1; h<3; h++) {
                    tab[h][j] = tab[h+1][j];
                }
            }
        }
    }
}

void xuong() {
    for (int j=0; j<4; j++) {
        for (int i=3; i>=0; i--) {
            if (tab[i][j] == 0) {
                for (int h = i-1; h>=0; h--) {
                    if(tab[h][j] != 0) {
                        tab[i][j] = tab[h][j];
                        tab[h][j] = 0;
                        break;
                    }
                }

            }
        }
    }
   for (int j=0; j<4; j++) {
        for (int i=3; i>0; i--) {
            if (tab[i][j] == tab[i-1][j]) {
                tab[i][j] = tab[i][j] * 2;
                diem += tab[i][j];
                tab[i-1][j] = 0;
                for (int h = i-1; h>0; h--) {
                    tab[h][j] = tab[h-1][j];
                }
            }
        }
    }
}

int highscore()
{
    int diem1;
    fstream ip;
    ip.open("highscore.txt");
    ip >> diem1;
    ip.close();

    fstream op;
    op.open("highscore.txt");
    if (diem < diem1)
        return diem1;
    else {
        op << diem;
        return diem;
    }
    op.close();
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);
    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
