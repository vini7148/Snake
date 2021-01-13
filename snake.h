#include <iostream>
#include <list>

struct point
{
    int x;
    int y;
};

class snake
{
    std::list<point> sk;

    point food;

    int score;
    int direction;

    bool dead;

public:
    snake();
    snake(int x, int y);
    ~snake();

    bool update_dir(int x);
    int ck_dir();
    bool update_snake(wchar_t *screen,  int width, int height);
    bool del_tail();

    void ck_dead(int width, int height);
    bool is_dead();

    std::list<point> dr_snake();
    point ret_food();
    int ret_score();
};