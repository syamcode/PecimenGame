#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#define FOOD1_SCORE 15	//Titik
#define FOOD2_SCORE 100	//Sedap Malam
#define FOOD3_SCORE 300	//Menyan
#define FOOD4_SCORE 500	//Melati
#define FOOD5_SCORE 700	//Kopi Hitam

typedef struct{
	char name[15];
	int score;
}dataStore;

void initScore(playerControl *player);
void initLives(playerControl *player);
void incScore(int food, playerControl *player);
void eatFood(playerControl *player);
void incLives(playerControl *player, int *liveGiven);
int randomise(int min, int max);
int foodType(int x);
void spawnFood(MapController map[20][20], position pos);
void despawnFood(MapController map[20][20], position pos);
position randFoodPos(int nodelevel[][2]);
position randFood(playerControl *player);
void storeScore(playerControl *player);
int scoreCount();
void sortFile(char *filename);

#endif // SCORE_H_INCLUDED
