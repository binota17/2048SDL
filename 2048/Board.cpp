#include "Board.h"
#include "Variables.h"
#include "Texture.h"


void board(SDL_Window* window, SDL_Renderer* renderer, int tab[4][4])
{
    SDL_Rect rect;
    SDL_Texture *hai = loadTexture("images/2.bmp", renderer);
    SDL_Texture *bon = loadTexture("images/4.bmp", renderer);
    SDL_Texture *tam = loadTexture("images/8.bmp", renderer);
    SDL_Texture *msau = loadTexture("images/16.bmp", renderer);
    SDL_Texture *bhai = loadTexture("images/32.bmp", renderer);
    SDL_Texture *stu = loadTexture("images/64.bmp", renderer);
    SDL_Texture *trhai = loadTexture("images/128.bmp", renderer);
    SDL_Texture *hatram = loadTexture("images/256.bmp", renderer);
    SDL_Texture *namtram = loadTexture("images/512.bmp", renderer);
    SDL_Texture *nghin = loadTexture("images/1024.bmp", renderer);
    SDL_Texture *hainghin = loadTexture("images/2048.bmp", renderer);
    SDL_Texture *bonnghin = loadTexture("images/4096.bmp", renderer);
    SDL_Texture *tamnghin = loadTexture("images/8192.bmp", renderer);

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            rect.x = 105 +100*j;
            rect.y = 240 + 100*i;
            rect.w = 90;
            rect.h = 90;

            if (tab[i][j] == 0) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
            else if (tab[i][j]  == 2 ) {
            renderTexture(hai, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 4 ) {
            renderTexture(bon, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 8 ) {
            renderTexture(tam, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 16 ) {
            renderTexture(msau, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 32 ) {
            renderTexture(bhai, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 64 ) {
            renderTexture(stu, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 128 ) {
            renderTexture(trhai, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 256 ) {
            renderTexture(hatram, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 512 ) {
            renderTexture(namtram, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 1024 ) {
            renderTexture(nghin, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 2048 ) {
            renderTexture(hainghin, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 4096 ) {
            renderTexture(bonnghin, renderer, rect.x, rect.y, rect.w, rect.h);
            }
            else if (tab[i][j]  == 8192 ) {
            renderTexture(tamnghin, renderer, rect.x, rect.y, rect.w, rect.h);
            }
        }
    }
}

void renderwin(SDL_Window* window, SDL_Renderer *renderer)
{
    int w = win();
    SDL_Texture* win = loadTexture("images/win.bmp", renderer);

    SDL_Rect rec;
    rec.x = 100;
    rec.y = 200;

    if (w == 1)
        renderTexture(win, renderer, rec.x, rec.y);

}
void renderlose(SDL_Window* window, SDL_Renderer *renderer)
{
    int l = gameover();
    SDL_Texture* lose = loadTexture("images/thua.bmp", renderer);

    SDL_Rect rec;
    rec.x = 100;
    rec.y = 200;

    if (l == 1)
    {
        renderTexture(lose, renderer, rec.x, rec.y);
    }
}

int Menu(SDL_Texture* texture)
{
    const int Item = 2;
    TTF_Font *fon = TTF_OpenFont("visitor1.ttf", 45);

    bool selected[Item] = {false, false};
    const char *labels[Item] = {"NewGame", "Exit"};

    int posx = 0, posy = 0;

    SDL_Texture *start = loadTexture("images/start.bmp", renderer);
    renderTexture(start, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

//    if (start == nullptr){
//        SDL_DestroyTexture(start);
//        quitSDL(window, renderer);
//    }
    for (int i=0; i< Item; ++i)
        drawtext(texture, renderer, 100, 400 + i*60, labels[i], {0,0,0}, fon);

    SDL_Event event;
    while(true)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    return Exit;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        return Exit;
                case SDL_MOUSEMOTION:
                    {
                        posx = event.motion.x;
                        posy = event.motion.y;
                        for( int i = 0; i < Item; ++i)
                            if (checkFocusWithRect(posx, posy, {100, 400+i*60, 200-105*i, 50-15*i}))
                            {
                                if (selected[i] == false)
                                {
                                    selected[i] = true;
                                    drawtext(texture, renderer, 100, 400 + i*60, labels[i], {0,0,0}, fon);
                                }
                                else
                                {
                                    selected[i] = false;
                                    drawtext(texture, renderer, 100, 400 + i*60, labels[i], {255,0,0}, fon);
                                }
                            }
                    }
                    break;
                    case SDL_MOUSEBUTTONDOWN:
                    {
                        posx = event.button.x;
                        posy = event.button.y;
                        for (int i = 0; i < Item; ++i)
                            if (checkFocusWithRect(posx, posy, {100, 400+i*60, 200-105*i, 50-15*i}))
                            {
                                return i;
                            }
                    }
            }
        }
        SDL_RenderPresent(renderer);
    }
}
