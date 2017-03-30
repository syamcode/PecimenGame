#ifndef INETERFACES_H_INCLUDED
#define INETERFACES_H_INCLUDED
//layar 800 x 600
#define MAX_INPUT_LEN 15
#define panjang 600

POINT cursorPosition;
int mX, mY;
DWORD screenWidth = GetSystemMetrics ( SM_CXSCREEN);
DWORD screenHeight = GetSystemMetrics (SM_CYSCREEN);

int kursor(int option, int x, int y);
void tampilan();
void tampilan2();
void menuutama();
void storymode();
void versusmode();
void menuplay();
void menuscore();
void howtoplay();
void aboutus();
void inputnama(playerControl *player);

#endif
