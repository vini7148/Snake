#include "console.h"

console::console()
{
    width = 120;

    height = 30;

    screen = new wchar_t[width * height];
    for (int i = 0; i < width * height; i++)
        screen[i] = L' ';
    
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);

    dwBytesWritten = 0;
}

console::console(int x, int y)
{
    width = x;

    height = y;

    screen = new wchar_t[width * height];
    for (int i = 0; i < width * height; i++)
        screen[i] = L' ';
    
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);

    dwBytesWritten = 0;
}

console::~console()
{

}

void console::clrscr()
{
    for (int i = 0; i < width * height; i++)
        screen[i] = L' ';
}

bool console::init()
{
    clrscr();

    return true;
}

void console::header(int score)
{
    for (int i = 0; i < width; i++)
	{
		screen[i] = L'-';
		screen[2 * width + i] = L'-';
	}

    screen[0] = L'+';
    screen[width - 1] = L'+';

    
    screen[2 * width] = L'+';
    screen[3 * width - 1] = L'+';
	
    wsprintfW(&screen[width + width / 3], L"CURRENT SCORE: %d ", score);
}

bool console::update(std::list<point> sk, point food, bool dead, int score)
{
    clrscr();
    
    header(score);

    for (auto s : sk)
		screen[s.y * width + s.x] = dead ? L'*' : L'O';

	screen[sk.front().y * width + sk.front().x] = dead ? L'X' : L'@';

	screen[food.y * width + food.x] = L'A';

    WriteConsoleOutputCharacterW(hConsole, screen, width * height, { 0,0 }, &dwBytesWritten);
    
    return true;
}

wchar_t* console::ret_screen()
{
    return screen;
}

int console::ret_wid()
{
    return width;
}

int console::ret_hei()
{
    return height;
}

void console::end_game(int score)
{
    clrscr();

    wsprintfW(&screen[12 * width + 50], L"Game End ");
    wsprintfW(&screen[13 * width + 50], L"Your Score was %d ", score);
    wsprintfW(&screen[14 * width + 50], L"Press Space to restart ");

    WriteConsoleOutputCharacterW(hConsole, screen, width * height, { 0,0 }, &dwBytesWritten);
}