#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "peciman.h"
#define MAX_LIVES 10
#define DEFAULTSPEED 8
#define ESCAPESPEED 6

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
} playerControl;

void InitGame(playerControl *player);

void InitLevel(playerControl *player);

void ResetPosition(playerControl *player);

void GameStart(playerControl *player);

#endif // GAME_H_INCLUDED
