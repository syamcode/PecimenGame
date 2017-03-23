void DrawGhost(ghostController ghost) {
    int posX = ghost.posX * GRIDSIZE;
    int posY = ghost.posY * GRIDSIZE;
    switch(ghost.ghostType) {
        case TUYUL : readimagefile("assets/images/Ghost4.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case TENGKORAK : readimagefile("assets/images/Ghost3.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case KUNTILANAK : readimagefile("assets/images/Ghost1.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
        case POCONG : readimagefile("assets/images/Ghost2.bmp", posX, posY, posX+GRIDSIZE, posY+GRIDSIZE);break;
    }
}
