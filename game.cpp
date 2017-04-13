void InitLevel(playerControl *player);
void InitGame(playerControl *player) {//M. Hisyam A
    initScore(player);
    initLives(player);
    player->level = 1;
    InitLevel(player);
}
void GameRoundCheck();

void InitLevel(playerControl *player) { //M. Hisyam A
    switch(player->level) {
        case 1 : CreateMap(level1, player);break;
        case 2 : CreateMap(level2, player);break;
        case 3 : CreateMap(level3, player);break;
    }
}
void ResetPosition(playerControl *player) {//M. Hisyam A
    player->peciman.pos.x = player->peciman.initPos.x;
    player->peciman.pos.y = player->peciman.initPos.y;
    player->ghost1.pos.x = player->ghost1.initPos.x;
    player->ghost1.pos.y = player->ghost1.initPos.y;
    player->ghost2.pos.x = player->ghost2.initPos.x;
    player->ghost2.pos.y = player->ghost2.initPos.y;
    player->ghost3.pos.x = player->ghost3.initPos.x;
    player->ghost3.pos.y = player->ghost3.initPos.y;
    player->ghost4.pos.x = player->ghost4.initPos.x;
    player->ghost4.pos.y = player->ghost4.initPos.y;
}
void GameStart(playerControl *player) { //Hisyam, Fadhit, Fahmi
    clock_t begin;
    clock_t end;
    char choose;
    int time_spent;
    int step = 0;
    char scoreText[20];
    char livesText[20];
    int liveGiven=0;
    char lepel[2];
    while (player->lives>0 && player->level<=3) {
        cleardevice();
        DrawSideMenu();
        settextstyle(8, HORIZ_DIR,1);
        outtextxy(660, 165,player->name);
        ResetPosition(player);
        DrawMap();
        DrawGhost(player->ghost1);
        DrawPacman(player->peciman);
        begin = clock();
        srand(time(NULL));
        PlaySound(TEXT("sounds/pacman_beginning.wav"),NULL,SND_ASYNC);
        printScore(player->score, 660, 285);
        printLives(player->lives, 627, 405);
        sprintf(lepel, "%d", player->level);
        //BlackSquare(24*GRIDSIZE,GRIDSIZE*2.8);
        outtextxy(720,84, lepel);
        while(player->foodCount > 0 && (player->peciman.pos.x!=player->ghost1.pos.x) || (player->peciman.pos.y != player->ghost1.pos.y)) {
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
            if (step%8 == 0){
                if (CanMovePeciman(player->peciman , player->peciman.nextDirection)) // dicek apakah ada penghalang tembok atau tidak
                {
                    player->peciman.direction = player->peciman.nextDirection; // perubahan arah jika tidak ada tembok
                }
                Move(&player->peciman);
                if(levelMap[player->peciman.pos.x][player->peciman.pos.y].Food != 0){
                    eatFood(player);
                    printScore(player->score, 660, 285);
                    incLives(player, &liveGiven);
                    printLives(player->lives, 627, 405);
                }
                changeState(&player->peciman); // mengubah keadaan pacman dari membuka menjadi tertutup
            }
            if (step%16 == 0) {
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
            if((time_spent==20 && (levelMap[9][12].Food==FOOD2 || levelMap[9][12].Food==FOOD3)) || (time_spent==15 && levelMap[9][12].Food==FOOD4) || (time_spent==10 && levelMap[9][12].Food==FOOD5)){
                despawnFood(&levelMap[9][12],9,12);
            }
        }
        if (player->foodCount == 0) {
            printf("Game End");
            player->level++;
            InitLevel(player);
        }
        else {
            PlaySound(TEXT("sounds/pacman_death.wav"),NULL,SND_ASYNC);
            player->lives--;
            delay(1500);
        }

    }
    cleardevice();
    settextstyle(8, HORIZ_DIR,30);
    setcolor(WHITE);
    if (player->lives==0){
        outtext("GAME OVER");
        PlaySound(TEXT("sounds/pacman_intermission.wav"),NULL,SND_ASYNC);
    }
    else{
        outtext("PLAYER WIN");
        PlaySound(TEXT("sounds/pacman_intermission.wav"),NULL,SND_ASYNC);
    }
}
