void DrawGhost(ghostController ghost) {
    int posX = ghost.pos.x * GRIDSIZE;
    int posY = ghost.pos.y * GRIDSIZE;
    switch(ghost.ghostType) {
        case KUNTILANAK : readimagefile("assets/images/Ghost1.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case POCONG : readimagefile("assets/images/Ghost2.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case TENGKORAK : readimagefile("assets/images/Ghost3.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case TUYUL : readimagefile("assets/images/Ghost4.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
    }
}
void InitGhost(ghostController *ghost, position pos, int ghostType) {
    ghost->pos.x = pos.x;
    ghost->pos.y = pos.y;
    ghost->ghostType = ghostType;
}
int CanMove(ghostController ghost, int direction) {
    switch(direction) {
        case RIGHT : return ((levelMap[ghost.pos.x+1][ghost.pos.y].Wall == REMPTY || levelMap[ghost.pos.x+1][ghost.pos.y].Wall == RWALL_GHOST) && (levelMap[ghost.pos.x+1][ghost.pos.y].Object == REMPTY || levelMap[ghost.pos.x+1][ghost.pos.y].Object == RPACMAN));
        case LEFT : return ((levelMap[ghost.pos.x-1][ghost.pos.y].Wall == REMPTY || levelMap[ghost.pos.x-1][ghost.pos.y].Wall == RWALL_GHOST) && (levelMap[ghost.pos.x-1][ghost.pos.y].Object == REMPTY  || levelMap[ghost.pos.x-1][ghost.pos.y].Object == RPACMAN));
        case UP : return ((levelMap[ghost.pos.x][ghost.pos.y-1].Wall == REMPTY || levelMap[ghost.pos.x][ghost.pos.y-1].Wall == RWALL_GHOST) && (levelMap[ghost.pos.x][ghost.pos.y-1].Object == REMPTY  || levelMap[ghost.pos.x][ghost.pos.y-1].Object == RPACMAN));
        case DOWN : return ((levelMap[ghost.pos.x][ghost.pos.y+1].Wall == REMPTY || levelMap[ghost.pos.x][ghost.pos.y+1].Wall == RWALL_GHOST) && (levelMap[ghost.pos.x][ghost.pos.y+1].Object == REMPTY  || levelMap[ghost.pos.x][ghost.pos.y+1].Object == RPACMAN));
    }
}
void BlackSquareCheck(position pos) {
    if (levelMap[pos.x][pos.y].Food!=REMPTY) {
        DrawFood(levelMap[pos.x][pos.y].Food, pos);
    }
    else if (levelMap[pos.x][pos.y].Wall == RWALL_GHOST){
        DrawWall(RWALL_GHOST, pos);
    }
    else {
        BlackSquare(pos.x, pos.y);
    }
}
void GhostMove(ghostController *ghost) {
    setfillstyle(SOLID_FILL, 0);
    switch(ghost->direction)
    {
        case RIGHT :
            if(CanMove(*ghost, RIGHT)){
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = REMPTY;
                ghost->pos.x++;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
        case LEFT :
            if(CanMove(*ghost, LEFT)){ // Cek apakah ada tembok atau tidak
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = REMPTY;
                ghost->pos.x--;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
        case UP :
            if(CanMove(*ghost, UP)){ // Cek apakah ada tembok atau tidak
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = REMPTY;
                ghost->pos.y--;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
        case DOWN :
            if(CanMove(*ghost, DOWN)){ // Cek apakah ada tembok atau tidak
                BlackSquareCheck(ghost->pos);
                levelMap[ghost->pos.x][ghost->pos.y].Object = REMPTY;
                ghost->pos.y++;
                levelMap[ghost->pos.x][ghost->pos.y].Object = ghost->ghostType;
            }break;
    }
    DrawGhost(*ghost);
}
int isXGreaterThanY(int x, int y) {
    if (x>y) {
        return 1;
    }
    else {
        return 0;
    }
}
void GhostAutoMove(ghostController *ghost, pacmanController pacman) {
        int moved =1;
        if (isXGreaterThanY(abs(pacman.pos.x - ghost->pos.x), abs(pacman.pos.y - ghost->pos.y))) {
            if(pacman.pos.x > ghost->pos.x && CanMove(*ghost, RIGHT)) {
                ghost->direction = RIGHT;
            }
            else if (pacman.pos.x < ghost->pos.x && CanMove(*ghost, LEFT)){
                ghost->direction = LEFT;
            }
            else {
                moved = 0;
            }
        }
        else {
            if(pacman.pos.y > ghost->pos.y && CanMove(*ghost, DOWN)) {
                ghost->direction = DOWN;
            }
            else if (pacman.pos.y < ghost->pos.y && CanMove(*ghost, UP)){
                ghost->direction = UP;
            }
            else {
                moved = 0;
            }
        }
        if (!moved) {
            if (CanMove(*ghost, UP)) {
                 ghost->direction = UP;
            }
            else if (CanMove(*ghost, LEFT)) {
                 ghost->direction = LEFT;
            }
            else if (CanMove(*ghost, DOWN)) {
                 ghost->direction = DOWN;
            }
            else {
                 ghost->direction = RIGHT;
            }
        }
        GhostMove(ghost);
}
