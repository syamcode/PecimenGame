#include "includes/score.h"

void resetScore(){
    score=0
}

void incScore(pacmanController *pecimen){
    switch(level1[pecimen->posX][pecimen->posY]){
    case FOOD1:
        score+=FOOD1_SCORE;
        break;
    case FOOD2:
        score+=FOOD2_SCORE;
        break;
    case FOOD3:
        score+=FOOD3_SCORE;
        break;
    case FOOD4:
        score+=FOOD4_SCORE;
        break;
    }
    level1[pecimen->posX][pecimen->posY]=1;
}
