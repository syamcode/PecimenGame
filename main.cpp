#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <windows.h>
#include "includes/peciman.h"
#include "includes/map.h"
#include "includes/ghost.h"
#include "includes/score.h"
#include "includes/interfaces.h"

#include "map.cpp"
#include "peciman.cpp"
#include "ghost.cpp"
#include "score.cpp"
#include "game.cpp"
#include "interfaces.cpp"

//playerControl player1;

int main()
{
    initwindow(800, 600, "Pecimen Game");
    menuutama();
    getch();
    closegraph();
    return 0;
}
