#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#define GRIDSIZE 30
#define EMPTY 1
#define PACMAN 2
#define GHOST1 4
#define GHOST2 8
#define GHOST3 16
#define GHOST4 32
#define FOOD1 64
#define FOOD2 128
#define FOOD3 256
#define FOOD4 512
#define FOOD5 0
#define WALL_HOR 1024
#define WALL_VER 2048
#define WALL_COR_UPRIGHT 4096
#define WALL_COR_UPLEFT 8192
#define WALL_COR_UNDERRIGHT 16348
#define WALL_COR_UNDERLEFT 32768

#define RPACMAN 1
#define RGHOST1 2
#define RGHOST2 4
#define RGHOST3 8
#define RGHOST4 16
#define RFOOD1 1
#define RFOOD2 2
#define RFOOD3 4
#define RFOOD4 8
#define RFOOD5 16
#define RWALL_HOR 1
#define RWALL_VER 2
#define RWALL_COR_UPRIGHT 4
#define RWALL_COR_UPLEFT 8
#define RWALL_COR_UNDERRIGHT 16
#define RWALL_COR_UNDERLEFT 32

typedef struct{
    int Object;
    int Wall;
    int Food;
} MapController;

MapController levelMap[20][20];

void CreateMap(int maps);

int IsWall_Ver(int);
int IsWall_Hor(int);
int IsWall_Cor_UnderLeft(int);
int IsWall_Cor_UnderLeft(int);
int IsWall_Cor_UpLeft(int);
int IsWall_Cor_UpRight(int);
int IsPacman(int x);
int IsFood1(int x);
int IsFood2(int x);
int IsFood3(int x);
int IsFood4(int x);
int IsGhost1(int x);
int IsGhost2(int x);
int IsGhost3(int x);
int IsGhost4(int x);
void DrawMap();
void CreateMap(int maps[20][20])
#endif // MAP_H_INCLUDED
