#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#define GRIDSIZE 30
#define EMPTY 1
#define WALL 2
#define PACMAN 4
#define GHOST1 8
#define GHOST2 16
#define GHOST3 32
#define GHOST4 64
#define FOOD1 128
#define FOOD2 256
#define FOOD3 512
#define FOOD4 1024

typedef struct{
    int Object;
    int Wall;
    int Food;
} MapController;

//MapController levelMap[20][20];

void CreateMap(int maps);

int IsWall(int x);
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

#endif // MAP_H_INCLUDED
