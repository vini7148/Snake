#include "snake.h"

snake::snake()
{
    sk = {
        {60, 15},
        {61, 15},
        {62, 15},
        {63, 15},
        {64, 15},
        {65, 15},
        {66, 15},
        {67, 15},
        {68, 15},
        {69, 15}
    };

    food = {
        30,
        15
    };

    score = 0;

    direction = 3;

    dead = false;
}

snake::snake(int x, int y)
{
    sk = {
        {x / 2, y / 2},
        {x / 2 + 1, y / 2},
        {x / 2 + 2, y / 2},
        {x / 2 + 3, y / 2},
        {x / 2 + 4, y / 2},
        {x / 2 + 5, y / 2},
        {x / 2 + 6, y / 2},
        {x / 2 + 7, y / 2},
        {x / 2 + 8, y / 2},
        {x / 2 + 9, y / 2}
    };

    food = {
        x / 4,
        y / 2
    };

    score = 0;

    direction = 3;

    dead = false;
}

snake::~snake()
{

}

bool snake::update_dir(int x)
{
    if(x == 0)
    {
        direction++;
        direction %= 4;
        
        return true;
    }

    if (x == 1)
    {
        direction--;
        direction = (direction < 0)?3:direction;

        return true;
    }

    return false;
}

int snake::ck_dir()
{
    return direction;
}
    
bool snake::update_snake(wchar_t *screen, int width, int height)
{
    switch (direction)
	{
	    case 0: // UP
			sk.push_front({ sk.front().x, sk.front().y - 1 });
			break;
		
        case 1: // RIGHT
			sk.push_front({ sk.front().x + 1, sk.front().y });
			break;
		
        case 2: // DOWN
			sk.push_front({ sk.front().x, sk.front().y + 1 });
			break;
		
        case 3: // LEFT
			sk.push_front({ sk.front().x - 1, sk.front().y });
			break;
	}

    if (sk.front().x == food.x && sk.front().y == food.y)
	{
		score++;

		while (screen[food.y * width + food.x] != L' ')
		{
			food.x = rand() % width;
			food.y = (rand() % (height-3))+3;
		}

		for (int i = 0; i < 5; i++)
				sk.push_back({ 
                    sk.back().x, sk.back().y
                });
	}

    return true;
}

bool snake::del_tail()
{
    if (sk.empty())
        return false;

    sk.pop_back();
    return true;
}

void snake::ck_dead(int width, int height)
{
    if (sk.front().x < 0 || sk.front().x >= width)
		dead = true;
	
    if (sk.front().y < 3 || sk.front().y >= height)
		dead = true;


	for (std::list<point>::iterator i = sk.begin(); i != sk.end(); i++)
		if (i != sk.begin() && i->x == sk.front().x && i->y == sk.front().y)
			dead = true;

}

bool snake::is_dead()
{
    return dead;
}

std::list<point> snake::dr_snake()
{
    return sk;
}

point snake::ret_food()
{
    return food;
}

int snake::ret_score()
{
    return score;
}