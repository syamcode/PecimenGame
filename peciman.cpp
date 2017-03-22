#include "includes/peciman.h"
#include <graphics.h>

void drawPacman(pacmanController peciman)
{
    int posX = peciman.posX * GRIDSIZE;
    int posY = peciman.posY * GRIDSIZE;
     printf("%d", peciman.direction);
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
void chageState(pacmanController *peciman)
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
    drawPacman(peciman);
}

void Move()
{

}
