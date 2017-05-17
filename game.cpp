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
        case 1 : CreateMap(level1, player);nodeCount=58;createNodes(player, NodeLevel1);break;
        case 2 : CreateMap(level2, player);nodeCount=70;createNodes(player, NodeLevel2);break;
        case 3 : CreateMap(level3, player);nodeCount=60;createNodes(player, NodeLevel3);break;
        case 4 : CreateMap(level4, player);break;
        case 5 : CreateMap(level5, player);break;
        case 6 : CreateMap(level6, player);nodeCount=116;createNodes(player, NodeLevel6);break;
        case 7 : CreateMap(level7, player);nodeCount=12;break;
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

    player->ghost1.lastNode = levelMap[player->ghost1.pos.x][player->ghost1.pos.y].node;
    player->peciman.lastNode = levelMap[player->peciman.pos.x][player->peciman.pos.y].node;
}
void GameStart(playerControl *player) { //Hisyam, Fadhit, Fahmi
    int rekamana;
    clock_t begin;
    clock_t end;
    char choose;
    int time_spent;
    int step = 0;
    char scoreText[20];
    char livesText[20];
    int liveGiven=0;
    char lepel[2];
    CreateStack(&player->ghost1.path);
    int prev[nodeCount];
    int speed;
    //PrintPath(path);
    while (player->lives>0 && player->level<=7) {
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
        PlaySound("sounds/pacman_beginning.wav",NULL,SND_ASYNC);
        printScore(player->score, 660, 285);
        printLives(player->lives, 627, 405);
        sprintf(lepel, "%d", player->level);
        //BlackSquare(24*GRIDSIZE,GRIDSIZE*2.8);
        outtextxy(720,84, lepel);
        EmptyStack(&player->ghost1.path);
        switch(player->level) {
            case 1 : bfs(player->ghost1.lastNode, prev, GraphLevel1);break;
            case 2 : bfs(player->ghost1.lastNode, prev, GraphLevel2);break;
            case 3 : bfs(player->ghost1.lastNode, prev, GraphLevel3);break;
        }

        rekamana = player->peciman.lastNode;
        GeneratePath(prev, player->ghost1.lastNode, player->peciman.lastNode, &player->ghost1.path);
//        PrintPath(player->ghost1.path);
//        system("pause");
        while(player->foodCount > 0) {
            if((player->peciman.pos.x==player->ghost1.pos.x) && (player->peciman.pos.y == player->ghost1.pos.y))
                break;
            //printf("%d ",player->foodCount);
            step++;
//                        int i, j;
//            for(i=0;i<20;i++) {
//                for(j=0;j<20;j++) {
//                    printf("%d ", levelMap[j][i].node);
//                }
//                printf("\n");
//            }
//            system("pause");
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
                if(levelMap[player->peciman.pos.x][player->peciman.pos.y].node != -1) {
                    player->peciman.lastNode = levelMap[player->peciman.pos.x][player->peciman.pos.y].node;
                }
            }
            //speed = (0.5*16);
            printf("%d %d %d %d\n", player->ghost1.lastNode,player->peciman.lastNode, rekamana, levelMap[player->ghost1.pos.x][player->ghost1.pos.y].node);
            if (step%8 == 0) {

                if (Top(player->ghost1.path)!=Nil) {
                    printf("%d\n", Top(player->ghost1.path));
                    printf("\n========================\n");
                    PrintPath(player->ghost1.path);
                    printf("\n========================\n");
                    if (player->level==1) {
                        if (player->ghost1.pos.x!=NodeLevel1[Info(Top(player->ghost1.path))][0] || player->ghost1.pos.y!=NodeLevel1[Info(Top(player->ghost1.path))][1]) {
                            GhostAutoMove(&player->ghost1, NodeLevel1[Info(Top(player->ghost1.path))]);
                            // gotoXY(startX, startY, nodepos[Info(Top(*path))][0], nodepos[Info(Top(*path))][1]);
                        }
                        else {
                            player->ghost1.lastNode = Pop(&player->ghost1.path);
    //
                        }
                    }
                    else if (player->level==2) {
                        if (player->ghost1.pos.x!=NodeLevel2[Info(Top(player->ghost1.path))][0] || player->ghost1.pos.y!=NodeLevel2[Info(Top(player->ghost1.path))][1]) {
                            GhostAutoMove(&player->ghost1, NodeLevel2[Info(Top(player->ghost1.path))]);
                            // gotoXY(startX, startY, nodepos[Info(Top(*path))][0], nodepos[Info(Top(*path))][1]);
                        }
                        else {
                            player->ghost1.lastNode = Pop(&player->ghost1.path);
    //
                        }
                    }
                    else if (player->level==3) {
                        if (player->ghost1.pos.x!=NodeLevel3[Info(Top(player->ghost1.path))][0] || player->ghost1.pos.y!=NodeLevel3[Info(Top(player->ghost1.path))][1]) {
                            GhostAutoMove(&player->ghost1, NodeLevel3[Info(Top(player->ghost1.path))]);
                            // gotoXY(startX, startY, nodepos[Info(Top(*path))][0], nodepos[Info(Top(*path))][1]);
                        }
                        else {
                            player->ghost1.lastNode = Pop(&player->ghost1.path);
    //
                        }
                    }

                }
                if (player->ghost1.lastNode!=player->peciman.lastNode && Top(player->ghost1.path)==Nil){
                    rekamana = player->peciman.lastNode;
                    EmptyStack(&player->ghost1.path);
                    switch(player->level) {
                        case 1 : bfs(player->ghost1.lastNode, prev, GraphLevel1);break;
                        case 2 : bfs(player->ghost1.lastNode, prev, GraphLevel2);break;
                        case 3 : bfs(player->ghost1.lastNode, prev, GraphLevel3);break;
                    }
                    GeneratePath(prev, player->ghost1.lastNode, player->peciman.lastNode, &player->ghost1.path);
                }
            }

            GetCursorPos(&cursorPosition);
            mX=cursorPosition.x;
            mY=cursorPosition.y;

            if (GetAsyncKeyState(VK_LBUTTON) && mX>=624 && mX<=780 && mY>=550 && mY<=600){
                menuutama();
                break;
            }
            delay(10);
            end = clock();
            time_spent = (int)(end - begin) / CLOCKS_PER_SEC; // Ulah di hapus
            // printf("%d %d %d\n", player->score, player->lives, time_spent);
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
            PlaySound("sounds/pacman_death.wav",NULL,SND_ASYNC);
            player->lives--;
            delay(1500);
        }

    }
    cleardevice();
    settextstyle(8, HORIZ_DIR,30);
    setcolor(WHITE);
    if (player->lives==0){
        outtext("GAME OVER");
        PlaySound("sounds/pacman_intermission.wav",NULL,SND_ASYNC);
        delay(1000);
         menuutama();
    }
    else{
        outtext("PLAYER WIN");
        PlaySound("sounds/pacman_intermission.wav",NULL,SND_ASYNC);
        delay(1000);
         menuutama();
    }
}
