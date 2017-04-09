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
  incScore(levelMap[player->peciman.pos.x][player->peciman.pos.y].Food, player);
  if (levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==RFOOD1){
    PlaySound(TEXT("sounds/pacman_chomp.wav"),NULL,SND_ASYNC);
    player->foodCount--;
  }
  else if(levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==RFOOD2 || levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==RFOOD3 || levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==RFOOD4 ||levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==RFOOD5){
    PlaySound(TEXT("sounds/pacman_eatfruit.wav"),NULL,SND_ASYNC);
  }
  levelMap[player->peciman.pos.x][player->peciman.pos.y].Food=REMPTY;
}

void incLives(playerControl *player, int *liveGiven){
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
  position pos;
  pos.x = posX;
  pos.y = posY;
  map->Food=foodType(randomise(1,100));
  DrawFood(map->Food, pos);
}

void despawnFood(MapController *map, int posX, int posY){
  map->Food=REMPTY;
  setcolor(BLACK);
  bar(posX * GRIDSIZE, posY* GRIDSIZE, (posX * GRIDSIZE) + GRIDSIZE, posY*GRIDSIZE + GRIDSIZE);
}

void randFoodPos(){
  position pos;
  do{
    pos.x=randomise(0,19);
    pos.y=randomise(0,19);
  }while(levelMap[pos.x][pos.y].Wall!=0 || ((pos.x==8 || pos.x==9 || pos.x==10 || pos.x==11) && (pos.y==9 || pos.y==10)));
  spawnFood(&levelMap[pos.x][pos.y],pos.x, pos.y);
}
