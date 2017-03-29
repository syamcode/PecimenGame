#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

typedef struct {
    int posX;
    int posY;
    int direction;
    int speed;
    int ghostType;
}ghostController;
void DrawGhost(ghostController ghost);
void GhostMove(ghostController *ghost);
int CanMove(ghostController ghost, int direction);
void GhostAutoMove(ghostController *ghost, pacmanController pacman);
void InitGhost(ghostController *ghost, int posX, int posY, int ghostType);
void BlackSquareCheck(int posX, int posY);
#endif
