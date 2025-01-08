#include <graphics.h>
#include <stdio.h>

void drawCar() {

    setcolor(BLUE);
    rectangle(150, 300, 450, 400); 
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(151, 301, BLUE); 

   
    setcolor(GREEN);
    line(200, 300, 400, 300);    
    line(200, 300, 250, 250);   
    line(400, 300, 350, 250);   
    line(250, 250, 350, 250);   
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(251, 251, GREEN); 

    setcolor(BLACK);
    circle(200, 420, 20);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(200, 420, BLACK);

   
    circle(400, 420, 20);
    floodfill(400, 420, BLACK); 
}

int main() {
     int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);

    drawCar(); 

    getch();
    closegraph(); 
    return 0;
}
