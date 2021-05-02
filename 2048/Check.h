#pragma once

#include "Variables.h"
#include "Texture.h"

bool checkFocusWithRect(const int &x, const int &y, const SDL_Rect &rect);
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
int gameover();
int win();
