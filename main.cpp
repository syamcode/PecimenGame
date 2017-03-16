#include <stdio.h>
#include <graphics.h>
#include "includes/peciman.h"

int main()
{
    initwindow(800, 600, "Pecimen Game");
    pacmanController peciman;

    peciman.direction = getch();
    printf("%d",peciman.direction);
    cleardevice();
    drawPacman(peciman);

    getch();
    return 0;
}
