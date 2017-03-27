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



int main()
{
    clock_t begin;

    /* here, do your time-consuming job */

    clock_t end;
    int time_spent;

    initwindow(800, 600, "Pecimen Game");
    initScore(&player1);
    initLives(&player1);
    CreateMap(level1, &player1);
    char choose;
    int step = 0;
    char scoreText[20];
    char livesText[20];
    int liveGiven=0;
    DrawMap();
    sprintf(scoreText, "Score : %d", player1.score);
    sprintf(livesText, "Lives : %d", player1.lives);
    //setfillstyle(SOLID_FILL, BLACK);
    //bar(22*GRIDSIZE, GRIDSIZE, 28*GRIDSIZE, 3*GRIDSIZE);
    outtextxy(22*GRIDSIZE, GRIDSIZE, scoreText);
    outtextxy(22*GRIDSIZE, 2 * GRIDSIZE, livesText);
    DrawGhost(player1.ghost1);
//    DrawGhost(player1.ghost2);
//    DrawGhost(player1.ghost3);
//    DrawGhost(player1.ghost4);
    begin = clock();
    srand(time(NULL));
    while (true)
    {

        step++;
        if(kbhit())
        {
            choose = getch();
            switch(choose){
            case RIGHTARROW :   player1.peciman.direction = RIGHT;break;
            case LEFTARROW :   player1.peciman.direction = LEFT;break;
            case DOWNARROW :   player1.peciman.direction = DOWN;break;
            case UPARROW :   player1.peciman.direction = UP;break;
            case 13: spawnFood(&levelMap[9][12],9,12); break;
            }
        }
        if (step%10 == 0){
            Move(&player1.peciman);
             if(levelMap[player1.peciman.posX][player1.peciman.posY].Food != 0){
             	eatFood(&player1);
                incLives(&player1, &liveGiven);
             }
            changeState(&player1.peciman);
        }
        if (step%10 == 5) {
            GhostAutoMove(&player1.ghost1, player1.peciman);
//            GhostAutoMove(&player1.ghost2, player1.peciman);
//            GhostAutoMove(&player1.ghost3, player1.peciman);
//            GhostAutoMove(&player1.ghost4, player1.peciman);

        }
        delay(10);
        end = clock();
        time_spent = (int)(end - begin) / CLOCKS_PER_SEC; // Ulah di hapus
        printf("%d %d %d\n", player1.score, player1.lives, time_spent);
        if(time_spent==60){
        	spawnFood(&levelMap[9][12],9,12);
        	// randFoodPos();
        	begin=clock();
        }
        if((time_spent==20 && (levelMap[9][12].Food==RFOOD2 || levelMap[9][12].Food==RFOOD3)) || (time_spent==15 && levelMap[9][12].Food==RFOOD4) || (time_spent==10 && levelMap[9][12].Food==RFOOD5)){
        	despawnFood(&levelMap[9][12],9,12);
        }
//      printf("Time = %f\n",time_spent);
    }

    getch();
    return 0;
}
