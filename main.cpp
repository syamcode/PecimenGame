#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include "includes/peciman.h"
#include "includes/map.h"
#include "includes/ghost.h"
#include "includes/score.h"
#include "map.cpp"
#include "peciman.cpp"
#include "ghost.cpp"
#include "score.cpp"
#include "game.cpp"



int main()
{
    initwindow(800, 600, "Pecimen Game");
    playerControl player1;
    InitGame(&player1);
    GameStart(&player1);
    getch();
    return 0;
}
