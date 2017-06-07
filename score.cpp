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
  Food(map[pos.x][pos.y].Food, pos);
}

void despawnFood(MapController map[20][20], position pos){//Fahmi Rosdiansyah
  map[pos.x][pos.y].Food=EMPTY;
  setcolor(BLACK);
  bar(pos.x * GRIDSIZE, pos.y* GRIDSIZE, (pos.x * GRIDSIZE) + GRIDSIZE, pos.y*GRIDSIZE + GRIDSIZE);
}

position randFoodPos(){
  position pos;
  int i, count=0, arr[nodeCount];
  for(i=0;i<nodeCount;i++){
    if(levelMap[nodePos[i*2+0]][nodePos[i*2+1]].Food==EMPTY){
      arr[count]=i;
      count++;
    }
  }
  int idx = randomise(0,count-1);
  pos.x = nodePos[arr[idx]*2+0];
  pos.y = nodePos[arr[idx]*2+1];
  return pos;
  // spawnFood(&levelMap[pos.x][pos.y],pos.x, pos.y);
}

position randFood(playerControl *player){
    position pos;
    pos = randFoodPos();
    return pos;
}

void storeScore(playerControl *player){
  dataStore scoreData;
  strcpy(scoreData.name, player->name);
  scoreData.score = player->score;
  FILE *highscore;
  highscore=fopen("assets/files/highscore.dat", "a+");
  if(highscore==NULL)
    return;
  fwrite(&scoreData, sizeof(scoreData), 1, highscore);
  fclose(highscore);
  sortFile("assets/files/highscore.dat");
}

int scoreCount() {
  int sum=0;
  dataStore score;
  FILE *file;
  file=fopen("assets/files/highscore.dat", "rb");
  fread(&score, sizeof(score), 1, file);
  while(!feof(file)) {
    fread(&score, sizeof(score), 1, file);
    sum++;
  }
  fclose(file);
  return sum;
}

void sortFile(char *filename){
  int structSize, fileSize, i, j;
  FILE * file;
  file = fopen(filename,"rb+");
  if(file==NULL)
    return;
  dataStore pivot, temp;
  structSize = sizeof(pivot);
  fseek(file, 0, SEEK_END);
  fileSize = ftell(file);
  rewind(file);
  for (i = 0; i < fileSize; i += structSize){
    for (j = 0; j < fileSize - structSize; j += structSize){
      fread(&pivot, structSize, 1, file);
      fread(&temp, structSize, 1, file);
      if (pivot.score < temp.score){
        fseek(file, -(structSize * 2), SEEK_CUR);
        fwrite(&temp, structSize, 1, file);
        fwrite(&pivot, structSize, 1, file);
        fseek(file, -structSize, SEEK_CUR);
      }
      else{
        fseek(file, -structSize, SEEK_CUR);
      }
    }
    rewind(file);
  }
  fclose(file);
}
