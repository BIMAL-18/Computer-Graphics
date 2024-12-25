#include <stdio.h>
#include <math.h>

void ddaLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    float x_increment = (float) dx / steps;
    float y_increment = (float) dy / steps;
    float x = x1;
    float y = y1;

    char grid[25][25];
    int i, j;

    // Initialize grid with dots
    for (i = 0; i < 25; i++) {
        for (j = 0; j < 25; j++) {
            grid[i][j] = '.';
        }
    }

    printf("\nPlotting points:\n");
    int k;
    for (k = 0; k <= steps; k++) {
        int rounded_x = (int) round(x);
        int rounded_y = (int) round(y);
        int plot_x = rounded_x;
        int plot_y = 25 - 1 - rounded_y;  // Invert y coordinate for display
        
        if (plot_x >= 0 && plot_x < 25 && plot_y >= 0 && plot_y < 25) {
            grid[plot_y][plot_x] = '*';
            printf("(%d, %d) ", rounded_x, rounded_y);
        }
        
        x += x_increment;
        y += y_increment;
    }

    printf("\n\n");
    printf("Line representation:\n");
    
    // Print the grid with dots and line
    for (i = 0; i < 25; i++) {
        for (j = 0; j < 25; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int x1, y1, x2, y2;

    printf("Enter coordinates (x1, y1) and (x2, y2) for line drawing:\n");
    printf("(x1,y1) \n");
    scanf("%d%d", &x1, &y1);
    printf("(x2, y2) \n");
    scanf("%d%d", &x2, &y2);

    ddaLine(x1, y1, x2, y2);
    return 0;
}