#ifndef INETERFACES_H_INCLUDED
#define INETERFACES_H_INCLUDED
//layar 800 x 600
#define MAX_INPUT_LEN 15
#define panjang 600

POINT cursorPosition;
int mX, mY;
DWORD screenWidth = GetSystemMetrics ( SM_CXSCREEN);
DWORD screenHeight = GetSystemMetrics (SM_CYSCREEN);

void DrawSideMenu(); //Haya Utami
void tampilan();//Auliya Aqma
void tampilan2();//Auliya Aqma
void menuutama();//Auliya Aqma
void storymode();//Auliya Aqma
void versusmode();//Auliya Aqma
void menuplay();//Auliya Aqma
void menuscore();//Auliya Aqma
void howtoplay();//Auliya Aqma
void aboutus();//Haya Utami
void inputnama(playerControl *player);//Haya Utami
void drawNumber(int x, int posX, int posY, int posisi);//Fahmi Rosdiansyah
void printScore(int score, int posX, int posY);//Fahmi Rosdiansyah
void printLives(int lives, int posX, int posY);//Fahmi Rosdiansyah

#endif
