void DrawGhost(ghostController ghost) { //M. Hisyam A
    int posX = ghost.pos.x * GRIDSIZE;
    int posY = ghost.pos.y * GRIDSIZE;
    switch(ghost.ghostType) {
        case KUNTILANAK :
                            if(ghost.stateghost==DEAD){
                                readimagefile("assets/images/eye_ghost.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);
                            }
                            else if(ghost.stateghost==BEING_CHASED){
                                readimagefile("assets/images/Ghost1PU.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);
                            }
                            else {
                            readimagefile("assets/images/Ghost1.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);
                            }
                        break;
        case POCONG :
                        if(ghost.stateghost==DEAD){
                            readimagefile("assets/images/eye_ghost.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);
                        }
                        else if(ghost.stateghost==BEING_CHASED){
                            readimagefile("assets/images/Ghost1PU.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);
                        }
                        else {
                        readimagefile("assets/images/Ghost2.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);
                        }
                        break;
        case TENGKORAK : readimagefile("assets/images/Ghost3.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case TUYUL : readimagefile("assets/images/Ghost4.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
    }
}
void InitGhost(ghostController *ghost, position pos, int ghostType) {//M. Hisyam A
    ghost->initPos.x = pos.x;
    ghost->initPos.y = pos.y;
    ghost->ghostType = ghostType;
    ghost->stateghost= 3;
    ghost->speed = DEFAULTSPEED;
}
int CanMove(ghostController ghost, int direction) {//M. Hisyam A
    switch(direction) {
        case RIGHT : return ((levelMap[ghost.pos.x+1][ghost.pos.y].Wall == EMPTY || levelMap[ghost.pos.x+1][ghost.pos.y].Wall == WALL_GHOST) && (levelMap[ghost.pos.x+1][ghost.pos.y].Object != PACMAN));
        case LEFT : return ((levelMap[ghost.pos.x-1][ghost.pos.y].Wall == EMPTY || levelMap[ghost.pos.x-1][ghost.pos.y].Wall == WALL_GHOST) && (levelMap[ghost.pos.x-1][ghost.pos.y].Object != PACMAN));
        case UP : return ((levelMap[ghost.pos.x][ghost.pos.y-1].Wall == EMPTY || levelMap[ghost.pos.x][ghost.pos.y-1].Wall == WALL_GHOST) && (levelMap[ghost.pos.x][ghost.pos.y-1].Object != PACMAN));
        case DOWN : return ((levelMap[ghost.pos.x][ghost.pos.y+1].Wall == EMPTY || levelMap[ghost.pos.x][ghost.pos.y+1].Wall == WALL_GHOST) && (levelMap[ghost.pos.x][ghost.pos.y+1].Object != PACMAN));
    }
}
void BlackSquareCheck(position pos) {//M. Hisyam A
    if (levelMap[pos.x][pos.y].Food!= EMPTY) {
        Food(levelMap[pos.x][pos.y].Food, pos);
    }
    else if (levelMap[pos.x][pos.y].Wall == WALL_GHOST){
        readimagefile("assets/images/Ghost_Wall.bmp",pos.x*GRIDSIZE, pos.y*GRIDSIZE, (pos.x*GRIDSIZE) + GRIDSIZE, (pos.y*GRIDSIZE) + GRIDSIZE);
          //BlackSquare(pos.x, pos.y);
    }
    else {
        BlackSquare(pos.x, pos.y);
    }
}
void GhostMove(ghostController *ghost) {//M. Hisyam A
    setfillstyle(SOLID_FILL, 0);
    switch(ghost->direction)
    {
        case RIGHT :
            if(CanMove(*ghost, RIGHT)){
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = EMPTY;
                ghost->pos.x++;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
        case LEFT :
            if(CanMove(*ghost, LEFT)){ // Cek apakah ada tembok atau tidak
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = EMPTY;
                ghost->pos.x--;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
        case UP :
            if(CanMove(*ghost, UP)){ // Cek apakah ada tembok atau tidak
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = EMPTY;
                ghost->pos.y--;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
        case DOWN :
            if(CanMove(*ghost, DOWN)){ // Cek apakah ada tembok atau tidak
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = EMPTY;
                ghost->pos.y++;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
    }
    DrawGhost(*ghost);
}

void GhostAutoMove(ghostController *ghost, int np) {//M. Hisyam A
        int moved =1;
        //printf("am %d %d\n", nodepos[0], nodepos[1]);
        if (abs(nodePos[np*2+0] - ghost->pos.x) > abs(nodePos[np*2+1] - ghost->pos.y) && (CanMove(*ghost, RIGHT) || CanMove(*ghost, LEFT))) {
            if(nodePos[np*2+0] > ghost->pos.x && CanMove(*ghost, RIGHT)) {
                ghost->direction = RIGHT;
            }

            else {
                ghost->direction = LEFT;
            }

        }
        else if (CanMove(*ghost, UP) || CanMove(*ghost, DOWN)){
            if(nodePos[np*2+1] > ghost->pos.y && CanMove(*ghost, DOWN)) {
                ghost->direction = DOWN;
            }
            else {
                ghost->direction = UP;
            }
        }
        // if (!moved) {
        //     if (CanMove(*ghost, UP)) {
        //          ghost->direction = UP;
        //     }
        //     else if (CanMove(*ghost, LEFT)) {
        //          ghost->direction = LEFT;
        //     }
        //     else if (CanMove(*ghost, DOWN)) {
        //          ghost->direction = DOWN;
        //     }
        //     else {
        //          ghost->direction = RIGHT;
        //     }
        // }
        GhostMove(ghost);
}

void GeneratePath(int prev[], int start, int End, Stack *path) {
    int i=End;
    while(prev[i]!=-1) {
        Push(path, i);
        //printf("%d ", i);
        i = prev[i];
    }
}

void PrintPath(Stack path) {
    while (Top(path)!=Nil) {
        printf("%d ", Info(Top(path)));
        Top(path) = Next(Top(path));
    }
}

int bfs(int v, int prev[]) {
    Queue Q;
    CreateQueue(&Q);
    EnQueue(&Q, v);

    int visited[nodeCount];
    memset(prev, 0, sizeof(prev));
    memset(visited, 0 , sizeof(visited));
    int node = DeQueue(&Q);
    visited[v] = 1;

    int i;
    for(i=0;i<nodeCount;i++) {
        prev[i] = -1;
    }
    while (1) {

        for(i=0;i<nodeCount;i++) {

            if (graph[node*nodeCount+i] == 1 && visited[i] == 0) {
                prev[i] = node;
                visited[i] = 1;
                EnQueue(&Q, i);
            }
        }
        if (Front(Q) == Nil) {
            break;
        }
        else {
            node = DeQueue(&Q);
        }
    }
    return node;
}

void ghostRealMove(ghostController * ghost, int dest) {
    int prev[nodeCount];
    int prev2[nodeCount];
    EmptyStack(&ghost->path);
    bfs(ghost->lastNode, prev);
    if(ghost->stateghost==CHASING){
        GeneratePath(prev, ghost->lastNode, dest, &ghost->path);
    }else if(ghost->stateghost==DEAD){
        GeneratePath(prev, ghost->lastNode, ghost->initNode, &ghost->path);
    }else if(ghost->stateghost==ROAMING){
        GeneratePath(prev, ghost->lastNode, randomise(0, nodeCount-1), &ghost->path);
    }
    else {
        int ln = bfs(dest, prev2);
        GeneratePath(prev, ghost->lastNode, ln, &ghost->path);
    }
}

void ghostMoveAsli(ghostController * ghost, int dest) {
    if (ghost->lastNode!=dest && Top(ghost->path)==Nil){
        ghostRealMove(ghost, dest);
    }
    if (Top(ghost->path)!=Nil) {
        printf("%d\n", Top(ghost->path));
        printf("\n========================\n");
        PrintPath(ghost->path);
        printf("\n========================\n");
        if (ghost->pos.x!=nodePos[Info(Top(ghost->path))*2+0] || ghost->pos.y!=nodePos[Info(Top(ghost->path))*2+1]) {
            GhostAutoMove(ghost, Info(Top(ghost->path)));
        }
        else {
            ghost->lastNode = Pop(&ghost->path);
            ghostRealMove(ghost, dest);
        }

    }
}

void printState(int state) {
    switch(state) {
        case CHASING : printf("Chasing\n");break;
        case BEING_CHASED : printf("Being Chased\n");break;
        case ROAMING : printf("Roaming\n");break;
        case DEAD : printf("Dead\n");break;
    }
}
