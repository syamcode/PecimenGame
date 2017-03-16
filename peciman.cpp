#include "includes/peciman.h"
#include <graphics.h>

void drawPacman(pacmanController peciman)
{
    switch (peciman.direction) {
      case UP:
      readimagefile("assets/images/PacmanUpOpen.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      break;

      case DOWN:
      readimagefile("assets/images/PacmanDownOpen.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      break;

      case RIGHT:
      readimagefile("assets/images/PacmanRightOpen.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      break;

      case LEFT:
      readimagefile("assets/images/PacmanLeftOpen.bmp", peciman.posX, peciman.posY, peciman.posX + GRIDSIZE, peciman.posY + GRIDSIZE);
      break;
    }
    // readimagefile("assets/images/PacmanRightOpen.bmp", posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
}
