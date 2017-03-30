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
    PlaySound(TEXT("sounds/pacman_beginning.wav"),NULL,SND_ASYNC);
    CreateMap(level2, &player1);

    char choose;
    int step = 0;
    char scoreText[20];
    char livesText[20];
    int liveGiven=0;
    DrawMap();
    readimagefile("picture/pecimen.bmp",20.3*GRIDSIZE,GRIDSIZE/2,26.5*GRIDSIZE,GRIDSIZE*2);
    rectangle(20.2*GRIDSIZE,GRIDSIZE/2,26.5*GRIDSIZE,19.8*GRIDSIZE);
    rectangle(20.3*GRIDSIZE,GRIDSIZE*2,26.4*GRIDSIZE,19.7*GRIDSIZE);

    settextstyle(8, HORIZ_DIR,1);

    rectangle(20.8*GRIDSIZE,GRIDSIZE*2.5,26*GRIDSIZE,3.5*GRIDSIZE);
    outtextxy(21.5*GRIDSIZE,GRIDSIZE*2.8,"LEVEL");

    outtextxy(21.5*GRIDSIZE, 4.2*GRIDSIZE,"NAMA PLAYER");
   // sprintf(nameText, "Nama Player  : ", player1.name);
   //outtextxy(21*GRIDSIZE,3*GRIDSIZE, nameText);
   rectangle(20.8*GRIDSIZE,GRIDSIZE*4,26*GRIDSIZE,5*GRIDSIZE);
    rectangle(20.8*GRIDSIZE,GRIDSIZE*4,26*GRIDSIZE,7*GRIDSIZE);

    outtextxy(22.5*GRIDSIZE, 8.2*GRIDSIZE,"SCORE");
    rectangle(20.8*GRIDSIZE,GRIDSIZE*8,26*GRIDSIZE,9*GRIDSIZE);
    rectangle(20.8*GRIDSIZE,GRIDSIZE*8,26*GRIDSIZE,11*GRIDSIZE);

    outtextxy(22.5*GRIDSIZE, 12.2*GRIDSIZE,"LIVES");
    rectangle(20.8*GRIDSIZE,GRIDSIZE*12,26*GRIDSIZE,13*GRIDSIZE);
    rectangle(20.8*GRIDSIZE,GRIDSIZE*12,26*GRIDSIZE,16.5*GRIDSIZE);

	outtextxy(21.2*GRIDSIZE, 17.2*GRIDSIZE,"BACK TO MENU");
	rectangle(20.8*GRIDSIZE,GRIDSIZE*17,26*GRIDSIZE,18*GRIDSIZE);
    /*klik menu dengan mouse */
    //while(1)
    //{
        //GetCursorPos(&cursorPosition);
        //mX=cursorPosition.x;
        //mY=cursorPosition.y;

       //if (GetAsyncKeyState(VK_LBUTTON) && mX>=370 && mX<=470 && mY>=570)
       //{
           //menuutama();
       //}
    //}
    settextstyle(2, HORIZ_DIR,0.2);
    outtextxy(22.5*GRIDSIZE,18.5*GRIDSIZE, "GOOD LUCK!");
    DrawGhost(player1.ghost1);
//    DrawGhost(player1.ghost2);
//    DrawGhost(player1.ghost3);
//    DrawGhost(player1.ghost4);
    begin = clock();
    srand(time(NULL));
    while (true)
    {
printf("%d ",player1.foodCount);
        step++;
        if(kbhit())
        {
            choose = getch();
            switch(choose){
            case RIGHTARROW :
                player1.peciman.nextDirection = RIGHT;
                break;

            case LEFTARROW :
                player1.peciman.nextDirection = LEFT;
                break;

            case DOWNARROW :
                player1.peciman.nextDirection = DOWN;
                break;

            case UPARROW :
                 player1.peciman.nextDirection = UP;
                break;

            case 13: spawnFood(&levelMap[9][12],9,12); break;
            }
        }
        if (step%10 == 0){
            if (CanMovePeciman(player1.peciman , player1.peciman.nextDirection))
            {
                player1.peciman.direction = player1.peciman.nextDirection;
            }
            Move(&player1.peciman);
             if(levelMap[player1.peciman.posX][player1.peciman.posY].Food != 0){
             	eatFood(&player1);
             	printScore(player1.score, 22*GRIDSIZE, 9.5*GRIDSIZE);
             	printLives(player1.lives, 22*GRIDSIZE, 13.5*GRIDSIZE);
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
