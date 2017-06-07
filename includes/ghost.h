#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED
#include "list.h"

#define ROAMING 3
#define CHASING 0
#define BEING_CHASED 1
#define DEAD 2

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
int bfs(int v, int prev[]);
#endif
