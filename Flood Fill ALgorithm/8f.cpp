#include <stdio.h>
#include <graphics.h>

void floodFill8(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        floodFill8(x + 1, y, fillColor, boundaryColor);
        floodFill8(x - 1, y, fillColor, boundaryColor);
        floodFill8(x, y + 1, fillColor, boundaryColor);
        floodFill8(x, y - 1, fillColor, boundaryColor);
        floodFill8(x + 1, y + 1, fillColor, boundaryColor);
        floodFill8(x - 1, y - 1, fillColor, boundaryColor);
        floodFill8(x - 1, y + 1, fillColor, boundaryColor);
        floodFill8(x + 1, y - 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);

    int x1 = 150, yl = 100;
    int x2 = 200, y2 = 100;
    int x3 = 225, y3 = 150;
    int x4 = 200, y4 = 200;
    int x5 = 150, y5 = 200;
    int x6 = 125, y6 = 150;

    line(x1, yl, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x5, y5);
    line(x5, y5, x6, y6);
    line(x6, y6, x1, yl);

    int fillColor = RED;
    int boundaryColor = WHITE;

    floodFill8((x1 + x2 + x3 + x4 + x5 + x6) / 6, (yl + y2 + y3 + y4 + y5 + y6) / 6, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}
