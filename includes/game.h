#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

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

#endif // GAME_H_INCLUDED
