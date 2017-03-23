#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include "includes/peciman.h"
#include "includes/map.h"
#include "includes/score.h"
#include "map.cpp"
#include "peciman.cpp"
#include "score.cpp"


int main()
{
    clock_t begin;

    /* here, do your time-consuming job */

    clock_t end;
    double time_spent;

    pacmanController peciman;
    initwindow(800, 600, "Pecimen Game");
    initScore(&player1);
    initLives(&player1);
    CreateMap(level1, &peciman);
    char choose;
    int step = 0;

    DrawMap();
    while (true)
    {
        step++;
        begin = clock();
        if(kbhit())
        {
            choose = getch();
            switch(choose){
            case RIGHTARROW :   peciman.direction = RIGHT;break;
            case LEFTARROW :   peciman.direction = LEFT;break;
            case DOWNARROW :   peciman.direction = DOWN;break;
            case UPARROW :   peciman.direction = UP;break;
            // case 13: addBonus(levelMap[9][12],9,12); break;
            }
        }
        if (step%200 == 0){
            delay(100);
            Move(&peciman);
            // if(levelMap[peciman.posX][peciman.posY].Food != 0){
            // 	eatFood(&peciman);
	           //  incLives(&player1);
            // }
            changeState(&peciman);
        }
        end = clock();
        time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // Ulah di hapus
//      printf("Time = %f\n",time_spent);
        printf("%d %d\n", player1.score, player1.lives);
    }

    getch();
    return 0;
}
