#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#define FOOD1_SCORE 15	//Titik
#define FOOD2_SCORE 100	//Sedap Malam
#define FOOD3_SCORE 300	//Menyan
#define FOOD4_SCORE 500	//Melati
#define FOOD5_SCORE 700	//Kopi Hitam

typedef struct{
	char *name;
	int score;
	int lives;
} playerControl;

playerControl player1;

void initScore(playerControl *player);
void initLives(playerControl *player);
void incScore(playerControl *player);
void incLives(playerControl *player);
int randomise(int min, int max);
int foodType(int x);

#endif // SCORE_H_INCLUDED
