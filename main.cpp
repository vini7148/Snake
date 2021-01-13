#include "gameloop.h"

int main()
{
    gameloop* G = new gameloop(120, 30);

    G->init();
    
    while(G->run())
    {

    }
    
    delete G;

    return 0;
}