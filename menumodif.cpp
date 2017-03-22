#include <stdio.h>
#include <graphics.h>
#include <windows.h>

//layar 800 x 600
int kursor(int option, int x, int y)
{
	int select=1, p=325, q=375;
	int input;
	readimagefile("picture/pacman1.bmp",x, y, p, q); //menampilkan lambang kursor
	do
	{
		input=getch();
		if(input==80) //80 kode ASCII kursor bawah
		{
			readimagefile("picture/black.bmp",x, y, p, q);
			y=y+25;
			q=q+25;
			select++;
			if(select>option)
			{
				y=y-(25*option);
				q=q-(25*option);
				select=1;
			}
			readimagefile("picture/pacman1.bmp",x, y, p, q);
		}
		if(input==72) //72 kode ASCII kursor atas
		{
			readimagefile("picture/black.bmp",x, y, p, q);
			y=y-25;
			q=q-25;
			select--;
			if (select<1)
			{
				y=y+(25*option);
				q=q+(25*option);
				select=option;
			}
			readimagefile("picture/pacman1.bmp",x, y, p, q);
		}
	}
	while(input!=13);
	return select;
}

void tampilan()
{
    //setbkcolor(2);
    setfillstyle(SOLID_FILL, 10);
    readimagefile("picture/pecimen.bmp",100, 10 , 700, 210);
    readimagefile("picture/pacman.bmp",50, 250, 300, 550);
}
void player1()
{  cleardevice();
    tampilan();
    outtextxy(475,300,"1 player ");
}
void player2()
{  cleardevice();
    tampilan();
    outtextxy(475,300,"2 player ");
}
void menuplay()
{   cleardevice();
    tampilan();
    //cleardevice();
    setcolor(15);
    settextstyle(9,HORIZ_DIR,3);
    outtextxy(400,300, "PLAYER");
    settextstyle(8,HORIZ_DIR,2);
    setcolor(9);
    outtextxy(400,350, "1 PLAYER");
    outtextxy(400,375, "2 PLAYER");
    setcolor(4);
    outtextxy(400,400, "BACK TO MENU");
    setcolor(15);
    int player = kursor(3,350,350);
    switch(player) //kursor di 4 posisi, x=50, y=32
{
	case 1 : player1();break;
	case 2 : player2();break;
    //case 3 : content();break;
	}
}

void menuscore()
{   cleardevice();
    tampilan();
    outtextxy(400,300,"score: ");

}

void howtoplay()
{    cleardevice();tampilan();
    outtextxy(400,300," how to play : ");

}

void aboutus()
{   cleardevice();tampilan();
    outtextxy(400,300," about us : ");


}
void content()

{   cleardevice();
    tampilan();
    setcolor(15);
    settextstyle(9,HORIZ_DIR,2);
    outtextxy(400,300, "MENU");
    settextstyle(8,HORIZ_DIR,1);
    setcolor(9);
    outtextxy(400,350, "PLAY");
    outtextxy(400,375, "SCORE");
    outtextxy(400,400, "HOW TO PLAY");
    outtextxy(400,425, "ABOUT US");
    setcolor(4);
    outtextxy(400,450, "EXIT");
    setcolor(15);
    int menu = kursor(5,350,350);
    switch(menu) //kursor di 5 posisi, x=50, y=32
{
	case 1 : menuplay();break;
	case 2 : menuscore ();break;
	case 3 : howtoplay(); break;
	case 4 : aboutus();break;
	case 5 : exit;
	}
}

int main()
{
int gd=DETECT, gm;
initwindow(800,600);
content();
//play(left, top);
getch();
closegraph();
return 0;
}
