#include <graphics.h>
#include <conio.h>

void drawCar(int x, int y)
{
    // Draw the body of the car
    setcolor(RED);
    rectangle(x, y, x + 150, y + 50);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x + 1, y + 1, RED);

    // Draw the roof of the car
    rectangle(x + 30, y - 20, x + 120, y);
    setfillstyle(SOLID_FILL, RED);
    floodfill(x + 31, y - 19, RED);

    // Draw the windows of the car
    setcolor(BLUE);
    rectangle(x + 40, y - 15, x + 70, y - 5);
    rectangle(x + 80, y - 15, x + 110, y - 5);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(x + 41, y - 14, BLUE);
    floodfill(x + 81, y - 14, BLUE);

    // Draw the wheels of the car
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    fillellipse(x + 40, y + 55, 15, 15);
    fillellipse(x + 110, y + 55, 15, 15);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 50, y = 300;
    int dx = 5;
    int delayTime = 30;

    while (!kbhit())
    {
        cleardevice();
        drawCar(x, y);

        x += dx;

        if (x + 150 >= getmaxx() || x <= 0)
        {
            dx = -dx;
        }

        delay(delayTime);
    }

    closegraph();
    return 0;
}