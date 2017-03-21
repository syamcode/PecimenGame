#include "includes/score.h"

void initScore(){
    player.score=0;
}

void initLives(playerControl *player){
    player->lives=3;
}

void incScore(playerControl *player){
    switch(levelMap[pecimen->posX][pecimen->posY].Food){
    case RFOOD1:
        player->score+=FOOD1_SCORE;
        break;
    case RFOOD2:
        player->score+=FOOD2_SCORE;
        break;
    case RFOOD3:
        player->score+=FOOD3_SCORE;
        break;
    case RFOOD4:
        player->score+=FOOD4_SCORE;
        break;
    case RFOOD5:
        player->score+=FOOD5_SCORE;
        break;
    }
    levelMap[pecimen->posX][pecimen->posY].Food=0;
}


void incLives(playerControl *player){

}
