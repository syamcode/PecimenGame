#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include "peciman.h"
#define MAX_LIVES 10

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

//void InitGame();
//void GameRoundCheck();
//void InitLevel();
void ResetPositionGhost(playerControl *player);

#endif // GAME_H_INCLUDED
