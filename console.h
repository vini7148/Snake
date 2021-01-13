#include <Windows.h>

#include "snake.h"

class console
{
    int width;
    int height;

    wchar_t *screen;

    HANDLE hConsole;

    DWORD dwBytesWritten;

public:
    console();
    console(int x, int y);
    ~console();

    void clrscr();
    bool init();
    void header(int score);
    bool update(std::list<point> sk, point food, bool dead, int score);

    wchar_t* ret_screen();
    int ret_wid();
    int ret_hei();

    void end_game(int score);
};