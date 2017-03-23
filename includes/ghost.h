#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

#define TUYUL 1
#define KUNTILANAK 2
#define POCONG 3
#define TENGKORAK 4
typedef struct {
    int posX;
    int posY;
    int direction;
    int speed;
    int ghostType;
}ghostController;
void DrawGhost(ghostController ghost);
void GhostMove();
int CanMove();
void GhostAutoMove();

#endif
