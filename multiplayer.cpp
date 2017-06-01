#include "includes/multiplayer.h"
void InitLevel2(playerControl1 *player1,playerControl1 *player2); //M. Hisyam A

void InitGame2(playerControl1 *player1,playerControl1 *player2) {//M. Hisyam A
    initScore(player1);
    initScore(player2);
    initLives(player1);
    initLives(player2);
    player1->level = 1;
    player2->level = 1;
    InitLevel(player1);
    InitLevel(player2);
}
void GameRoundCheck();
void InitLevel2(playerControl1 *player1,playerControl1 *player2) { //M. Hisyam A
    switch(player1->level) {
        case 1 : CreateMap(level1, player1);nodeCount=58;createNodes(player1, NodeLevel1);break;
        case 2 : CreateMap(level2, player1);nodeCount=70;createNodes(player1, NodeLevel2);break;
        case 3 : CreateMap(level3, player1);nodeCount=60;createNodes(player1, NodeLevel3);break;
        case 4 : CreateMap(level4, player1);break;
        case 5 : CreateMap(level5, player1);break;
        case 6 : CreateMap(level6, player1);nodeCount=116;createNodes(player1, NodeLevel6);break;
        case 7 : CreateMap(level7, player1);nodeCount=12;break;
    }
     switch(player2->level) {
        case 1 : CreateMap(level1, player2);nodeCount=58;createNodes(player2, NodeLevel1);break;
        case 2 : CreateMap(level2, player2);nodeCount=70;createNodes(player2, NodeLevel2);break;
        case 3 : CreateMap(level3, player2);nodeCount=60;createNodes(player2, NodeLevel3);break;
        case 4 : CreateMap(level4, player2);break;
        case 5 : CreateMap(level5, player2);break;
        case 6 : CreateMap(level6, player2);nodeCount=116;createNodes(player2, NodeLevel6);break;
        case 7 : CreateMap(level7, player2);nodeCount=12;break;
    }
}

void ResetPosition2(playerControl1 *player1,playerControl1 *player2) {//M. Hisyam A
    player1->peciman.pos.x = player1->peciman.initPos.x;
    player2->peciman.pos.x = player2->peciman.initPos.x;
    player1->peciman.pos.y = player1->peciman.initPos.y;
    player2->peciman.pos.y = player2->peciman.initPos.y;
    player1->ghost1.pos.x = player1->ghost1.initPos.x;
    player2->ghost1.pos.x = player2->ghost1.initPos.x;
    player1->ghost1.pos.y = player1->ghost1.initPos.y;
    player2->ghost1.pos.y = player2->ghost1.initPos.y;
    player1->ghost2.pos.x = player1->ghost2.initPos.x;
    player2->ghost2.pos.x = player2->ghost2.initPos.x;
    player1->ghost2.pos.y = player1->ghost2.initPos.y;
    player2->ghost2.pos.y = player2->ghost2.initPos.y;
    player1->ghost3.pos.x = player1->ghost3.initPos.x;
    player2->ghost3.pos.x = player2->ghost3.initPos.x;
    player1->ghost3.pos.y = player1->ghost3.initPos.y;
    player2->ghost3.pos.y = player2->ghost3.initPos.y;
    player1->ghost4.pos.x = player1->ghost4.initPos.x;
    player2->ghost4.pos.x = player2->ghost4.initPos.x;
    player1->ghost4.pos.y = player1->ghost4.initPos.y;
    player2->ghost4.pos.y = player2->ghost4.initPos.y;

    player1->ghost1.lastNode = levelMap[player1->ghost1.pos.x][player1->ghost1.pos.y].node;
    player2->ghost1.lastNode = levelMap[player2->ghost1.pos.x][player2->ghost1.pos.y].node;
    player1->peciman.lastNode = levelMap[player1->peciman.pos.x][player1->peciman.pos.y].node;
    player2->peciman.lastNode = levelMap[player2->peciman.pos.x][player2->peciman.pos.y].node;
}

void ResetPositionGhost2(playerControl1 *player1,playerControl1 *player2) {
    player1->ghost1.pos.x = player1->ghost1.initPos.x;
    player2->ghost1.pos.x = player2->ghost1.initPos.x;
    player1->ghost1.pos.y = player->ghost1.initPos.y;
    player2->ghost1.pos.y = player->ghost1.initPos.y;
    player1->ghost1.lastNode = levelMap[player1->ghost1.pos.x][player1->ghost1.pos.y].node;
    player2->ghost1.lastNode = levelMap[player2->ghost1.pos.x][player2->ghost1.pos.y].node;
    player1->ghost2.pos.x = player1->ghost2.initPos.x;
    player2->ghost2.pos.x = player2->ghost2.initPos.x;
    player1->ghost2.pos.y = player1->ghost2.initPos.y;
    player2->ghost2.pos.y = player2->ghost2.initPos.y;
    player1->ghost3.pos.x = player1->ghost3.initPos.x;
    player2->ghost3.pos.x = player2->ghost3.initPos.x;
    player1->ghost3.pos.y = player1->ghost3.initPos.y;
    player2->ghost3.pos.y = player2->ghost3.initPos.y;
    player1->ghost4.pos.x = player1->ghost4.initPos.x;
    player2->ghost4.pos.x = player2->ghost4.initPos.x;
    player1->ghost4.pos.y = player1->ghost4.initPos.y;
    player2->ghost4.pos.y = player2->ghost4.initPos.y;
}

void GameStart2(playerControl1 *player1,playerControl1 *player2) { //Hisyam, Fadhit, Fahmi
    int rekamana1,rekamana2;
    clock_t begin;
    clock_t end;
    char choose;
    int time_spent;
    int step = 0;
    char scoreText1[20];
    char scoreText2[20];
    char livesText1[20];
    char livesText2[20];
    int liveGiven=0;
    char lepel[2];
    CreateStack(&player1->ghost1.path);
    CreateStack(&player2->ghost1.path);
    int prev[nodeCount];
    int speed;
    position pos;
    pos.x=-1;
    pos.y=-1;
    //PrintPath(path);
    while (player1->lives>0&& player1->level<=7 || player2->lives>0&& player2->level<=7) {
        cleardevice();
        DrawSideMenu();
        settextstyle(8, HORIZ_DIR,1);
        outtextxy(660, 165,player1->name);
        outtextxy(660, 180,player2->name);
        ResetPosition2(player1);
        ResetPosition2(player2);
        DrawMap();
        DrawGhost(player1->ghost1);
        DrawPacman(player1->peciman);
        DrawPacman(player2->peciman);
        begin = clock();
        srand(time(NULL));
        PlaySound("sounds/pacman_beginning.wav",NULL,SND_ASYNC);
        printScore(player1->score, 660, 285);
        printLives(player2->lives, 627, 405);
        sprintf(lepel, "%d", player1->level);
        sprintf(lepel, "%d", player2->level);
        //BlackSquare(24*GRIDSIZE,GRIDSIZE*2.8);
        outtextxy(720,84, lepel);
        EmptyStack(&player1->ghost1.path);
        switch(player1->level) {
            case 1 : bfs(player1->ghost1.lastNode, prev, GraphLevel1);break;
            case 2 : bfs(player1->ghost1.lastNode, prev, GraphLevel2);break;
            case 3 : bfs(player1->ghost1.lastNode, prev, GraphLevel3);break;
        }
        switch(player2->level) {
            case 1 : bfs(player2->ghost2.lastNode, prev, GraphLevel1);break;
            case 2 : bfs(player2->ghost2.lastNode, prev, GraphLevel2);break;
            case 3 : bfs(player2->ghost2.lastNode, prev, GraphLevel3);break;
        }
        rekamana1 = player1->peciman.lastNode;
        rekamana2 = player2->peciman.lastNode;
        GeneratePath(prev, player1->ghost1.lastNode, player1->peciman.lastNode, &player1->ghost1.path);
//        PrintPath(player->ghost1.path);
//        system("pause");
        while(player1->foodCount > 0 && player2->foodCount > 0) {
            if((player1->peciman.pos.x==player1->ghost1.pos.x) && (player1->peciman.pos.y == player1->ghost1.pos.y))
                break;
            if((player2->peciman.pos.x==player2->ghost1.pos.x) && (player2->peciman.pos.y == player2->ghost1.pos.y))
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
                    player1->peciman.nextDirection = RIGHT;
                    break;

                case LEFTARROW :
                    player1->peciman.nextDirection = LEFT;
                    break;

                case DOWNARROW :
                    player1->peciman.nextDirection = DOWN;
                    break;

                case UPARROW :
                     player1->peciman.nextDirection = UP;
                    break;
                case RIGHTARROW2 :
                    player2->peciman.nextDirection = RIGHT;
                    break;

                case LEFTARROW2 :
                    player2->peciman.nextDirection = LEFT;
                    break;

                case DOWNARROW2 :
                    player2->peciman.nextDirection = DOWN;
                    break;

                case UPARROW2 :
                     player2->peciman.nextDirection = UP;
                    break;

                //case 13: spawnFood(&levelMap[9][12],9,12); break;
                }
            }
            if (step%8 == 0){
                if (CanMovePeciman(player1->peciman , player1->peciman.nextDirection)) // dicek apakah ada penghalang tembok atau tidak
                {
                    player1->peciman.direction = player1->peciman.nextDirection; // perubahan arah jika tidak ada tembok
                }if (CanMovePeciman(player2->peciman , player2->peciman.nextDirection)) // dicek apakah ada penghalang tembok atau tidak
                {
                    player2->peciman.direction = player2->peciman.nextDirection; // perubahan arah jika tidak ada tembok
                }
                Move(&player1->peciman);
                Move(&player2->peciman);

                if(levelMap[player1->peciman.pos.x][player1->peciman.pos.y].Food != 0){
//                    eatFood(player1);
                    printScore(player1->score, 660, 285);
//                    incLives(player1, &liveGiven);
                    printLives(player1->lives, 627, 405);
                }
                if(levelMap[player2->peciman.pos.x][player2->peciman.pos.y].Food != 0){
                    eatFood(player2);
                    printScore(player2->score, 660, 290);
                    incLives(player2, &liveGiven);
                    printLives(player2->lives, 627, 410);
                }
                changeState(&player1->peciman); // mengubah keadaan pacman dari membuka menjadi tertutup
                changeState(&player2->peciman); // mengubah keadaan pacman dari membuka menjadi tertutup
                if(levelMap[player1->peciman.pos.x][player1->peciman.pos.y].node != -1) {
                    player1->peciman.lastNode = levelMap[player1->peciman.pos.x][player1->peciman.pos.y].node;
                }
                if(levelMap[player2->peciman.pos.x][player2->peciman.pos.y].node != -1) {
                    player2->peciman.lastNode = levelMap[player2->peciman.pos.x][player2->peciman.pos.y].node;
                }
            }
            //speed = (0.5*16);
            printf("%d %d %d %d\n", player1->ghost1.lastNode,player1->peciman.lastNode, rekamana1, levelMap[player1->ghost1.pos.x][player1->ghost1.pos.y].node);
            printf("%d %d %d %d\n", player2->ghost1.lastNode,player2->peciman.lastNode, rekamana2, levelMap[player2->ghost1.pos.x][player2->ghost1.pos.y].node);
            if (step%8 == 0) {

                if (Top(player1->ghost1.path)!=Nil || Top(player2->ghost1.path)!=Nil) {
                    printf("%d\n", Top(player1->ghost1.path));
                    printf("\n========================\n");
                    printf("%d\n", Top(player2->ghost1.path));
                    printf("\n========================\n");
                    PrintPath(player1->ghost1.path);
                    printf("\n========================\n");
                    PrintPath(player2->ghost1.path);
                    printf("\n========================\n");
                    if (player1->level==1 || player2->level==1) {
                        if (player1->ghost1.pos.x!=NodeLevel1[Info(Top(player1->ghost1.path))][0] || player1->ghost1.pos.y!=NodeLevel1[Info(Top(player1->ghost1.path))][1] || player2->ghost1.pos.x!=NodeLevel1[Info(Top(player2->ghost1.path))][0] || player2->ghost1.pos.y!=NodeLevel1[Info(Top(player2->ghost1.path))][1]) {
                            GhostAutoMove(&player1->ghost1, NodeLevel1[Info(Top(player1->ghost1.path))]);
                            GhostAutoMove(&player2->ghost1, NodeLevel1[Info(Top(player2->ghost1.path))]);
                            // gotoXY(startX, startY, nodepos[Info(Top(*path))][0], nodepos[Info(Top(*path))][1]);
                        }
                        else {
                            player1->ghost1.lastNode = Pop(&player1->ghost1.path);
                            player2->ghost1.lastNode = Pop(&player2->ghost1.path);
    //
                        }
                    }
                    else if (player1->level==2 || player2->level==2) {
                        if (player1->ghost1.pos.x!=NodeLevel2[Info(Top(player1->ghost1.path))][0] || player1->ghost1.pos.y!=NodeLevel2[Info(Top(player1->ghost1.path))][1] || player2->ghost1.pos.x!=NodeLevel2[Info(Top(player2->ghost1.path))][0] || player2->ghost1.pos.y!=NodeLevel2[Info(Top(player2->ghost1.path))][1]) {
                            GhostAutoMove(&player1->ghost1, NodeLevel2[Info(Top(player1->ghost1.path))]);
                            GhostAutoMove(&player2->ghost1, NodeLevel2[Info(Top(player2->ghost1.path))]);
                            // gotoXY(startX, startY, nodepos[Info(Top(*path))][0], nodepos[Info(Top(*path))][1]);
                        }
                        else {
                            player1->ghost1.lastNode = Pop(&player1->ghost1.path);
                            player2->ghost1.lastNode = Pop(&player2->ghost1.path);
    //
                        }
                    }
                    else if (player1->level==3 || player2->level==3) {
                        if (player1->ghost1.pos.x!=NodeLevel3[Info(Top(player1->ghost1.path))][0] || player1->ghost1.pos.y!=NodeLevel3[Info(Top(player1->ghost1.path))][1] || player2->ghost1.pos.x!=NodeLevel3[Info(Top(player2->ghost1.path))][0] || player2->ghost1.pos.y!=NodeLevel3[Info(Top(player2->ghost1.path))][1]) {
                            GhostAutoMove(&player1->ghost1, NodeLevel3[Info(Top(player1->ghost1.path))]);
                            GhostAutoMove(&player2->ghost1, NodeLevel3[Info(Top(player2->ghost1.path))]);
                            // gotoXY(startX, startY, nodepos[Info(Top(*path))][0], nodepos[Info(Top(*path))][1]);
                        }
                        else {
                            player1->ghost1.lastNode = Pop(&player1->ghost1.path);
                            player2->ghost1.lastNode = Pop(&player2->ghost1.path);
    //
                        }
                    }

                }
                if (player1->ghost1.lastNode!=player1->peciman.lastNode && Top(player1->ghost1.path)==Nil && player2->ghost1.lastNode!=player2->peciman.lastNode && Top(player2->ghost1.path)==Nil){
                    rekamana1 = player1->peciman.lastNode;
                    rekamana2 = player2->peciman.lastNode;
                    EmptyStack(&player1->ghost1.path);
                    EmptyStack(&player2->ghost1.path);
                    switch(player1->level) {
                        case 1 : bfs(player1->ghost1.lastNode, prev, GraphLevel1);break;
                        case 2 : bfs(player1->ghost1.lastNode, prev, GraphLevel2);break;
                        case 3 : bfs(player1->ghost1.lastNode, prev, GraphLevel3);break;
                    }
                     switch(player2->level) {
                        case 1 : bfs(player2->ghost1.lastNode, prev, GraphLevel1);break;
                        case 2 : bfs(player2->ghost1.lastNode, prev, GraphLevel2);break;
                        case 3 : bfs(player2->ghost1.lastNode, prev, GraphLevel3);break;
                    }
                    GeneratePath(prev, player1->ghost1.lastNode, player1->peciman.lastNode, &player1->ghost1.path);
                    GeneratePath(prev, player2->ghost1.lastNode, player2->peciman.lastNode, &player2->ghost1.path);
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
                pos = randFood(player1);
                spawnFood(&levelMap[pos.x][pos.y],pos.x,pos.y);
                begin=clock();
            }
            if(pos.x!=-1 && pos.y!=-1){
                if((time_spent==20 && (levelMap[pos.x][pos.y].Food==FOOD2 || levelMap[pos.x][pos.y].Food==FOOD3)) || (time_spent==15 && levelMap[pos.x][pos.y].Food==FOOD4) || (time_spent==10 && levelMap[pos.x][pos.y].Food==FOOD5)){
                    despawnFood(&levelMap[pos.x][pos.y],pos.x,pos.y);
                }
            }
        }
        if (player1->foodCount == 0) {
            printf("Game End");
            player1->level++;
            InitLevel2(player1);
        }
        else {
            PlaySound("sounds/pacman_death.wav",NULL,SND_ASYNC);
            player1->lives--;
            delay(1500);
        }

    }
    cleardevice();
    settextstyle(8, HORIZ_DIR,30);
    setcolor(WHITE);
    if (player1->lives==0){
        outtext("GAME OVER PLAYER 1");
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
