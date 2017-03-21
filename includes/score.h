#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#define FOOD1_SCORE 10
#define FOOD2_SCORE 20
#define FOOD3_SCORE 30
#define FOOD4_SCORE 40
#define FOOD5_SCORE 50

typedef struct{
	char *name;
	int score;
	int lives;
} playerController;

playerController player1;

void initScore();
void initLives();
void incScore(playerControl *player);
void incLives(playerControl *player);

#endif // SCORE_H_INCLUDED
