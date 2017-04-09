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
    char lepel[2];
    DrawSideMenu();
    settextstyle(8, HORIZ_DIR,1);
    outtextxy(22*GRIDSIZE, 5.5*GRIDSIZE,player->name);
    while (player->lives>0) {
        DrawMap();

        DrawGhost(player->ghost1);
        DrawPacman(player->peciman);
        begin = clock();
        srand(time(NULL));
        PlaySound(TEXT("sounds/pacman_beginning.wav"),NULL,SND_ASYNC);
        printScore(player->score, 22*GRIDSIZE, 9.5*GRIDSIZE);
        printLives(player->lives, 22*GRIDSIZE, 13.5*GRIDSIZE);
        sprintf(lepel, "%d", player->level);
        //BlackSquare(24*GRIDSIZE,GRIDSIZE*2.8);
        outtextxy(24*GRIDSIZE,GRIDSIZE*2.8, lepel);
        while(player->foodCount > 0) {
            printf("%d ",player->foodCount);
            step++;
            if(kbhit())
            {
                choose = getch();
                switch(choose){ // untuk menyimpan direction yang akan dilakukan
                case RIGHTARROW :
                    player->peciman.nextDirection = RIGHT;
                    break;

                case LEFTARROW :
                    player->peciman.nextDirection = LEFT;
                    break;

                case DOWNARROW :
                    player->peciman.nextDirection = DOWN;
                    break;

                case UPARROW :
                     player->peciman.nextDirection = UP;
                    break;

                //case 13: spawnFood(&levelMap[9][12],9,12); break;
                }
            }
            if (step%10 == 0){
                if (CanMovePeciman(player->peciman , player->peciman.nextDirection)) // dicek apakah ada penghalang tembok atau tidak
                {
                    player->peciman.direction = player->peciman.nextDirection; // perubahan arah jika tidak ada tembok
                }
                Move(&player->peciman);
                if(levelMap[player->peciman.pos.x][player->peciman.pos.y].Food != 0){
                    printScore(player->score, 22*GRIDSIZE, 9.5*GRIDSIZE);
                    eatFood(player);
                    incLives(player, &liveGiven);
                    printLives(player->lives, 22*GRIDSIZE, 13.5*GRIDSIZE);
                }
                changeState(&player->peciman); // mengubah keadaan pacman dari membuka menjadi tertutup
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
