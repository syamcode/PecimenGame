#include <stdio.h>
#include <graphics.h>
#include "includes/peciman.h"
#include "includes/map.h"
#include "map.cpp"

int main()
{
    initwindow(800, 600, "Pecimen Game");
//    pacmanController peciman;
    CreateMap(level1);
    DrawMap();
    //peciman.direction = getch();
    //printf("%d",peciman.direction);
    //cleardevice();
    //drawPacman(peciman);

    getch();
    return 0;
}
