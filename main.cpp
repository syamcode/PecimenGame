#include <stdio.h>
#include <graphics.h>
#include "includes/peciman.h"
#include "includes/map.h"
#include "map.cpp"
#include "peciman.cpp"
#include <time.h>

int main()
{
    clock_t begin;

    /* here, do your time-consuming job */

    clock_t end;
    double time_spent;

    pacmanController peciman;
    initwindow(800, 600, "Pecimen Game");
//    pacmanController peciman;
    CreateMap(level1);
    //DrawMap();
    char choose;
    //peciman.direction = getch();
    //printf("%d",peciman.direction);
    //cleardevice();
    //drawPacman(peciman);
    //mainPeciman(peciman);
                        peciman.direction = RIGHT;
                    peciman.state = 1;
    int page = 1;
    DrawMap(peciman);
    while (true)
    {
        begin = clock();
//        setactivepage(page);
//        setvisualpage(1 - page);
        if(kbhit())
        {
            choose = getch();
            switch(choose){
            case RIGHTARROW :   peciman.direction = RIGHT;break;
            case LEFTARROW :   peciman.direction = LEFT;break;
            case DOWNARROW :   peciman.direction = DOWN;break;
            case UPARROW :   peciman.direction = UP;break;
            }
            //printf("%d", peciman.direction);
        }
//        page = 1 - page;
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time = %f\n",time_spent);
    }

    getch();
    return 0;
}
