int nodeCount = 1;
//prosedur untuk mengambar Wall menggunakan sprite sesuai kondisi di array dengan parameter jenis wall , posisi x, posisi y (by pega)
void DrawWall(int level) {
//    pos.x *= GRIDSIZE;
//    pos.y *= GRIDSIZE;
    switch(level){
            //   DrawSideMenu();
        case 1 :
          readimagefile("assets/images/Map1.bmp",0,0,800,600);
          break;
        case 2 :
          readimagefile("assets/images/Map2.bmp",0,0,800,600);
          break;
        case 3 :
          readimagefile("assets/images/Map3.bmp",0,0,800,600);
          break;
        case 4 :
          readimagefile("assets/images/Map4.bmp",0,0,800,600);
          break;
        case 5 :
          readimagefile("assets/images/Map5.bmp",0,0,800,600);
          break;
        case 6 :
          readimagefile("assets/images/Map6.bmp",0,0,800,600);
          break;
        case 7 :
          readimagefile("assets/images/Map7.bmp",0,0,800,600);
          break;
        }
//        if(wall==WALL_GHOST){
//                readimagefile("assets/images/Ghost_Wall.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
//        }
}
//prosedur untuk mengambar food menggunakan sprite sesuai kondisi di array dengan parameter jenis food , posisi x , posisi y (by pega)
void Food(int food,position pos) {
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
        case POWER_UP : readimagefile("assets/images/powerUp.bmp",pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE); //Haya Utami
        break;
    }
}

void DrawPortal(int portal, position pos)
{
    pos.x *= GRIDSIZE;
    pos.y *= GRIDSIZE;
    switch(portal){
        case IN_PORTAL : readimagefile("assets/images/IN_portal.bmp", pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
        case OUT_PORTAL : readimagefile("assets/images/OUT_portal.bmp", pos.x, pos.y, pos.x + GRIDSIZE, pos.y + GRIDSIZE);
        break;
    }
}

//prosedure untuk menggambar arena dengan struktur data array berukuran 20x20 dengan ukuran pixel 30 (by pega)
void DrawMap(int level)
{
    position pos;
    int i, j;
    for (i=0;i<20;i++) { //mengecek posisi array ke arah y
        for(j=0;j<20;j++) { //Mengecek posisi array ke arah x
            pos.x = i;
            pos.y = j;
            if(levelMap[i][j].Wall==WALL_GHOST)//pengecekan jika kondisi isi array menunjukan WALL
            {
                readimagefile("assets/images/Ghost_Wall.bmp",pos.x*GRIDSIZE, pos.y*GRIDSIZE, (pos.x*GRIDSIZE) + GRIDSIZE, (pos.y*GRIDSIZE) + GRIDSIZE);
//                DrawWall(levelMap[i][j].Wall,pos,level);
            }
            if(levelMap[i][j].Food!=0) //pengecekan jika kondisi isi array menunjukan food
            {
                Food(levelMap[i][j].Food,pos);
            }
        }
    }
}


//struktur data aray untuk level 1 berukuran 20x20 (by Pega)
int level1[20][20]= {
                    {15, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13,  32, 7,  7,  7,  7,  7,  7,  7, 13, 13,  7,  7,  7,  7,  7,  7,  7,  32, 13},
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
                    {13, 7,  7,  7,  7,   7, 2,  1,   1, 1, 1,  1,  1,  1,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 21,  7,  18, 7, 20,  12,12, 12, 12, 21,  7, 18,  7, 20, 14,  7, 13},
                    {13, 7, 13,  7,  7,  13, 7,  7,   7, 7,  7,  7,  7,  7, 13,  7,  7, 13,  7, 13},
                    {13, 7, 13,  7, 20,  16, 7, 18,   7,18, 18,  7, 18,  7, 17, 21,  7, 13,  7, 13},
                    {13, 7, 13,  7,  7,   7, 7, 13,   7,13, 13,  7, 13,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 17, 12, 21,   7,20, 16,   7,19, 19,  7, 17, 21,  7, 20, 12, 16,  7, 13},
                    {13, 32,  7,  7,  7,   7, 7,  7,   7, 7,  7,  7,  7,  7,  7,  7,  7,  7,  32, 13},
                    {17, 12, 12,12, 12,  12, 12, 12, 12, 12, 12, 12,12, 12, 12, 12, 12, 12, 12, 16}
                    };
//struktur data aray untuk level 2 berukuran 20x20 (by Pega)
int level2[20][20]= {
                    {15,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13, 32,  7,  7,  7, 18,  7,  7,  7, 15, 14,  7,  7,  7, 18,  7,  7,  7,  32, 13},
                    {13, 7, 20, 21,  7, 19,  7, 18,  7, 17, 16,  7, 18,  7, 19,  7, 20, 21,  7, 13},
                    {13, 7, 7,  7,  7,  7,  7, 13,  7,  7,  7,  7, 13,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 20, 12, 12, 21,  7, 17, 12, 12, 12, 12, 16,  7, 20, 12, 12, 21,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17,12, 12, 21,  7, 15, 12, 12, 21,  7,  7, 20, 12, 12, 14,  7, 20, 12, 12, 16},
                    {7 , 7,  7,  7,  7, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7,  7,  7,  7,  7},
                    {18, 7, 15, 14,  7, 13,  7, 15, 21, 22, 22, 20, 14,  7, 13,  7, 15, 14,  7, 18},
                    {13, 7, 17, 16,  7, 19,  7, 13,  1,  1,  1,  1, 13,  7, 19,  7, 17, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7, 13,  3,  1,  1,  1, 13,  7,  7,  7,  7,  7,  7, 13},
                    {19, 7, 20, 21,  7, 20, 21, 17, 12, 12, 12, 12, 16, 20, 21,  7, 20, 21,  7, 19},
                    {7 , 7,  7,  7,  7,  7,  7,  7,  2,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7},
                    {15,12, 12, 12, 21,  7, 20, 21,  7, 20, 21,  7, 20, 21,  7, 20, 12, 12, 12, 14},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 18,  7, 20, 12, 21,  7, 20, 14, 15, 21,  7, 20, 12, 21,  7, 18,  7, 13},
                    {13, 7, 13,  7,  7,  7,  7,  7,  7, 13, 13,  7,  7,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 17, 21,  7, 20, 12, 21,  7, 13, 13,  7, 20, 12, 21,  7, 20, 16,  7, 13},
                    {13, 32,  7,  7,  7,  7,  7,  7,  7, 19, 19,  7,  7,  7,  7,  7,  7,  7,  32, 13},
                    {17, 12, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 16}
                    };
//struktur data aray untuk level 2 berukuran 20x20 (by Pega)
 int level3[20][20]= {
                    {15,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14},
                    {13, 32,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  32, 13},
                    {13, 7, 15, 12, 21,  7, 20, 12, 12, 12, 12, 12, 12, 21,  7, 20, 12, 14,  7, 13},
                    {13, 7, 13,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 13,  7, 20, 14,  7, 20, 12, 12, 12, 12, 21,  7, 15, 21,  7, 13,  7, 13},
                    {13, 7, 13,  7,  7, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7,  7, 13,  7, 13},
                    {13, 7, 17, 21,  7, 19,  7, 20, 12, 12, 12, 12, 21,  7, 19,  7, 20, 16,  7, 13},
                    {13, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {17,12, 12, 12, 12, 21,  7, 15, 21, 22, 22, 20, 14,  7, 20, 12, 12, 12, 12, 16},
                    { 1, 1,  1,  1,  1,  1,  7, 13,  1,  1,  1,  1, 13,  7,  1,  1,  1,  1,  1,  1},
                    { 1, 1,  1,  1,  1,  1,  7, 13,  3,  1,  1,  1, 13,  7,  1,  1,  1,  1,  1,  1},
                    {15,12, 12, 12, 12, 21,  7, 17, 12, 12, 12, 12, 16,  7, 20, 12, 12, 12, 12, 14},
                    {13, 2,  7,  7,  7,  7,  7,  1,  1,  1,  1,  1,  1,  7,  7,  7,  7,  7,  7, 13},
                    {13, 7, 15, 21,  7, 18,  7, 20, 12, 12, 12, 12, 21,  7, 18,  7, 20, 14,  7, 13},
                    {13, 7, 13,  7,  7, 13,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7,  7, 13,  7, 13},
                    {13, 7, 13,  7, 20, 16,  7, 20, 12, 12, 12, 12, 21,  7, 17, 21,  7, 13,  7, 13},
                    {13, 7, 13,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13,  7, 13},
                    {13, 7, 17, 12, 21,  7, 20, 12, 12, 12, 12, 12, 12, 21,  7, 20, 12, 16,  7, 13},
                    {13, 32,  7, 7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 32, 13},
                    {17, 12, 12,12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 16}
                    };


int level4[20][20]= {
                    {15, 12, 12, 12, 12,  7, 12, 12, 12, 12, 12, 12, 12, 12,  7, 12, 12, 12, 12, 14},
                    {13, 15, 14, 32,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 32, 13},
                    {13, 17, 16,  7, 20, 14,  7, 20, 12, 12, 12, 12, 21,  7, 18,  7, 15, 21,  7, 13},
                    {13,  7,  7,  7,  7, 13,  7,  7,  7, 13, 13,  7,  7,  7, 13,  7, 19,  7,  7, 13},
                    {13,  7, 20, 21,  7, 13,  7, 18,  7, 13, 13,  7, 18,  7, 13, 21,  7,  7,  7, 13},
                    {13,  7,  7,  7,  7, 13,  7, 13,  7, 13, 13,  7, 13,  7, 13,  7, 18,  7,  7, 13},
                    {13, 18,  7, 20, 12, 16,  7, 19,  7, 19, 19,  7, 19,  7, 19,  7, 17, 21,  7, 13},
                    {13, 13,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 13},
                    {13, 17, 21,  7, 20, 12, 14, 15, 21, 22, 22, 20, 14, 15, 12, 21,  7, 20, 12, 13},
                    {13, 19,  7,  7,  7, 19, 13, 13,  1,  1,  1,  1, 13, 13, 19,  7,  7,  7,  7, 13},
                    {13,  7,  7, 18,  7,  7, 13, 13,  3,  1,  1,  1, 13, 13,  7,  7, 18,  7,  7, 13},
                    {13,  7, 20,  1, 21,  7, 19, 17, 12, 12, 12, 12, 16, 19,  7, 20,  1, 21,  7, 13},
                    {13,  7,  7, 19,  7,  7,  7,  7,  7,  2,  7,  7,  7,  7,  7,  7, 19,  7,  7, 13},
                    {13, 18,  7,  7,  7, 18,  7,  7, 15, 12, 12, 14,  7,  7, 18,  7,  7,  7, 18, 13},
                    {13, 31, 21,  7, 20,  1, 21,  7, 17, 14, 15, 16,  7, 20,  1, 21,  7, 20,  1, 13},
                    {13, 19,  7,  7,  7, 19,  7,  7,  7, 19, 19,  7,  7,  7, 19,  7,  7,  7, 19, 13},
                    {13,  7,  7, 18,  7,  7,  7, 18,  7,  7,  7,  7, 18,  7,  7,  7, 18,  7,  7, 13},
                    {13,  7, 20,  1, 21,  7, 20,  1, 21,  7,  7, 20,  1, 21,  7, 20, 1 , 21,  7, 13},
                    {13, 32,  7, 19,  7,  7,  7, 19,  7,  7,  7,  7, 19,  7,  7,  7, 19,  7, 32, 13},
                    {17, 12, 12, 12, 12,  7, 12, 12, 12, 12, 12, 12, 12, 12,  7, 12, 12, 12, 12, 16}
                    };

int level5[20][20]={
                    {18, 1,12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	1,	18},
                    {13, 32,	 7,	 7,	 7,	 7,	20,	21,	 7,	20,	21,	 7,	20,	21,	 7,	 7,	 7,	 7,	 32,	13},
                    {13, 7,	18,	 7,	18,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	18,	 7,	18,	 7,	13},
                    {13, 7,	17,	12,	16,	 7,	20,	21,	 7,	20,	21,	 7,	20,	21,	 7,	17,	12,	16,	 7,	13},
                    {13, 7,	19,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	19,	 7,	13},
                    {13, 7,	 7,	 7,	20,	12,	12,	14,	 7,	15,	14,	 7,	15,	12,	12,	21,	 7,	 7,	 7,	13},
                    {13,20,	12,	12,	14,	 7,	 7,	19,	 7,	17,	16,	 7,	19,	 7,	 7,	15,	12,	12,	21,	13},
                    {13, 7,	19,	 7,	17,	21,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	20,	16,	 7,	19,	 7,	13},
                    {13, 7,  7,  7,  7,  7,  7, 15, 21, 22, 22,	20,	14,	 7,	 7,	 7,	 7,	 7,	 7,	13},
                    {13,15,	14,	 7,	15,	14,	 7,	13,	 1,	 1,	 1,	 1,	13,	 7,	15,	14,	 7,	15,	14,	13},
                    {13,13,	19,	 7,	19,	13,	 7,	13,	 3,	 1,	 1,	 1,	13,	 7,	13,	19,	 7,	19,	13,	13},
                    {13,19,	 7,	 7,	 7,	13,	 7,	17,	12,	12,	12,	12,	16,	 7,	13,	 7,	 7,	 7,	19,	13},
                    {13, 7,	 7,	18,	 7,	13,	 7,	 7,	 2,	 7,	 7,	 7,	 7,	 7,	13,	 7,	18,	 7,	 7,	13},
                    {13, 7,	20,	16,	 7,	17,	14,	 7,	15,	14,	15,	14,	 7,	15,	16,	 7,	17,	21,	 7,	13},
                    {13, 7,	 7,	 7,	 7,	 7,	13,	 7,	19,	13,	13,	19,	 7,	13,	 7,	 7,	 7,	 7,	 7,	13},
                    {13,20,	12,	12,	21,	 7,	19,	 7,	 7,	13,	13,	 7,	 7,	19,	 7,	20,	12,	12,	21,	13},
                    {13, 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	13,	13,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	13},
                    {13, 7,	20,	12,	12,	21,	 7,	20,	12,	16,	17,	12,	21,	 7,	20,	12,	12,	21,	 7,	13},
                    {13, 32, 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 32,13},
                    {17,  1,12,	12,	12,	12,	12,	12,	12,	 12, 12,12,	12,	12,	12,	12,	12,	12,	 1,	16}
                    };


int level6[20][20]={
                  {20,	 7,	12,	12,	12,	12,	21,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	 7,	18},
                  {18,	 3,	18,	 7,	 7,	 7,	18,	 7,	 7,	 7,	 7,	 7,	 7,	18,	 7,	 7,	 7,	 7,	32, 13},
                  {18,	 32,13,	 7,	18,	 7,	13,	21,	 7,	20,	21,	 7,	20,	13,	 7,	20,	12,	12,	21,	13},
                  {13,	 7,	19,	 7,	19,	 7,	19,	 7,	 7,	 7,	 7,	 7,	 7,	19,	 7,	 7,	 7,	 7,	 7,	13},
                  {13,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	20,	12,	12,	12,	 7,	 7,	 7,	 7,	15,	21,	 7,	13},
                  {13,	20,	12,	21,	 7,	20,	21,	 7,	 7,	 7,	 7,	 7,	 7,	20,	21,	 7,	19,	 7,	 7,	13},
                  {13,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	20,	12,	12,	21,	 7,	 7,	 7,	 7,	 7,	18,	 7,	13},
                  {13,	 7,	20,	21,	 7,	18,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	18,	 7,	20,	16,	 7,	13},
                  {13,	 7,	 7,	 7,	 7,	13,	 7,	15,	21,	22,	22,	20,	14,	 7,	13,	 7,	 7,	 7,	 7,	13},
                  {13,	18,	 7,	15,	12,	16,	 7,	13,	 7,	 7,	 7,	 7,	13,	 7,	17,	12,	14,	 7,	18,	13},
                  {13,	19,	 7,	19,	 7,	 7,	 7,	13,	 3,	 7,	 7,	 7,	13,	 7,	 7,	 7,	19,	 7,	19,	13},
                  {13,	 7,	 7,	 7,	 7,	15,	21,	17,	12,	12,	12,	12,	16,	20,	14,	 7,	 7,	 7,	 7,	13},
                  {13,  20, 21,  7, 15, 16,  2,  7,  7,	 7,	 7,	 7,	 7,	 7,	17,	14,	 7,	20,	21,	13},
                  {13,	 7,	 7,	 7,	17,	14,	 7,	 7,	20,	14,	15,	21,	 7,	 7,	15,	16,	 7,	 7,	 7,	13},
                  {13,	 7,	18,	 7,	 7,	17,	14,	 7,	 7,	17,	16,	 7,	 7,	15,	16,	 7,	 7,	18,	 7,	13},
                  {13,	20,	12,	21,	 7,	 7,	17,	21,	 7,	 7,	 7,	 7,	20,	16,	 7,	 7,	20,	12,	21,	13},
                  {13,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	20,	21,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	13},
                  { 7,	 7,	15,	21,	 7,	20,	21,	 7,	 7,	 7,	 7,	 7,	 7,	20,	21,	 7,	20,	14,	 7,	 7},
                  {13,	 32,19,	 7,	 7,	 7,	 7,	 7,	20,	12,	12,	21,	 7,	 7,	 7,	 7,	 7,	19,	32, 13},
                  {19,	 7,	20,	12,	12,	12,	12,	 12,12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	 7,	21}
};

int level7[20][20]={
                    {15,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	14},
                    {13,	 32,	 7,	 7,	 7,	 7,	 7,	 1,	 1,	 1,	 1,	 1,	 1,	 7,	 7,	 7,	 7,	 7,	 32,	13},
                    {13,	 7,	15,	12,	12,	21,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	20,	12,	12,	14,	 7,	13},
                    {13,	 7,	13,	 7,	 7,	 7,	 7,	 7,	 1,	 1,	 1,	 1,	 7,	 7,	 7,	 7,	 7,	13,	 7,	13},
                    {13,	 7,	13,	 7,	 1,	 7,	 7,	 7,	20,	12,	12,	21,	 7,	 7,	 7,	 1,	 7,	13,	 7,	13},
                    {13,	 7,	19,	 7,	 1,	 7,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 7,	 1,	 7,	19,	 7,	13},
                    {13,	 7,	 7,	 7,	 1,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 1,	 7,	 7,	 7,	13},
                    {13,	 1,	 7,	 7,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 7,	 7,	 1,	13},
                    {13,	 1,	 7,	 7,	 1,	18,	 1,	15,	21,	22,	22,	20,	14,	 1,	18,	 1,	 7,	 7,	 1,	13},
                    {13,	 1,	 7,	 7,	 1,	13,	 1,	13,	 1,	 1,	 1,	 1,	13,	 1,	13,	 1,	 7,	 7,	 1,	13},
                    {13,	 1,	 7,	 7,	 1,	13,	 1,	13,	 1,	 3,	 1,	 1,	13,	 1,	13,	 1,	 7,	 7,	 1,	13},
                    {13,	 1,	 7,	 7,	 1,	19,	 1,	17,	12,	12,	12,	12,	16,	 1,	19,	 1,	 7,	 7,	 1,	13},
                    {13,	 1,	 7,	 7,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 1,	 7,	 7,	 1,	13},
                    {13,	 7,	 7,	 7,	 1,	 1,	 1,	 7,	 7,	 7,	 7,	 7,	 7,	 1,	 1,	 1,	 7,	 7,	 7,	13},
                    {13,	 7,	18,	 7,	 1,	 1,	 1,	 7,	 1,	 1,	 1,	 1,	 7,	 1,	 1,	 1,	 7,	18,	 7,	13},
                    {13,	 7,	13,	 7,	 1,	 1,	 1,	 7,	20,	12,	12,	21,	 7,	 1,	 1,	 1,	 7,	13,	 7,	13},
                    {13,	 7,	13,	 2,	 7,	 7,	 7,	 7,	 7,	 1,	 1,	 7,	 7,	 7,	 7,	 7,	 7,	13,	 7,	13},
                    {13,	 7,	17,	12,	12,	21,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	 7,	20,	12,	12,	16,	 7,	13},
                    {13,	 32,	 7,	 7,	 7,	 7,	 7,	 1,	 1,	 1,	 1,	 1,	 1,	 7,	 7,	 7,	 7,	 7,	 32,	13},
                    {17,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	12,	16}
};

int findPath(int posX, int posY, int direction) {
    if ((levelMap[posX][posY].Wall!=0 && levelMap[posX][posY].Wall!=22) || posX>19 || posY>19 ||posX<0 || posY<0) {
        return -1;
    }
    else if (levelMap[posX][posY].node!=-1) {
        return levelMap[posX][posY].node;
    }
    else {
        if (direction==LEFT) {
            return findPath(--posX, posY, LEFT);
        }
        else if(direction==RIGHT){
            return findPath(++posX, posY, RIGHT);
        }
        else if (direction==UP) {
            return findPath(posX, --posY, UP);
        }
        else if (direction==DOWN) {
            return findPath(posX, ++posY, DOWN);
        }
    }
}
int *graph;
int *nodePos;
void autoPath() {
    graph = (int * ) malloc(nodeCount * nodeCount * sizeof(int));
    memset(graph, 0, sizeof(graph));
    int i, j, path, k;
    for(i=0;i<20;i++) {
        for(j=0;j<20;j++) {
            if(levelMap[j][i].node!=-1 && (levelMap[j][i].Wall==0 || levelMap[j][i].Wall==22)) {
                for(k=1;k<=4;k++) {
                    switch(k) {
                        case LEFT : path = findPath(j-1, i, k);break;
                        case RIGHT : path = findPath(j+1, i, k);break;
                        case UP : path = findPath(j, i-1, k);break;
                        case DOWN : path = findPath(j, i+1, k);break;
                    }
                    if(path!=-1) {
                        graph[nodeCount * levelMap[j][i].node + path] = 1;
//                        printf("%d berhubungan dengan %d, %d = %d\n", levelMap[j][i].node, path, nodeCount * levelMap[j][i].node + path, graph[nodeCount * levelMap[j][i].node + path]);
                    }
                }
            }
        }
    }
}
void autoNodePos() {
    nodePos = (int * ) malloc(nodeCount * 2 * sizeof(int));
    memset(nodePos, 0, sizeof(nodePos));
    int i, j, path, k=0;
    for(i=0;i<20;i++) {
        for(j=0;j<20;j++) {
            if (levelMap[j][i].node!=-1) {
                nodePos[k*2+0] = j;
                nodePos[k*2+1] = i;
                k++;
            }
        }
    }
}
void generateNodes() {
    int i, j, c;
    nodeCount = 0;
    for(j=1;j<20;j++) {
        for(i=1;i<20;i++) {
            c = 0;
            if ((levelMap[i+1][j].Wall==0 || levelMap[i+1][j].Wall==22) && (levelMap[i][j+1].Wall==0 || levelMap[i][j+1].Wall==22)) {
                c++;
            }
            if ((levelMap[i+1][j].Wall==0 || levelMap[i+1][j].Wall==22) && (levelMap[i][j-1].Wall==0 || levelMap[i][j-1].Wall==22)) {
                c++;
            }
            if ((levelMap[i-1][j].Wall==0 || levelMap[i-1][j].Wall==22) && (levelMap[i][j+1].Wall==0 || levelMap[i][j+1].Wall==22)) {
                c++;
            }
            if ((levelMap[i-1][j].Wall==0 || levelMap[i-1][j].Wall==22) && (levelMap[i][j-1].Wall==0 || levelMap[i][j-1].Wall==22)) {
                c++;
            }
            if (c>0 && (levelMap[i][j].Wall==0 || levelMap[i][j].Wall==22)) {
                levelMap[i][j].node = nodeCount++;
            }
        }
    }
}

//Prosedure untuk membuat map dengan parameter
void CreateMap(int maps[20][20], playerControl *player)//Pega Kurniawan
{
    position pos;
    int i, j;
    player->foodCount = 0;
    for (i=0;i<20;i++) {
        for(j=0;j<20;j++) {
            pos.x = i;
            pos.y = j;
            // Kondisi pengecekan untuk setiap jenis wall
            levelMap[j][i].node = -1;
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
            else if (maps[j][i]== POWER_UP){ //Haya Utami
                levelMap[i][j].Food=POWER_UP;
                player->foodCount++;
            }
            else{
                levelMap[i][j].Food=EMPTY;
            }
        }
    }
}
