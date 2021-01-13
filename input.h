#include <Windows.h>

class input
{
    bool left;
    bool right;
    bool left_prev;
    bool right_prev;

public:
    input();
    ~input();

    bool getInput();
    bool is_left();
    bool is_right();
    bool update_prev();

    bool space_press();
};