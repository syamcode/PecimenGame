void initScore(playerControl *player){ //Fahmi Rosdiansyah
  player->score=0;
}

void initLives(playerControl *player){//Fahmi Rosdiansyah
  player->lives=5;
}

void incScore(int food, playerControl *player){//Fahmi Rosdiansyah
  switch(food){
  case FOOD1:
    player->score+=FOOD1_SCORE;
    break;
  case FOOD2:
    player->score+=FOOD2_SCORE;
    break;
  case FOOD3:
    player->score+=FOOD3_SCORE;
    break;
  case FOOD4:
    player->score+=FOOD4_SCORE;
    break;
  case FOOD5:
    player->score+=FOOD5_SCORE;
    break;
  }
}

void eatFood(playerControl *player){//Fahmi Rosdiansyah
  incScore(levelMap[player->peciman.pos.x][player->peciman.pos.y].Food, player);
  if (levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==FOOD1){
    PlaySound("sounds/pacman_chomp.wav",NULL,SND_ASYNC);
    player->foodCount--;
  }
  else if(levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==FOOD2 || levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==FOOD3 || levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==FOOD4 ||levelMap[player->peciman.pos.x][player->peciman.pos.y].Food==FOOD5){
    PlaySound("sounds/pacman_eatfruit.wav",NULL,SND_ASYNC);
  }
  levelMap[player->peciman.pos.x][player->peciman.pos.y].Food=EMPTY;
}

void incLives(playerControl *player, int *liveGiven){
  if(player->score>=2500 && *liveGiven==0 && player->lives<MAX_LIVES){
    player->lives++;
    *liveGiven=1;
  }
  else if(player->score>=5000 && *liveGiven==1 && player->lives<MAX_LIVES){
    player->lives++;
    *liveGiven=2;
  }
  else if(player->score>=15000 && *liveGiven==2 && player->lives<MAX_LIVES){
    player->lives++;
    *liveGiven=3;
  }
  else if(player->score>=25000 && *liveGiven==3 && player->lives<MAX_LIVES){
    player->lives++;
    *liveGiven=4;
  }
  else if(player->score>=40000 && *liveGiven==4 && player->lives<MAX_LIVES){
    player->lives++;
    *liveGiven=5;
  }
}

int randomise(int min, int max){//Fahmi Rosdiansyah
  return rand()%(max+1-min)+min;
}

int foodType(int x){//Fahmi Rosdiansyah
  switch(x){
    case 1 ... 40: return FOOD2; break;    //40%
    case 41 ... 70: return FOOD3; break;   //30%
    case 71 ... 90: return FOOD4; break;   //20%
    case 91 ... 100: return FOOD5; break;  //10%
  }
}

void spawnFood(MapController map[20][20], position pos){//Fahmi Rosdiansyah
  // position pos;
  // pos.x = posX;
  // pos.y = posY;
  map[pos.x][pos.y].Food=foodType(randomise(1,100));
  DrawFood(map[pos.x][pos.y].Food, pos);
}

void despawnFood(MapController map[20][20], position pos){//Fahmi Rosdiansyah
  map[pos.x][pos.y].Food=EMPTY;
  setcolor(BLACK);
  bar(pos.x * GRIDSIZE, pos.y* GRIDSIZE, (pos.x * GRIDSIZE) + GRIDSIZE, pos.y*GRIDSIZE + GRIDSIZE);
}

// void randFoodPos(){
//   position pos;
//   do{
//     pos.x=randomise(0,19);
//     pos.y=randomise(0,19);
//   }while(levelMap[pos.x][pos.y].Wall!=0 || ((pos.x==8 || pos.x==9 || pos.x==10 || pos.x==11) && (pos.y==9 || pos.y==10)));
//   spawnFood(&levelMap[pos.x][pos.y],pos.x, pos.y);
// }

position randFoodPos(int nodelevel[][2]){
  position pos;
  int i, count=0, arr[nodeCount];
  for(i=0;i<nodeCount;i++){
    if(levelMap[nodelevel[i][0]][nodelevel[i][1]].Food==EMPTY){
      arr[count]=i;
      count++;
    }
  }
  int idx = randomise(0,count-1);
  pos.x = nodelevel[arr[idx]][0];
  pos.y = nodelevel[arr[idx]][1];
  return pos;
  // spawnFood(&levelMap[pos.x][pos.y],pos.x, pos.y);
}

position randFood(playerControl *player){
  position pos;
  switch(player->level){
    case 1: pos = randFoodPos(NodeLevel1);break;
    case 2: pos = randFoodPos(NodeLevel2);break;
    case 3: pos = randFoodPos(NodeLevel3);break;
    case 4: break;
    case 5: break;
    case 6: pos = randFoodPos(NodeLevel6);break;
    case 7: break;
  }
  return pos;
}

void storeScore(playerControl *player){
  FILE *highscore;
  strcpy(scoreData.name, player->name);
  scoreData.score = player->score;
  highscore=fopen("highscore.dat", "a+");
  fwrite(&scoreData, sizeof(scoreData), 1, highscore);
  fclose(highscore);
}
