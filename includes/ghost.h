#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED
#include "list.h"
typedef struct {
    int direction;
    int speed;
    int ghostType;
    position pos;
    position initPos;
    Stack path;
    int lastNode;
    int initNode;
    int stateghost;
}ghostController;
void DrawGhost(ghostController ghost);
void GhostMove(ghostController *ghost);
int CanMove(ghostController ghost, int direction);
void GhostAutoMove(ghostController *ghost, pacmanController pacman);
void InitGhost(ghostController *ghost, position pos, int ghostType);
void BlackSquareCheck(position pos);
#endif
