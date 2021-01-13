#include "input.h"

input::input()
{
    left = false;
    right = false;

    left_prev = false;
    right_prev = false;
}

input::~input()
{
    left = false;
    right = false;

    left_prev = false;
    right_prev = false;
}

bool input::getInput()
{
    left = (0x8000 & GetAsyncKeyState((unsigned char)('\x25'))) != 0;
    right = (0x8000 & GetAsyncKeyState((unsigned char)('\x27'))) != 0;

    return true;
}

bool input::is_left()
{
    return (left && !left_prev);
}

bool input::is_right()
{
    return (right && !right_prev);
}

bool input::update_prev()
{
    left_prev = left;

    right_prev = right;

    return true;
}

bool input::space_press()
{
    return (0x8000 == GetAsyncKeyState((unsigned char)('\x20')));
}