#include "gameloop.h"

gameloop::gameloop()
{
    c = new console();
    S = new snake();
    In = new input();
}
    
gameloop::gameloop(int x, int y)
{
    c = new console(x, y);
    S = new snake(x, y);
    In = new input();
}

gameloop::~gameloop()
{
    delete c;
    delete S;
    delete In;
}

bool gameloop::init()
{
    return (c->init());
}

bool gameloop::run()
{
    while(!S->is_dead())
    {
        auto time_prev = std::chrono::system_clock::now();

        while((std::chrono::system_clock::now() - time_prev) < ((S->ck_dir()&1) ? std::chrono::milliseconds(120) : std::chrono::milliseconds(200)))
        {
            In->getInput();

            if(In->is_left())
                S->update_dir(1);

            if(In->is_right())
                S->update_dir(0);

            In->update_prev();
        }

        S->update_snake(c->ret_screen(), c->ret_wid(), c->ret_hei());
        S->ck_dead(c->ret_wid(), c->ret_hei());
        S->del_tail();

        c->update(S->dr_snake(), S->ret_food(), S->is_dead(), S->ret_score());
    }

    c->end_game(S->ret_score());

    auto time = std::chrono::system_clock::now();

    do
    {
        if (In->space_press())
            this->run();

    }while ((std::chrono::system_clock::now() - time) <= std::chrono::seconds(10));

    return false;
}