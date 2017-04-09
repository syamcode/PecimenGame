#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

typedef struct {
    int direction;
    int speed;
    int ghostType;
    position pos;
    position initPos;
}ghostController;
void DrawGhost(ghostController ghost);
void GhostMove(ghostController *ghost);
int CanMove(ghostController ghost, int direction);
void GhostAutoMove(ghostController *ghost, pacmanController pacman);
void InitGhost(ghostController *ghost, position pos, int ghostType);
void BlackSquareCheck(position pos);
#endif
