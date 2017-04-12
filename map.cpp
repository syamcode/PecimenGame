//prosedur untuk mengambar Wall menggunakan sprite sesuai kondisi di array dengan parameter jenis wall , posisi x, posisi y (by pega)
void DrawWall(int wall, position pos) {
    pos.x *= GRIDSIZE;
    pos.y *= GRIDSIZE;
    switch(wall){
        case WALL_HOR : readimagefile("assets/images/Wall_Hor.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_VER : readimagefile("assets/images/Wall_Ver.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_COR_UNDERLEFT : readimagefile("assets/images/Wall_Cor_DownLeft.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_COR_UNDERRIGHT : readimagefile("assets/images/Wall_Cor_DownRight.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_COR_UPLEFT : readimagefile("assets/images/Wall_Cor_UPLEFT.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_COR_UPRIGHT : readimagefile("assets/images/Wall_Cor_UPRIGHT.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_LIMIT_UP : readimagefile("assets/images/Wall_Limit_Up.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_LIMIT_DOWN : readimagefile("assets/images/Wall_Limit_Down.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_LIMIT_LEFT : readimagefile("assets/images/Wall_Limit_Left.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_LIMIT_RIGHT : readimagefile("assets/images/Wall_Limit_Right.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case WALL_GHOST : readimagefile("assets/images/Wall_Ghost.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
    }
}
//prosedur untuk mengambar food menggunakan sprite sesuai kondisi di array dengan parameter jenis food , posisi x , posisi y (by pega)
void DrawFood(int food,position pos) {
    pos.x *= GRIDSIZE;
    pos.y *= GRIDSIZE;
    switch(food){
        case FOOD1 : readimagefile("assets/images/FOOD1.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case FOOD2 : readimagefile("assets/images/FOOD2.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case FOOD3 : readimagefile("assets/images/FOOD3.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case FOOD4 : readimagefile("assets/images/FOOD4.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case FOOD5 : readimagefile("assets/images/FOOD5.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
    }
}

//prosedure untuk menggambar arena dengan struktur data array berukuran 20x20 dengan ukuran pixel 30 (by pega)
void DrawMap()
{
    position pos;
    int i, j;
    for (i=0;i<20;i++) { //mengecek posisi array ke arah y
        for(j=0;j<20;j++) { //Mengecek posisi array ke arah x
            pos.x = i;
            pos.y = j;
            if(levelMap[i][j].Wall!=0) //pengecekan jika kondisi isi array menunjukan WALL
            {
                DrawWall(levelMap[i][j].Wall,pos);
            }
            if(levelMap[i][j].Food!=0) //pengecekan jika kondisi isi array menunjukan food
            {
                DrawFood(levelMap[i][j].Food,pos);
            }
        }
    }
}

//struktur data aray untuk level 1 berukuran 20x20 (by Pega)
int level1[20][20]= {
                    {15, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13,  7, 7,  7,  7,  7,  7,  7,  7, 13, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 12, 14,  7, 15, 14,  7, 13, 13,  7, 15, 14,  7, 15, 12, 14,  7, 13},
                    {13, 7, 17, 12, 16,  7, 17, 16,  7, 19, 19,  7, 17, 16,  7, 17, 12, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 14,  7,  18, 7, 18,  7,  7,  7,  7, 18,  7, 18,  7, 15, 14,  7, 13},
                    {13, 7, 17, 16,  7,  13, 7, 17, 12, 12, 12, 12, 16,  7, 13,  7, 17, 16,  7, 13},
                    {13, 7,  7,  7,  7,  13, 1,  1,   1, 1,  1,  1,  1,  1, 13,  7,  7,  7,  7, 13},
                    {17,12, 12, 12, 12,  16, 1, 15,  21,22, 22, 20, 14,  1, 17, 12, 12, 12, 12, 16},
                    { 1, 1,  1,  1,  1,   1, 1, 13,   1, 1,  1,  1, 13,  1,  1,  1,  1,  1,  1, 1},
                    { 1, 1,  1,  1,  1,   1, 1, 13,   3, 4,  5,  6, 13,  1,  1,  1,  1,  1,  1, 1},
                    {15,12, 12, 12, 12,  21, 1, 17,  12,12, 12, 12, 16,  1, 20, 12, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7,   7, 1,  1,   1, 2, 1,  1,  1,  1,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 21,  7,  18, 7, 20,  12,12, 12, 12, 21,  7, 18,  7, 20, 14,  7, 13},
                    {13, 7, 13,  7,  7,  13, 7,  7,   7, 7,  7,  7,  7,  7, 13,  7,  7, 13,  7, 13},
                    {13, 7, 13,  7, 20,  16, 7, 18,   7,18, 18,  7, 18,  7, 17, 21,  7, 13,  7, 13},
                    {13, 7, 13,  7,  7,   7, 7, 13,   7,13, 13,  7, 13,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 17, 12, 21,   7,20, 16,   7,19, 19,  7, 17, 21,  7, 20, 12, 16,  7, 13},
                    {13, 7,  7,  7,  7,   7, 7,  7,   7, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17, 12, 12,12, 12,  12, 12, 12, 12, 12, 12, 12,12, 12, 12, 12, 12, 12, 12, 16}
                    };
//struktur data aray untuk level 2 berukuran 20x20 (by Pega)
int level2[20][20]= {
                    {15,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7, 18,  7,  7,  7, 15, 14,  7,  7,  7, 18,  7,  7,  7,  7, 13},
                    {13, 7, 20, 21,  7, 19,  7, 18,  7, 17, 16,  7, 18,  7, 19,  7, 20, 21,  7, 13},
                    {13, 7, 7,  7,  7,  7,  7, 13,  7,  7,  7,  7, 13,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 20, 12, 12, 21,  7, 17, 12, 12, 12, 12, 16,  7, 20, 12, 12, 21,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17,12, 12, 21,  7, 15, 12, 12, 21,  7,  7, 20, 12, 12, 14,  7, 20, 12, 12, 16},
                    {7 , 7,  7,  7,  7, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7,  7,  7,  7,  7},
                    {18, 7, 15, 14,  7, 13,  7, 15, 21, 22, 22, 20, 14,  7, 13,  7, 15, 14,  7, 18},
                    {13, 7, 17, 16,  7, 19,  7, 13,  1,  1,  1,  1, 13,  7, 19,  7, 17, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7, 13,  1,  3,  1,  1, 13,  7,  7,  7,  7,  7,  7, 13},
                    {19, 7, 20, 21,  7, 20, 21, 17, 12, 12, 12, 12, 16, 20, 21,  7, 20, 21,  7, 19},
                    {7 , 7,  7,  7,  7,  7,  7,  7,  7,  2,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7},
                    {15,12, 12, 12, 21,  7, 20, 21,  7, 20, 21,  7, 20, 21,  7, 20, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 18,  7, 20, 12, 21,  7, 20, 14, 15, 21,  7, 20, 12, 21,  7, 18,  7, 13},
                    {13, 7, 13,  7,  7,  7,  7,  7,  7, 13, 13,  7,  7,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 17, 21,  7, 20, 12, 21,  7, 13, 13,  7, 20, 12, 21,  7, 20, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7, 19, 19,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17, 12, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 16}
                    };
//struktur data aray untuk level 2 berukuran 20x20 (by Pega)
 int level3[20][20]= {
                    {15,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 12, 21,  7, 20, 12, 12, 12, 12, 12, 12, 21,  7, 20, 12, 14,  7, 13},
                    {13, 7, 13,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 13,  7, 20, 14,  7, 20, 12, 12, 12, 12, 21,  7, 15, 21,  7, 13,  7, 13},
                    {13, 7, 13,  7,  7, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7,  7, 13,  7, 13},
                    {13, 7, 17, 21,  7, 19,  7, 20, 12, 12, 12, 12, 21,  7, 19,  7, 20, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17,12, 12, 12, 12, 21,  7, 15, 21, 22, 22, 20, 14,  7, 20, 12, 12, 12, 12, 16},
                    { 1, 1,  1,  1,  1,  1,  7, 13,  1,  1,  1,  1, 13,  7,  1,  1,  1,  1,  1,  1},
                    { 1, 1,  1,  1,  1,  1,  7, 13,  1,  3,  1,  1, 13,  7,  1,  1,  1,  1,  1,  1},
                    {15,12, 12, 12, 12, 21,  7, 17, 12, 12, 12, 12, 16,  7, 20, 12, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7,  7,  7,  1,  1,  2,  1,  1,  1,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 21,  7, 18,  7, 20, 12, 12, 12, 12, 21,  7, 18,  7, 20, 14,  7, 13},
                    {13, 7, 13,  7,  7, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7,  7, 13,  7, 13},
                    {13, 7, 13,  7, 20, 16,  7, 20, 12, 12, 12, 12, 21,  7, 17, 21,  7, 13,  7, 13},
                    {13, 7, 13,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 17, 12, 21,  7, 20, 12, 12, 12, 12, 12, 12, 21,  7, 20, 12, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17, 12, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 16}
                    };
//Prosedure untuk membuat map dengan parameter
void CreateMap(int maps[20][20], playerControl *player)
{
    position pos;
    int i, j;
    player->foodCount = 0;
    for (i=0;i<20;i++) {
        for(j=0;j<20;j++) {
            pos.x = i;
            pos.y = j;
            // Kondisi pengecekan untuk setiap jenis wall
            if (maps[j][i]==WALL_HOR) {
                levelMap[i][j].Wall=WALL_HOR;
            }
            else if (maps[j][i]==WALL_VER) {
                levelMap[i][j].Wall=WALL_VER;
            }
            else if (maps[j][i]==WALL_COR_UNDERLEFT) {
                levelMap[i][j].Wall=WALL_COR_UNDERLEFT;
            }
            else if (maps[j][i]==WALL_COR_UNDERRIGHT) {
                levelMap[i][j].Wall=WALL_COR_UNDERRIGHT;
            }
            else if (maps[j][i]==WALL_COR_UPLEFT) {
                levelMap[i][j].Wall=WALL_COR_UPLEFT;
            }
            else if (maps[j][i]==WALL_COR_UPRIGHT) {
                levelMap[i][j].Wall=WALL_COR_UPRIGHT;
            }
            else if (maps[j][i]==WALL_LIMIT_UP) {
                levelMap[i][j].Wall=WALL_LIMIT_UP;
            }
            else if (maps[j][i]==WALL_LIMIT_DOWN) {
                levelMap[i][j].Wall=WALL_LIMIT_DOWN;
            }
            else if (maps[j][i]==WALL_LIMIT_LEFT) {
                levelMap[i][j].Wall=WALL_LIMIT_LEFT;
            }
            else if (maps[j][i]==WALL_LIMIT_RIGHT) {
                levelMap[i][j].Wall=WALL_LIMIT_RIGHT;
            }
            else if (maps[j][i]==WALL_GHOST) {
                levelMap[i][j].Wall=WALL_GHOST;
            }
            else {
                levelMap[i][j].Wall=EMPTY;
            }

            // Kondisi pengecekan untuk Objek bergerak
            if (maps[j][i]==KUNTILANAK) {
                levelMap[i][j].Object=KUNTILANAK;
                InitGhost(&player->ghost1, pos, KUNTILANAK);
            }
            else if (maps[j][i]==POCONG) {
                levelMap[i][j].Object=POCONG;
                InitGhost(&player->ghost2, pos, POCONG);
            }
            else if (maps[j][i]==TENGKORAK) {
                levelMap[i][j].Object=TENGKORAK;
                InitGhost(&player->ghost3, pos, TENGKORAK);
            }
            else if (maps[j][i]==TUYUL){
                levelMap[i][j].Object=TUYUL;
                InitGhost(&player->ghost4, pos, TUYUL);
            }
            else if (maps[j][i]==PACMAN) {
                levelMap[i][j].Object=PACMAN; // Masukan RPACMAN ke record jika angka yang di map adalah angka pacman
                InitPacman(&player->peciman, i, j); // Kondisi pertama pacman

            }
            else{
                  levelMap[i][j].Object=EMPTY;
            }

            // Kondisi pengecekan untuk Food
            if (maps[j][i]==FOOD1) {
                levelMap[i][j].Food=FOOD1;
                player->foodCount++;
            }
            else if (maps[j][i]==FOOD2) {
                levelMap[i][j].Food=FOOD2;
            }
            else if (maps[j][i]==FOOD3) {
                levelMap[i][j].Food=FOOD3;
            }
            else if (maps[j][i]==FOOD4) {
                levelMap[i][j].Food=FOOD4;
            }
            else if (maps[j][i]== FOOD5) {
                levelMap[i][j].Food=FOOD5;
            }
            else{
                levelMap[i][j].Food=EMPTY;
            }
        }
    }
}
