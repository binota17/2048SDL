#include "Check.h"

bool checkFocusWithRect(const int &x, const int &y, const SDL_Rect &rect)
{
	if (x > rect.x && x < rect.x + rect.w && y > rect.y && y < rect.y + rect.h)
		return true;
	return false;
}


void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
    {
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

int gameover() {
    int m=0, n=0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++)
            if (tab[i][j] == 0) {
                m = 1; break;
            }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++)
            if (tab[i][j] == tab[i][j+1] || tab[i][j] == tab[i+1][j] ) {
                n = 1; break;
            }
    }
    if (m == 1 || n == 1) return 0;
    else return 1;
}

int win()
{
    int n=0;
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++) {
            if (tab[i][j] == 2048) {
                n = 1;
                break;
            }
    }
    if (n == 1) return 1;
    else return 0;
}
