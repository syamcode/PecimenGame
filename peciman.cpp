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
    // readimagefile("assets/images/PacmanRightOpen.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
}

// void movePacman()
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
void mainPeciman(pacmanController peciman)
{
    peciman.direction = getch();
    DrawPacman(peciman);
}

void Move(pacmanController *peciman)
{
    setfillstyle(SOLID_FILL, 0);
    switch(peciman->direction){
    case RIGHT : if(levelMap[peciman->posX+1][peciman->posY].Wall == 0){
        setcolor(0);
        bar(peciman->posX * GRIDSIZE, peciman->posY* GRIDSIZE, (peciman->posX * GRIDSIZE) + GRIDSIZE, peciman->posY*GRIDSIZE + GRIDSIZE);
        peciman->posX++;
        levelMap[peciman->posX+1][peciman->posY].Object = RPACMAN;
        }break;
    case LEFT : if(levelMap[peciman->posX-1][peciman->posY].Wall == 0){
        setcolor(0);
        bar(peciman->posX * GRIDSIZE, peciman->posY* GRIDSIZE, (peciman->posX * GRIDSIZE) + GRIDSIZE, peciman->posY*GRIDSIZE + GRIDSIZE);
        peciman->posX--;
        levelMap[peciman->posX-1][peciman->posY].Object = RPACMAN;
        }break;
    case UP : if(levelMap[peciman->posX][peciman->posY-1].Wall == 0){
        setcolor(0);
        bar(peciman->posX * GRIDSIZE, peciman->posY* GRIDSIZE, (peciman->posX * GRIDSIZE) + GRIDSIZE, peciman->posY*GRIDSIZE + GRIDSIZE);
        peciman->posY--;
        levelMap[peciman->posX][peciman->posY-1].Object = RPACMAN;
        }break;
    case DOWN : if(levelMap[peciman->posX][peciman->posY+1].Wall == 0){
        setcolor(0);
        bar(peciman->posX * GRIDSIZE, peciman->posY* GRIDSIZE, (peciman->posX * GRIDSIZE) + GRIDSIZE, peciman->posY*GRIDSIZE + GRIDSIZE);
        peciman->posY++;
        levelMap[peciman->posX][peciman->posY+1].Object = RPACMAN;
        }break;
    }

    DrawPacman(*peciman);
}
