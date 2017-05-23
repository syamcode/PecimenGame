#ifndef MULTIPLAYER_H_INCLUDED
#define MULTIPLAYER_H_INCLUDED

#include "peciman.h"
#define UPARROW2 119
#define DOWNARROW2 115
#define LEFTARROW2 97
#define RIGHTARROW2 100

typedef struct{
	char name[15];
	int score;
	int lives;
	int foodCount;
	int level;
	pacmanController peciman;
	ghostController ghost1;
	ghostController ghost2;
	ghostController ghost3;
	ghostController ghost4;
} playerControl1;


int CanMovePeciman2(pacmanController peciman, int nextDirection);

#endif
