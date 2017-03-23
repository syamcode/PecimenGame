#include <stdio.h>
#include <graphics.h>
#include <windows.h>
#define MAX_INPUT_LEN 15

//typedef struct{
	//char *name;
	//int score;
	//int lives;
//}playerControl;

void inputnama();

//playerControl player1.name;

int main(){
    int gd = DETECT, gm;
    initwindow(800, 600);
    //printf("%d\n",getmaxx());
    //printf("%d",getmaxy());
    inputnama();
    getch();
    closegraph();
    return(0);
}

void inputnama() {
    char inputbuf[MAX_INPUT_LEN];
    for(int idx=0;idx<MAX_INPUT_LEN;idx++)
        inputbuf[idx]=0;
    int input_pos = 0;
    int the_end=0;
    char c;
    do
    {
       cleardevice();
       readimagefile("picture/pecimen.bmp",100,10,700,160);
       rectangle(100,250,700,400);
       settextstyle(3, HORIZ_DIR,4);
       outtextxy(280,260,"Nama Player:");
       outtextxy (280, 300, inputbuf);
       c = getch();
       switch (c)
       {
            case 8: /* backspace */
              if (input_pos)
              {
                 input_pos--;
                 inputbuf[input_pos] = 0;
              }
              break;
            case 13: /* return */
              the_end = 1;
              break;
            case 27: /* Escape = Abort */
              inputbuf[0] = 0;
              the_end = 1;
              break;
            default:
              if (input_pos < MAX_INPUT_LEN-1 && c >= ' ' && c <= '~')
              {
                 inputbuf[input_pos] = c;
                 input_pos++;
                 inputbuf[input_pos] = 0;
              }
       }

    } while (!the_end);
    //getchar(playerControl player1.name);
}
