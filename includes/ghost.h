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
void InitGhost(ghostController *ghost, position pos, int ghostType);
int CanMove(ghostController ghost, int direction);
void BlackSquareCheck(position pos);
void GhostMove(ghostController *ghost);
void GhostAutoMove(ghostController *ghost, pacmanController pacman);
void GeneratePath(int prev[], int start, int End, Stack *path);
void PrintPath(Stack path);
int bfs(int v, int prev[]) ;
void ghostRealMove(ghostController * ghost, int dest);
void ghostMoveAsli(ghostController * ghost, int dest);
void printState(int state);

#endif
