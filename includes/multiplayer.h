#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define UP2 119
#define DOWN2 115
#define LEFT2 97
#define RIGHT2 100

#define GRIDSIZE2 20

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

int CanMovePeciman2(pacmanController peciman, int nextDirection);

#endif
