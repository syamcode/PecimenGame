void InitLevel(playerControl *player);
void InitGame(playerControl *player) {
    initScore(player);
    initLives(player);
    player->level = 1;
    InitLevel(player);
}
void GameRoundCheck();

void InitLevel(playerControl *player) {
    switch(player->level) {
        case 1 : CreateMap(level1, player);break;
        case 2 : CreateMap(level2, player);break;
        case 3 : CreateMap(level3, player);break;
    }
}

void GameStart(playerControl *player) {
    clock_t begin;
    clock_t end;
    char choose;
    int time_spent;
    int step = 0;
    char scoreText[20];
    char livesText[20];
    int liveGiven=0;
    while (player->lives>0) {
        DrawMap();
        DrawGhost(player->ghost1);
        begin = clock();
        srand(time(NULL));
        while(player->foodCount > 0) {
            printf("%d ",player->foodCount);
            step++;
            if(kbhit())
            {
                choose = getch();
                switch(choose){
                case RIGHTARROW :   player->peciman.direction = RIGHT;break;
                case LEFTARROW :   player->peciman.direction = LEFT;break;
                case DOWNARROW :   player->peciman.direction = DOWN;break;
                case UPARROW :   player->peciman.direction = UP;break;
                }
            }
            if (step%10 == 0){
                Move(&player->peciman);
                 if(levelMap[player->peciman.posX][player->peciman.posY].Food != 0){
                    eatFood(player);
                    printScore(player->score, 20*GRIDSIZE, GRIDSIZE);

                    incLives(player, &liveGiven);
                    printLives(player->lives, 20*GRIDSIZE, 2*GRIDSIZE);
                 }
                changeState(&player->peciman);
            }
            if (step%10 == 5) {
                GhostAutoMove(&player->ghost1, player->peciman);
            }
            delay(10);
            end = clock();
            time_spent = (int)(end - begin) / CLOCKS_PER_SEC; // Ulah di hapus
            printf("%d %d %d\n", player->score, player->lives, time_spent);
            if(time_spent==60){
                spawnFood(&levelMap[9][12],9,12);
                begin=clock();
            }
            if((time_spent==20 && (levelMap[9][12].Food==RFOOD2 || levelMap[9][12].Food==RFOOD3)) || (time_spent==15 && levelMap[9][12].Food==RFOOD4) || (time_spent==10 && levelMap[9][12].Food==RFOOD5)){
                despawnFood(&levelMap[9][12],9,12);
            }
        }
        printf("Game End");
        player->level++;
        InitLevel(player);
    }
}
