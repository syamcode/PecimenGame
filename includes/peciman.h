#ifndef PECIMAN_H_INCLUDED
#define PECIMAN_H_INCLUDED

#define GRIDSIZE 37

#define UP 72
#define RIGHT 77
#define LEFT 75
#define DOWN 80

typedef struct{
    int direction;
    int posX;
    int posY;
}pacmanController;

void drawPacman(pacmanController peciman);

#endif // PECIMAN_H_INCLUDED
