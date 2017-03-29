void DrawGhost(ghostController ghost) {
    int posX = ghost.posX * GRIDSIZE;
    int posY = ghost.posY * GRIDSIZE;
    switch(ghost.ghostType) {
        case KUNTILANAK : readimagefile("assets/images/Ghost1.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case POCONG : readimagefile("assets/images/Ghost2.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case TENGKORAK : readimagefile("assets/images/Ghost3.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case TUYUL : readimagefile("assets/images/Ghost4.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
    }
}
void InitGhost(ghostController *ghost, int posX, int posY, int ghostType) {
    ghost->posX = posX;
    ghost->posY = posY;
    ghost->ghostType = ghostType;
}
int CanMove(ghostController ghost, int direction) {
    switch(direction) {
        case RIGHT : return ((levelMap[ghost.posX+1][ghost.posY].Wall == REMPTY || levelMap[ghost.posX+1][ghost.posY].Wall == RWALL_GHOST) && (levelMap[ghost.posX+1][ghost.posY].Object == REMPTY || levelMap[ghost.posX+1][ghost.posY].Object == RPACMAN)) ? 1:0;
        case LEFT : return ((levelMap[ghost.posX-1][ghost.posY].Wall == REMPTY || levelMap[ghost.posX-1][ghost.posY].Wall == RWALL_GHOST) && (levelMap[ghost.posX-1][ghost.posY].Object == REMPTY  || levelMap[ghost.posX-1][ghost.posY].Object == RPACMAN)) ? 1:0;
        case UP : return ((levelMap[ghost.posX][ghost.posY-1].Wall == REMPTY || levelMap[ghost.posX][ghost.posY-1].Wall == RWALL_GHOST) && (levelMap[ghost.posX][ghost.posY-1].Object == REMPTY  || levelMap[ghost.posX][ghost.posY-1].Object == RPACMAN)) ? 1:0;
        case DOWN : return ((levelMap[ghost.posX][ghost.posY+1].Wall == REMPTY || levelMap[ghost.posX][ghost.posY+1].Wall == RWALL_GHOST) && (levelMap[ghost.posX][ghost.posY+1].Object == REMPTY  || levelMap[ghost.posX][ghost.posY+1].Object == RPACMAN)) ? 1:0;
    }
}
void GhostMove(ghostController *ghost) {
    setfillstyle(SOLID_FILL, 0);
    switch(ghost->direction)
    {
        case RIGHT :
            if(CanMove(*ghost, RIGHT)){ // Cek apakah ada tembok atau tidak
                BlackSquare(ghost->posX, ghost->posY);
                levelMap[ghost->posX][ghost->posY].Object = REMPTY;
                ghost->posX++;
                levelMap[ghost->posX][ghost->posY].Object = ghost->ghostType;
            }break;
        case LEFT :
            if(CanMove(*ghost, LEFT)){ // Cek apakah ada tembok atau tidak
                BlackSquare(ghost->posX, ghost->posY);
                levelMap[ghost->posX][ghost->posY].Object = REMPTY;
                ghost->posX--;
                levelMap[ghost->posX][ghost->posY].Object = ghost->ghostType;
            }break;
        case UP :
            if(CanMove(*ghost, UP)){ // Cek apakah ada tembok atau tidak
                BlackSquare(ghost->posX, ghost->posY);
                levelMap[ghost->posX][ghost->posY].Object = REMPTY;
                ghost->posY--;
                levelMap[ghost->posX][ghost->posY].Object = ghost->ghostType;
            }break;
        case DOWN :
            if(CanMove(*ghost, DOWN)){ // Cek apakah ada tembok atau tidak
                levelMap[ghost->posX][ghost->posY].Object = REMPTY;
                BlackSquare(ghost->posX, ghost->posY);
                ghost->posY++;
                levelMap[ghost->posX][ghost->posY].Object = ghost->ghostType;
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
        if (isXGreaterThanY(abs(pacman.posX - ghost->posX), abs(pacman.posY - ghost->posY))) {
            if(pacman.posX > ghost->posX && CanMove(*ghost, RIGHT)) {
                ghost->direction = RIGHT;
            }
            else if (pacman.posX < ghost->posX && CanMove(*ghost, LEFT)){
                ghost->direction = LEFT;
            }
            else {
                moved = 0;
            }
        }
        else {
            if(pacman.posY > ghost->posY && CanMove(*ghost, DOWN)) {
                ghost->direction = DOWN;
            }
            else if (pacman.posY < ghost->posY && CanMove(*ghost, UP)){
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
