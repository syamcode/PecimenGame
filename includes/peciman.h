#ifndef PECIMAN_H_INCLUDED
#define PECIMAN_H_INCLUDED

#define GRIDSIZE 30

#define UPARROW 72
#define DOWNARROW 80
#define LEFTARROW 75
#define RIGHTARROW 77

#define UP 1
#define RIGHT 2
#define LEFT 3
#define DOWN 4

typedef struct{
	int x;
	int y;
} position;

typedef struct{
    int direction;
    int nextDirection;
    position pos;
    position initPos;
    int state;
}pacmanController;



void DrawPacman(pacmanController peciman);
void mainPeciman(pacmanController peciman);
void InitPacman(pacmanController *peciman, int i, int j);

#endif // PECIMAN_H_INCLUDED
