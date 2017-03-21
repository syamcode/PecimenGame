
int IsWall_Hor(int x) {
    return x==WALL_HOR?1:0;
}
int IsWall_Ver(int x) {
    return x==WALL_VER?1:0;
}
int IsWall_Cor_UpRight(int x) {
    return x == WALL_COR_UPRIGHT?1:0;
}
int IsWall_Cor_UpLeft(int x) {
    return x == WALL_COR_UPLEFT?1:0;
}
int IsWall_Cor_UnderRight (int x) {
    return x == WALL_COR_UNDERRIGHT?1:0;
}
int IsWall_Cor_UnderLeft(int x) {
    return x == WALL_COR_UNDERLEFT?1:0;
}
int IsWall_Limit_Up(int x) {
    return x == WALL_LIMIT_UP?1:0;
}
int IsWall_Limit_Down(int x) {
    return x == WALL_LIMIT_DOWN?1:0;
}
int IsWall_Limit_Left(int x) {
    return x == WALL_LIMIT_LEFT?1:0;
}
int IsWall_Limit_Right(int x) {
    return x == WALL_LIMIT_RIGHT?1:0;
}
int IsPacman(int x) {
    return x & PACMAN;
}
int IsFood1(int x) {
    return x & FOOD1;
}
int IsFood2(int x) {
    return x & FOOD2;
}
int IsFood3(int x) {
    return x & FOOD3;
}
int IsFood4(int x) {
    return x & FOOD4;
}
int IsFood5(int x) {
    return x & FOOD5;
}
int IsGhost1(int x) {
    return x & GHOST1;
}
int IsGhost2(int x) {
    return x & GHOST2;
}
int IsGhost3(int x) {
    return x & GHOST3;
}
int IsGhost4(int x) {
    return x & GHOST4;
}
void DrawWall(int wall,int posX, int posY) {
    switch(wall){
        case RWALL_HOR : readimagefile("assets/images/Wall_Hor.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_VER : readimagefile("assets/images/Wall_Ver.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UNDERLEFT : readimagefile("assets/images/Wall_Cor_DownLeft.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UNDERRIGHT : readimagefile("assets/images/Wall_Cor_DownRight.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UPLEFT : readimagefile("assets/images/Wall_Cor_UPLEFT.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UPRIGHT : readimagefile("assets/images/Wall_Cor_UPRIGHT.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_LIMIT_UP : readimagefile("assets/images/Wall_Limit_Up.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_LIMIT_DOWN : readimagefile("assets/images/Wall_Limit_Down.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_LIMIT_LEFT : readimagefile("assets/images/Wall_Limit_Left.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_LIMIT_RIGHT : readimagefile("assets/images/Wall_Limit_Right.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
    }
}
void DrawFood(int wall,int posX, int posY) {
    switch(wall){
        case RWALL_HOR : readimagefile("assets/images/Wall.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_VER : readimagefile("assets/images/wallLeft.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UNDERLEFT : readimagefile("assets/images/Wall2.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
    }
}
void DrawObject(int wall,int posX, int posY) {
    switch(wall){
        case RWALL_HOR : readimagefile("assets/images/Wall3.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_VER : readimagefile("assets/images/wall.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UNDERLEFT : readimagefile("assets/images/Wall2.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
    }
}


void DrawMap()
{
     int i, j;
    for (i=0;i<20;i++) {
        for(j=0;j<20;j++) {
            {
            if(levelMap[j][i].Wall!=0)
                {
                DrawWall(levelMap[j][i].Wall,i*GRIDSIZE,j*GRIDSIZE);
                }
            }if(levelMap[j][i].Food!=0)
                {
                DrawFood(levelMap[j][i].Food,j,i);
                }
            }if(levelMap[j][i].Object!=0)
            {
                DrawObject(levelMap[j][i].Object,j,i);
            }
    }
}

int level1[20][20]= {
                    {15, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13, 1, 1,  1,  1,  1,  1,  1,  1, 13, 13, 1, 1, 1, 1, 1, 1, 1, 1, 13},
                    {13, 1, 15, 12, 14, 1,  15, 14, 1, 13, 13, 1, 15, 14, 1, 15, 12, 14, 1, 13},
                    {13, 1, 17, 12, 16, 1,  17, 16, 1, 19, 19, 1, 17, 16, 1, 17, 12, 16, 1, 13},
                    {13, 1, 1,  1,  1,  1,  1,  1,  1,  1,  1, 1,  1,  1,  1, 1, 1, 1, 1, 13},
                    {13, 1, 15, 14, 1,  18, 1,  18, 1,  1,  1, 1,  18, 1, 18, 1, 15, 14, 1, 13},
                    {13, 1, 17, 16, 1,  13, 1,  17, 12, 12, 12,12, 16, 1, 13, 1, 17, 16, 1, 13},
                    {13, 1, 1,  1,  1,  13, 1,  1,  1,  1,  1, 1,   1, 1, 13, 1, 1, 1, 1, 13},
                    {17, 12,12, 12, 12, 16, 1,  15, 21, 1,  1, 20, 14, 1, 17, 12, 12, 12, 12, 16},
                    {1,  1, 1,  1,  1,  1,  1,  13,  1, 1,  1,  1, 13, 1,  1,  1,  1,  1,  1,  1},
                    {18, 1, 1,  1,  1,  1,  1,  13,  1, 1,  1,  1, 13, 1,  1,  1,  1,  1,  1, 18},
                    {13, 1, 1,  1,  1,  1,  1,  17, 12,12, 12, 12, 16,1, 1, 1, 1, 1, 1, 13},
                    {13, 1, 1,  1,  1,  1,  1,  1,   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 13},
                    {13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 13},
                    {13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 13},
                    {13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 13},
                    {13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 13},
                    {13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 13},
                    {13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 13},
                    {17, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,16}
                    };

void CreateMap(int maps[20][20])
{
       int i, j;
    for (i=0;i<20;i++) {
        for(j=0;j<20;j++) {

            if (IsWall_Hor(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_HOR;
            }else if (IsWall_Ver(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_VER;
            }else if (IsWall_Cor_UnderLeft(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_COR_UNDERLEFT;
            } else if (IsWall_Cor_UnderRight(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_COR_UNDERRIGHT;
            }else if (IsWall_Cor_UpLeft(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_COR_UPLEFT;
            }else if (IsWall_Cor_UpRight(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_COR_UPRIGHT;
            }else if (IsWall_Limit_Up(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_LIMIT_UP;
            }else if (IsWall_Limit_Down(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_LIMIT_DOWN;
            }else if (IsWall_Limit_Left(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_LIMIT_LEFT;
            }else if (IsWall_Limit_Right(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_LIMIT_RIGHT;
            }
            else {
                    levelMap[j][i].Wall=REMPTY;
            }
            if (IsGhost1(maps[j][i])) {
                levelMap[j][i].Object=RGHOST1;
            }else if (IsGhost2(maps[j][i])) {
                levelMap[j][i].Object=RGHOST2;
            }else if (IsGhost3(maps[j][i])) {
                levelMap[j][i].Object=RGHOST3;
            }else if (IsGhost4(maps[j][i])) {
                levelMap[j][i].Object=RGHOST4;
            }else if (IsPacman(maps[j][i])) {
                levelMap[j][i].Object=RPACMAN;
            }else{
                  levelMap[j][i].Object=0;
            }
            if (IsFood1(maps[j][i])) {
                levelMap[j][i].Food=RFOOD1;
            }else if (IsFood2(maps[j][i])) {
                levelMap[j][i].Food=RFOOD2;
            }else if (IsFood3(maps[j][i])) {
                levelMap[j][i].Food=RFOOD3;
            }else if (IsFood4(maps[j][i])) {
                levelMap[j][i].Food=RFOOD4;
            }else if (IsFood5(maps[j][i])) {
                levelMap[j][i].Food=RFOOD5;
            }else{
              levelMap[j][i].Food=0;
            }
        }
    }
}

