#include "includes/peciman.h"
#include <graphics.h>

void DrawPacman(pacmanController peciman)
{
    int posX = peciman.posX * GRIDSIZE;
    int posY = peciman.posY * GRIDSIZE;
    switch (peciman.direction) {
      case UP:
      if (peciman.state == 1) // if open
      {
        readimagefile("assets/images/PacmanUpOpen.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
      }
      else  // close
      {
        readimagefile("assets/images/PacmanUpClose.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
      }
      break;

      case DOWN:
      if (peciman.state == 1) // if open
      {
        readimagefile("assets/images/PacmanDownOpen.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
      }
      else // close
      {
        readimagefile("assets/images/PacmanDownClose.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
      }
      break;

      case RIGHT:
      if (peciman.state == 1) // if open
      {
        readimagefile("assets/images/PacmanRightOpen.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
      }
      else // close
      {
        readimagefile("assets/images/PacmanRightClose.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
      }
      break;

      case LEFT:
      if (peciman.state == 1) // if open
      {
        readimagefile("assets/images/PacmanLeftOpen.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
      }
      else// close
      {
        readimagefile("assets/images/PacmanLeftClose.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
      }
      break;
    }
}

void InitPacman (pacmanController *peciman, int i, int j)
{
    peciman->posX = i;
    peciman->posY = j;
    peciman->direction = RIGHT;
    peciman->state = 1;
}

void changeState(pacmanController *peciman)
{
    if (peciman->state == 0)
    {
      peciman->state = 1; // change to open
    }
    else
    {
      peciman->state = 0; // change to close
    }
}

void BlackSquare(int posX, int posY)
{
    setcolor(0);
    bar(posX * GRIDSIZE, posY* GRIDSIZE, (posX * GRIDSIZE) + GRIDSIZE, posY*GRIDSIZE + GRIDSIZE);
}

void Move(pacmanController *peciman)
{
    setfillstyle(SOLID_FILL, 0);
    switch(peciman->direction)
    {
        case RIGHT :
             if (peciman->posX == 19){
            BlackSquare(peciman->posX, peciman->posY);
            peciman->posX = 0;

            levelMap[peciman->posX][peciman->posY].Object = RPACMAN;

            //Print Pacman di index 0
            BlackSquare(peciman->posX, peciman->posY);
            levelMap[peciman->posX][peciman->posY].Object = REMPTY;
            levelMap[peciman->posX][peciman->posY].Object = RPACMAN;

            }
            else if(levelMap[peciman->posX+1][peciman->posY].Wall == 0){ // Cek apakah ada tembok atau tidak dan print ke array index selanjutnya
            BlackSquare(peciman->posX, peciman->posY);
            levelMap[peciman->posX][peciman->posY].Object = REMPTY;
            peciman->posX++;
            levelMap[peciman->posX][peciman->posY].Object = RPACMAN;
            }



            break;

        case LEFT :
            if (peciman->posX == 0){
              BlackSquare(peciman->posX, peciman->posY);
              peciman->posX = 20 ;
              levelMap[peciman->posX][peciman->posY].Object = RPACMAN;
            }
            if(levelMap[peciman->posX-1][peciman->posY].Wall == 0 ){
            BlackSquare(peciman->posX, peciman->posY);
            levelMap[peciman->posX][peciman->posY].Object = REMPTY;
            peciman->posX--;
            levelMap[peciman->posX][peciman->posY].Object = RPACMAN;
            }


            break;

        case UP :
             if (peciman->posY == 0){
                BlackSquare(peciman->posX, peciman->posY);
              peciman->posX = 20;
              levelMap[peciman->posX][peciman->posY].Object = RPACMAN;
            }
            if(levelMap[peciman->posX][peciman->posY-1].Wall == 0){
            BlackSquare(peciman->posX, peciman->posY);
            levelMap[peciman->posX][peciman->posY].Object = REMPTY;
            peciman->posY--;
            levelMap[peciman->posX][peciman->posY].Object = RPACMAN;
            }

            break;

        case DOWN :
            if (peciman->posY == 19){
            BlackSquare(peciman->posX, peciman->posY);
              peciman->posY = 0;
              levelMap[peciman->posX][peciman->posY].Object = RPACMAN;

            //Print pacman
              BlackSquare(peciman->posX, peciman->posY);
            levelMap[peciman->posX][peciman->posY].Object = REMPTY;
            levelMap[peciman->posX][peciman->posY].Object = RPACMAN;
            }
            else if(levelMap[peciman->posX][peciman->posY+1].Wall == 0){
            BlackSquare(peciman->posX, peciman->posY);
            levelMap[peciman->posX][peciman->posY].Object = REMPTY;
            peciman->posY++;
            levelMap[peciman->posX][peciman->posY].Object = RPACMAN;
            }
            break;


    }
    DrawPacman(*peciman);
}
