#include "Variables.h"

int SCREEN_WIDTH = 600;
int SCREEN_HEIGHT = 700;
std::string WINDOW_TITLE = "2048" ;

int tab[4][4];
int diem = 0;

SDL_Window *window;
SDL_Renderer *renderer;

//std::vector<std::vector<int>> tab(4, std::vector<int>(4));
//std::vector<std::vector<int>> coptab(4, std::vector<int>(4));
//
