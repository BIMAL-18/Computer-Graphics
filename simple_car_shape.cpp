#include <graphics.h>
#include <stdio.h>

void drawCar() {
    // Car body
    setcolor(BLUE);
    rectangle(150, 300, 450, 400); // Car body (rectangle)
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(151, 301, BLUE); // Fill the car body

    // Car roof
    setcolor(GREEN);
    line(200, 300, 400, 300);    // Top line of the roof
    line(200, 300, 250, 250);    // Left diagonal of the roof
    line(400, 300, 350, 250);    // Right diagonal of the roof
    line(250, 250, 350, 250);    // Top horizontal line of the roof
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(251, 251, GREEN);  // Fill the roof

    // Front wheel
    setcolor(BLACK);
    circle(200, 420, 20); // Front wheel (circle)
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(200, 420, BLACK); // Fill the front wheel

    // Rear wheel
    circle(400, 420, 20); // Rear wheel (circle)
    floodfill(400, 420, BLACK); // Fill the rear wheel
}

int main() {
     int gd = DETECT, gm;
    char driver[] = "";  
    initgraph(&gd, &gm, driver);

    drawCar(); // Call the function to draw the car

    getch(); // Wait for user input
    closegraph(); // Close graphics mode
    return 0;
}