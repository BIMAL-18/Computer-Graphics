#include <stdio.h>
#include <graphics.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);
    
    int x = 0, y = ry;
    int rx2 = rx * rx;
    int ry2 = ry * ry;
    int twoRx2 = 2 * rx2;
    int twoRy2 = 2 * ry2;
    int p, px, py;

    // Region 1
    p = ry2 - rx2 * ry + 0.25 * rx2;
    px = 0;
    py = twoRx2 * y;
    
    while (px < py) {
        x++;
        px += twoRy2;
        if (p < 0) {
            p += ry2 + px;
        } else {
            y--;
            py -= twoRx2;
            p += ry2 + px - py;
        }
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }

    // Region 2
    p = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;
    while (y > 0) {
        y--;
        py -= twoRx2;
        if (p > 0) {
            p += rx2 - py;
        } else {
            x++;
            px += twoRy2;
            p += rx2 - py + px;
        }
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
    }
    
    getch();
    closegraph();
}

int main() {
    int xc, yc, rx, ry;
    
    printf("Enter center coordinates (xc, yc) and radii (rx, ry) for ellipse drawing:\n");
    printf("xc: ");
    scanf("%d", &xc);
    printf("yc: ");
    scanf("%d", &yc);
    printf("rx: ");
    scanf("%d", &rx);
    printf("ry: ");
    scanf("%d", &ry);
    
    drawEllipse(xc, yc, rx, ry);
    return 0;
}