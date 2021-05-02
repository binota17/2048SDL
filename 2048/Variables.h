#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern std::string WINDOW_TITLE ;

extern int tab[4][4];
extern int diem;

enum Menu
{
	NewGame,
	Exit,
	Quit
};


extern SDL_Window *window;
extern SDL_Renderer *renderer;


//
//extern std::vector<std::vector<int>> tab;
//extern std::vector<std::vector<int>> coptab;
