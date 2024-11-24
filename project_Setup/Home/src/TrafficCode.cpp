#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

// Function to draw the traffic light
void drawTrafficLight(int state) {
    // Traffic light pole and base
    setfillstyle(SOLID_FILL, BLACK);
    rectangle(500, 100, 550, 300); // Pole
    floodfill(501, 101, WHITE);

    // Base of the pole (to prevent it from floating)
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    rectangle(495, 300, 555, 320); // Base
    floodfill(500, 310, WHITE);

    // Red light
    setfillstyle(SOLID_FILL, state == 0 ? RED : DARKGRAY);
    circle(525, 150, 20); // Top (Red Light)
    floodfill(525, 150, WHITE);

    // Yellow light
    setfillstyle(SOLID_FILL, state == 1 ? YELLOW : DARKGRAY);
    circle(525, 200, 20); // Middle (Yellow Light)
    floodfill(525, 200, WHITE);

    // Green light
    setfillstyle(SOLID_FILL, state == 2 ? GREEN : DARKGRAY);
    circle(525, 250, 20); // Bottom (Green Light)
    floodfill(525, 250, WHITE);
}

// Function to draw the car
void drawCar(int x, int y) {
    // Car body
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(x, y, x + 100, y + 40); // Main body
    floodfill(x + 1, y + 1, WHITE);

    // Car roof
    rectangle(x + 20, y - 20, x + 80, y); // Roof
    floodfill(x + 21, y - 19, WHITE);

    // Wheels
    setfillstyle(SOLID_FILL, BLACK);
    circle(x + 20, y + 50, 10); // Front wheel
    floodfill(x + 21, y + 51, WHITE);

    circle(x + 80, y + 50, 10); // Rear wheel
    floodfill(x + 81, y + 51, WHITE);
}

// Function to draw the road and lane markings
void drawRoad() {
    // Road
    setfillstyle(SOLID_FILL, DARKGRAY);
    rectangle(0, 400, 640, 480);
    floodfill(1, 401, WHITE);

    // Lane markings
    setfillstyle(SOLID_FILL, WHITE);
    for (int i = 0; i < 640; i += 80) {
        rectangle(i + 30, 440, i + 50, 450);
        floodfill(i + 31, 441, WHITE);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int carX = 0, carY = 420; // Initial car position
    int trafficState = 0;     // 0 = Red, 1 = Yellow, 2 = Green
    int timer = 0;            // Timer to manage traffic light change

    while (!kbhit()) { // Run until a key is pressed
        cleardevice(); // Clear the screen

        // Draw traffic light
        drawTrafficLight(trafficState);

        // Draw road
        drawRoad();

        // Move the car only if the light is green
        if (trafficState == 2) {
            carX += 5; // Car moves forward
        }

        // Reset car position if it goes off-screen
        if (carX > getmaxx()) {
            carX = -100;
        }

        // Draw the car
        drawCar(carX, carY);

        // Update traffic light state every 100 cycles (about 5 seconds)
        timer++;
        if (timer > 100) {
            trafficState = (trafficState + 1) % 3; // Cycle: Red -> Yellow -> Green
            timer = 0;
        }

        delay(50); // Animation delay
    }

    getch();
    closegraph();
    return 0;
}
