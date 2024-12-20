#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

// Class for drawing the traffic light
class TrafficLight

 {


private:

    int state; // 0 = Red, 1 = Yellow, 2 = Green
public:

    TrafficLight() : state(0) {} // Initialize with red light

    void draw()

    
     {
        // Traffic light pole and base

        setfillstyle(SOLID_FILL, BLACK);
        rectangle(500, 100, 550, 300); // Pole
        floodfill(501, 101, WHITE);


        // Base of the pole
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

    void updateState() 

    {
        state = (state + 1) % 3; // Cycle through 0 -> 1 -> 2 -> 0
    }


    int getState() 
    {
        return state;
    }
};

// Class for drawing the car
class Car

 {

private:

    int x, y;
    
public:

    Car(int startX, int startY) : x(startX), y(startY) {}

    void draw()

     {
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

    void move()
     {
        x += 5; // Move car forward
    }

    void resetPosition(int screenWidth)
     {
        if (x > screenWidth) 
        {
            x = -100; // Reset position if off-screen
        }
    }
};

// Class for drawing the road

class Road 
{
public:
    void draw()
     {
        // Road
        setfillstyle(SOLID_FILL, DARKGRAY);
        rectangle(0, 400, 640, 480);
        floodfill(1, 401, WHITE);

        // Lane markings
        setfillstyle(SOLID_FILL, WHITE);
        for (int i = 0; i < 640; i += 80) 
        {
            rectangle(i + 30, 440, i + 50, 450);
            floodfill(i + 31, 441, WHITE);
        }
    }
};

// Main simulation class
class Simulation 
{
private:
    TrafficLight trafficLight;
    Car car;
    Road road;
    int timer; // Timer for traffic light state change

public:
    Simulation() : car(0, 420), timer(0) {}

    void run()
     {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");

        while (!kbhit()) { // Run until a key is pressed
            cleardevice(); // Clear the screen

            // Draw traffic light
            trafficLight.draw();

            // Draw road
            road.draw();

            // Move the car only if the light is green
            if (trafficLight.getState() == 2) 
            
            {
                car.move();
            }

            // Reset car position if off-screen
            car.resetPosition(getmaxx());

            // Draw the car
            car.draw();

            // Update traffic light state every 100 cycles (about 5 seconds)
            timer++;
            if (timer > 100)


             {
                trafficLight.updateState();
                timer = 0;
            }

            delay(50); // Animation delay
        }

        getch();
        closegraph();


    }

};

int main()

 {

    Simulation simulation;
    simulation.run();
    return 0;

}