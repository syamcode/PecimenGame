#include "includes/score.h"

playerControl player1;

void initScore(playerControl *player){
    player->score=0;
}

void initLives(playerControl *player){
    player->lives=3;
}

void incScore(int food, playerControl *player){
   switch(food){
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
}

void eatFood(playerControl *player){
    incScore(levelMap[player->peciman.posX][player->peciman.posY].Food, player);
    if (levelMap[player->peciman.posX][player->peciman.posY].Food==RFOOD1){
      player->foodCount--;
    }
    levelMap[player->peciman.posX][player->peciman.posY].Food=REMPTY;
}

void incLives(playerControl *player, int *liveGiven){
    // if(player->score==2500 || player->score==5000 || player->score==15000 || player->score==25000 || player->score==40000)
    if(player->score>=2500 && *liveGiven==0){
      player->lives++;
      *liveGiven=1;
    }
    else if(player->score>=5000 && *liveGiven==1){
      player->lives++;
      *liveGiven=2;
    }
    else if(player->score>=15000 && *liveGiven==2){
      player->lives++;
      *liveGiven=3;
    }
    else if(player->score>=25000 && *liveGiven==3){
      player->lives++;
      *liveGiven=4;
    }
    else if(player->score>=40000 && *liveGiven==4){
      player->lives++;
      *liveGiven=5;
    }
}

int randomise(int min, int max){
    return rand()%(max+1-min)+min;
}

int foodType(int x){
    switch(x){
        case 1 ... 40: return RFOOD2; break;    //40%
        case 41 ... 70: return RFOOD3; break;   //30%
        case 71 ... 90: return RFOOD4; break;   //20%
        case 91 ... 100: return RFOOD5; break;  //10%
    }
}

void spawnFood(MapController *map, int posX, int posY){
    map->Food=foodType(randomise(1,100));
    DrawFood(map->Food,posX*GRIDSIZE,posY*GRIDSIZE);
}

void despawnFood(MapController *map, int posX, int posY){
  map->Food=REMPTY;
  setcolor(BLACK);
  bar(posX * GRIDSIZE, posY* GRIDSIZE, (posX * GRIDSIZE) + GRIDSIZE, posY*GRIDSIZE + GRIDSIZE);
}

void randFoodPos(){
  int posX, posY;
  do{
    posX=randomise(0,19);
    posY=randomise(0,19);
  }while(levelMap[posX][posY].Wall!=0 || ((posX==8 || posX==9 || posX==10 || posX==11) && (posY==9 || posY==10)));
  spawnFood(&levelMap[posX][posY],posX,posY);
}

void drawNumber(int x, int posX, int posY, int posisi){
    posX+=posisi*GRIDSIZE/2;
    switch(x){
        case 0: readimagefile("assets/images/0.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
        case 1: readimagefile("assets/images/1.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
        case 2: readimagefile("assets/images/2.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
        case 3: readimagefile("assets/images/3.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
        case 4: readimagefile("assets/images/4.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
        case 5: readimagefile("assets/images/5.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
        case 6: readimagefile("assets/images/6.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
        case 7: readimagefile("assets/images/7.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
        case 8: readimagefile("assets/images/8.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
        case 9: readimagefile("assets/images/9.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    }
}

void printScore(int score, int posX, int posY){
    drawNumber((((((score/10)/10)/10)/10)/10)%10,posX,posY,0);
    drawNumber(((((score/10)/10)/10)/10)%10,posX,posY,1);
    drawNumber((((score/10)/10)/10)%10,posX,posY,2);
    drawNumber(((score/10)/10)%10,posX,posY,3);
    drawNumber((score/10)%10,posX,posY,4);
    drawNumber(score%10,posX,posY,5);
}

void printLives(int lives, int posX, int posY){
    int i;
    for(i=0;i<lives;i++){
        readimagefile("assets/images/lives.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);
        posX+=GRIDSIZE;
    }
}
