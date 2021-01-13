#include <Windows.h>
#include <iostream>
#include <thread>

#include "input.h"
#include "console.h"

class gameloop
{
    console* c;
    input* In;
    snake* S;

public:
    gameloop();
    gameloop(int x, int y);
    ~gameloop();

    bool init();
    bool run();
};