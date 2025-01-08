#include <stdio.h>
#include <graphics.h>

void floodFill4(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        floodFill4(x + 1, y, fillColor, boundaryColor); // right
        floodFill4(x - 1, y, fillColor, boundaryColor); // left
        floodFill4(x, y + 1, fillColor, boundaryColor); // down
        floodFill4(x, y - 1, fillColor, boundaryColor); // up
    }
}

int main() {
    int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);
    
    
    int xl = 100, yl = 150;
    int x2 = 180, y2 = 120;
    int x3 = 260, y3 = 150;
    int x4 = 260, y4 = 230;
    int x5 = 180, y5 = 260;
    int x6 = 100, y6 = 230;

    line(xl, yl, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x5, y5);
    line(x5, y5, x6, y6);
    line(x6, y6, xl, yl);

    int fillColor = YELLOW;  // Changed fill color to YELLOW
    int boundaryColor = BLACK;  // Changed boundary color to BLACK

    floodFill4((xl + x2 + x3 + x4 + x5 + x6) / 6, (yl + y2 + y3 + y4 + y5 + y6) / 6, fillColor, boundaryColor);

    getch();
    closegraph();

    return 0;
}
