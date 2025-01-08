#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void drawTriangle(int xl, int yl, int x2, int y2, int x3, int y3) {
    line(xl, yl, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, xl, yl);
}

void boundaryFill8(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill8(x + 1, y, fillColor, boundaryColor);
        boundaryFill8(x - 1, y, fillColor, boundaryColor);
        boundaryFill8(x, y + 1, fillColor, boundaryColor);
        boundaryFill8(x, y - 1, fillColor, boundaryColor);
        boundaryFill8(x + 1, y + 1, fillColor, boundaryColor);
        boundaryFill8(x - 1, y - 1, fillColor, boundaryColor);
        boundaryFill8(x - 1, y + 1, fillColor, boundaryColor);
        boundaryFill8(x + 1, y - 1, fillColor, boundaryColor);
    }
}

int main() {
    int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);
    

    int xl = 200, yl = 200;
    int x2 = 300, y2 = 200;
    int x3 = 250, y3 = 300;

    drawTriangle(xl, yl, x2, y2, x3, y3);

    int fillColor = RED;
    int boundaryColor = WHITE;

    boundaryFill8((xl + x2 + x3) / 3, (yl + y2 + y3) / 3, fillColor, boundaryColor);

    getch();
    closegraph();

    return 0;
}
