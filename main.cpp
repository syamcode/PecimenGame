#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include "includes/peciman.h"
#include "includes/ghost.h"
#include "includes/game.h"
#include "includes/map.h"
#include "includes/score.h"
#include "includes/interfaces.h"
#include "includes/list.h"
#include "map.cpp"
#include "peciman.cpp"
#include "ghost.cpp"
#include "score.cpp"
#include "game.cpp"
#include "interfaces.cpp"
#include "list.cpp"

//playerControl player1;

int main()
{
    initwindow(800, 600, "Pecimen Game");
    PlaySound("sounds/bgm.wav",NULL,SND_ASYNC | SND_LOOP);
    menuutama();
    getch();
    closegraph();
    return 0;
}
