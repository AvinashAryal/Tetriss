#include"game.cpp"

#include"game.h"
#include"gamefield.h"
#include"tetromino.h"

game *g = new game;

int main(int argc, char *argv[])
{
    g->CreateGame();
    while(g->GameSwitch())
    {
        g->DisplayGame();
    }
    g->DestroyGame();
    delete g;
    return 0;
}

