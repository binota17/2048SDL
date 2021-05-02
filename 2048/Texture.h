#pragma once

#include "Variables.h"
#include "Board.h"
#include "Check.h"

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y);
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h);
void drawtext(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, std::string text, SDL_Color color, TTF_Font* font);

