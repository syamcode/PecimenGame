#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#define GRIDSIZE 30
#define EMPTY 0
#define PACMAN 2
#define KUNTILANAK 3
#define POCONG 4
#define TENGKORAK 5
#define TUYUL 6
#define FOOD1 7
#define FOOD2 8
#define FOOD3 9
#define FOOD4 10
#define FOOD5 11
#define WALL_HOR 12
#define WALL_VER 13
#define WALL_COR_UPRIGHT 14
#define WALL_COR_UPLEFT 15
#define WALL_COR_UNDERRIGHT 16
#define WALL_COR_UNDERLEFT 17
#define WALL_LIMIT_UP 18
#define WALL_LIMIT_DOWN 19
#define WALL_LIMIT_LEFT 20
#define WALL_LIMIT_RIGHT 21
#define WALL_GHOST 22


typedef struct{
    int Object;
    int Wall;
    int Food;
} MapController;

MapController levelMap[20][20];
//void CreateMap(int maps);
void DrawMap();
void CreateMap(int maps[20][20], pacmanController *peciman);

#endif // MAP_H_INCLUDED
