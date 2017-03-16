#include "includes/peciman.h"
#include <graphics.h>

void drawPacman(pacmanController peciman)
{
    switch (peciman.direction) {
      case UP:
      if (peciman.state == 1) // if open
      {
        readimagefile("assets/images/PacmanUpOpen.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      }
      else if // close
      {
        readimagefile("assets/images/PacmanUpClose.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      }
      break;

      case DOWN:
      if (peciman.state == 1) // if open
      {
        readimagefile("assets/images/PacmanDownOpen.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      }
      else if // close
      {
        readimagefile("assets/images/PacmanDownClose.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      }
      break;

      case RIGHT:
      if (peciman.state == 1) // if open
      {
        readimagefile("assets/images/PacmanRightOpen.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      }
      else if // close
      {
        readimagefile("assets/images/PacmanRightClose.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      }
      break;

      case LEFT:
      if (peciman.state == 1) // if open
      {
        readimagefile("assets/images/PacmanLeftOpen.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      }
      else if // close
      {
        readimagefile("assets/images/PacmanLeftClose.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
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
    pecimen.state = 1;
    pecimen.direction = getch();
    drawPacman(peciman);

}
