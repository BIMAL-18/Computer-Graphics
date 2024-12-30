#include <stdio.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int r) {
    int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);
    
    int x = 0;
    int y = r;
    int p = 1 - r;  // Initial decision parameter
    
    // Plot initial points in all octants
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc - y, yc - x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    
    while (x < y) {
        x++;
        
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        
        // Plot points in all octants
        putpixel(xc + x, yc + y, WHITE);  // Octant 1
        putpixel(xc + y, yc + x, WHITE);  // Octant 2
        putpixel(xc - y, yc + x, WHITE);  // Octant 3
        putpixel(xc - x, yc + y, WHITE);  // Octant 4
        putpixel(xc - x, yc - y, WHITE);  // Octant 5
        putpixel(xc - y, yc - x, WHITE);  // Octant 6
        putpixel(xc + y, yc - x, WHITE);  // Octant 7
        putpixel(xc + x, yc - y, WHITE);  // Octant 8
    }
    
    getch();
    closegraph();
}

int main() {
    int xc, yc, r;
    
    printf("Enter the center coordinates (xc, yc) and radius (r) of the circle:\n");
    printf("xc: ");
    scanf("%d", &xc);
    printf("yc: ");
    scanf("%d", &yc);
    printf("Radius (r): ");
    scanf("%d", &r);
    
    drawCircle(xc, yc, r);
    return 0;
}