#include <stdio.h>
#include <graphics.h>

void drawTriangle(int xl, int yl, int x2, int y2, int x3, int y3) {
    line(xl, yl, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, xl, yl);
}

void boundaryFill8(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        boundaryFill8(x + 1, y, fillColor, boundaryColor); // right
        boundaryFill8(x - 1, y, fillColor, boundaryColor); // left
        boundaryFill8(x, y + 1, fillColor, boundaryColor); // down
        boundaryFill8(x, y - 1, fillColor, boundaryColor); // up
        boundaryFill8(x + 1, y + 1, fillColor, boundaryColor); // down-right
        boundaryFill8(x - 1, y - 1, fillColor, boundaryColor); // up-left
        boundaryFill8(x - 1, y + 1, fillColor, boundaryColor); // down-left
        boundaryFill8(x + 1, y - 1, fillColor, boundaryColor); // up-right
    }
}

int main() {
    int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);

    int xl = 100, yl = 100;
    int x2 = 200, y2 = 100;
    int x3 = 150, y3 = 200;

    drawTriangle(xl, yl, x2, y2, x3, y3);

    int fillColor = RED;
    int boundaryColor = WHITE;

    boundaryFill8((xl + x2 + x3) / 3, (yl + y2 + y3) / 3, fillColor, boundaryColor);

    getch();
    closegraph();

    return 0;
}
