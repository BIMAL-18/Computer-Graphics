#include <graphics.h>
#include <stdio.h>

void scanlinePolygonFill(int polygon[][2], int n) {
    int y, x, i, j;
    int x_intersect[20];
    int gd = DETECT, gm;
    char driver[] = "";

    initgraph(&gd, &gm, driver);

    for (y = 0; y < getmaxy(); y++) {
        int k = 0;

        for (i = 0; i < n; i++) {
            int x1 = polygon[i][0], y1 = polygon[i][1];
            int x2 = polygon[(i + 1) % n][0], y2 = polygon[(i + 1) % n][1];

            if ((y1 <= y && y2 > y) || (y1 > y && y2 <= y)) {
                x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
                x_intersect[k++] = x;
            }
        }

        for (i = 0; i < k - 1; i++) {
            for (j = i + 1; j < k; j++) {
                if (x_intersect[i] > x_intersect[j]) {
                    int temp = x_intersect[i];
                    x_intersect[i] = x_intersect[j];
                    x_intersect[j] = temp;
                }
            }
        }

        for (i = 0; i < k; i += 2) {
            if (i + 1 < k) {
                for (x = x_intersect[i]; x <= x_intersect[i + 1]; x++) {
                    putpixel(x, y, WHITE);
                }
            }
        }
    }

    getch();
    closegraph();
}

int main() {
    int n, i;

    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &n);

    int polygon[n][2];

    for (i = 0; i < n; i++) {
        printf("Enter x and y coordinates of vertex %d: ", i + 1);
        scanf("%d %d", &polygon[i][0], &polygon[i][1]);
    }

    scanlinePolygonFill(polygon, n);

    return 0;
}
