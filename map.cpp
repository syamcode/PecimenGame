#include <stdio.h>
#include <graphics.h>
#include "includes/map.h"


int IsWall_Hor(int x) {
    return x & WALL_HOR;
}
int IsWall_Ver(int x) {
    return x & WALL_VER;
}
int IsWall_Cor_UpRight(int x) {
    return x & WALL_COR_UPRIGHT;
}
int IsWall_Cor_UpLeft(int x) {
    return x & WALL_COR_UPLEFT;
}
int IsWall_Cor_UnderRight (int x) {
    return x & WALL_COR_UNDERRIGHT;
}
int IsWall_Cor_UnderLeft(int x) {
    return x & WALL_COR_UNDERLEFT;
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
        case RWALL_HOR : readimagefile("assets/images/WallLeft.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_VER : readimagefile("assets/images/Wall.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UNDERLEFT : readimagefile("assets/images/Wall2.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UNDERRIGHT : readimagefile("assets/images/Wall3.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UPLEFT : readimagefile("assets/images/PacmanUpOpen.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UPRIGHT : readimagefile("assets/images/Tengkorak.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
    }
}
void DrawFood(int wall,int posX, int posY) { // masih contoh, yang dibawah belum asli
    switch(wall){
        case RWALL_HOR : readimagefile("assets/images/Wall.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_VER : readimagefile("assets/images/wallLeft.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
        case RWALL_COR_UNDERLEFT : readimagefile("assets/images/Wall2.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
        break;
    }
}
void DrawObject(int wall,int posX, int posY) { // masih contoh, yang dibawah belum asli
//    switch(wall){
//        case RWALL_HOR : readimagefile("assets/images/Wall3.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
//        break;
//        case RWALL_VER : readimagefile("assets/images/wall.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
//        break;
//        case RWALL_COR_UNDERLEFT : readimagefile("assets/images/Wall2.bmp",posX, posY, posX + GRIDSIZE, posY + GRIDSIZE);
//        break;
//    }
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
                    {8192, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 4096},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {1024, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1024},
                    {32768, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048, 2048,32768}
                    };



void CreateMap(int maps[20][20])
{
       int i, j;
    for (i=0;i<20;i++) {
        for(j=0;j<20;j++) {

            if (IsWall_Hor(maps[j][i])) {
                levelMap[j][i].Wall=RWALL_HOR;
            }else if (IsWall_Ver(maps[j][i])) {
                levelMap[j][i].Wall=2;
            }else if (IsWall_Cor_UnderLeft(maps[j][i])) {
                levelMap[j][i].Wall=32;
            } else if (IsWall_Cor_UnderRight(maps[j][i])) {
                levelMap[j][i].Wall=16;
            }else if (IsWall_Cor_UpLeft(maps[j][i])) {
                levelMap[j][i].Wall=8;
            }else if (IsWall_Cor_UpRight(maps[j][i])) {
                levelMap[j][i].Wall=4;
            }
            else {
                    levelMap[j][i].Wall=0;
            }
            if (IsGhost1(maps[j][i])) {
                levelMap[j][i].Object=2;
            }else if (IsGhost2(maps[j][i])) {
                levelMap[j][i].Object=4;
            }else if (IsGhost3(maps[j][i])) {
                levelMap[j][i].Object=8;
            }else if (IsGhost4(maps[j][i])) {
                levelMap[j][i].Object=16;
            }else if (IsPacman(maps[j][i])) {
                levelMap[j][i].Object=1;
            }else{
                  levelMap[j][i].Object=0;
            }
            if (IsFood1(maps[j][i])) {
                levelMap[j][i].Food=1;
            }else if (IsFood2(maps[j][i])) {
                levelMap[j][i].Food=2;
            }else if (IsFood3(maps[j][i])) {
                levelMap[j][i].Food=4;
            }else if (IsFood4(maps[j][i])) {
                levelMap[j][i].Food=8;
            }else if (IsFood5(maps[j][i])) {
                levelMap[j][i].Food=16;
            }else{
              levelMap[j][i].Food=0;
            }
        }
    }
}

