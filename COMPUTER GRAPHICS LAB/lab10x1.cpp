#include <graphics.h>
#include <conio.h>

void drawBall(int x, int y, int radius)
{
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, radius, radius);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 100, y = 100;
    int radius = 20;
    int dx = 5, dy = 5;
    int delayTime = 30;

    while (!kbhit())
    {
        cleardevice();
        drawBall(x, y, radius);

        x += dx;
        y += dy;

        if (x - radius <= 0 || x + radius >= getmaxx())
        {
            dx = -dx;
        }
        if (y - radius <= 0 || y + radius >= getmaxy())
        {
            dy = -dy;
        }

        delay(delayTime);
    }

    closegraph();
    return 0;
}