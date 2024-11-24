#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

using namespace std;

void drawCar(int x, int y) {
    // Car body
    setfillstyle(SOLID_FILL, RED);
    rectangle(x, y, x + 150, y + 50); // Body
    floodfill(x + 1, y + 1, WHITE);

    // Car roof
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(x + 20, y - 30, x + 130, y); // Roof
    floodfill(x + 21, y - 29, WHITE);

    // Wheels
    setfillstyle(SOLID_FILL, BLACK);
    circle(x + 30, y + 60, 15); // Front wheel
    floodfill(x + 31, y + 61, WHITE);
    circle(x + 120, y + 60, 15); // Rear wheel
    floodfill(x + 121, y + 61, WHITE);

    // Headlights
    setfillstyle(SOLID_FILL, YELLOW);
    rectangle(x + 140, y + 10, x + 150, y + 30); // Front headlight
    floodfill(x + 141, y + 11, WHITE);
}

void drawRoad() {
    // Road surface
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(0, 350, 640, 480);
    floodfill(1, 351, WHITE);

    // Lane markings
    setfillstyle(SOLID_FILL, WHITE);
    for (int i = 0; i < 640; i += 80) {
        rectangle(i + 20, 400, i + 50, 410);
        floodfill(i + 21, 401, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x = 0, y = 370; // Initial position of the car

    while (!kbhit()) { // Keep moving the car until a key is pressed
        cleardevice(); // Clear the screen

        drawRoad(); // Draw the road
        drawCar(x, y); // Draw the car at the current position

        x += 5; // Move the car to the right
        if (x > getmaxx()) { // Reset position when the car goes off-screen
            x = -150;
        }

        delay(50); // Slow down the animation
    }

    getch();
    closegraph();
    return 0;
}
