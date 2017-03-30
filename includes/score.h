#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#define FOOD1_SCORE 15	//Titik
#define FOOD2_SCORE 100	//Sedap Malam
#define FOOD3_SCORE 300	//Menyan
#define FOOD4_SCORE 500	//Melati
#define FOOD5_SCORE 700	//Kopi Hitam
#define ONES 5
#define TENS 4
#define HUNDREDS 3
#define THOUSANDS 2
#define TENTHOUSANDS 1
#define HUNDREDTHOUSANDS 0

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

void initScore(playerControl *player);
void initLives(playerControl *player);
void incScore(int food, playerControl *player);
void eatFood(playerControl *player);
void incLives(playerControl *player, int *liveGiven);
int randomise(int min, int max);
int foodType(int x);
void spawnFood(MapController *map, int posX, int posY);
void despawnFood(MapController *map, int posX, int posY);
void randFoodPos();
void drawNumber(int x, int posX, int posY, int posisi);
void printScore(int score, int posX, int posY);
void printLives(int lives, int posX, int posY);

#endif // SCORE_H_INCLUDED
