#include <graphics.h>
#include <iostream>
using namespace std;

void drawCircle(int x, int y, int radius)
{
    int decisionParam = 1.25 - radius;
    int x2 = 0;
    int y2 = radius;

    while (x2 <= y2)
    {
        putpixel(x + x2, y + y2, RED);
        putpixel(x + x2, y - y2, RED);
        putpixel(x - x2, y + y2, RED);
        putpixel(x - x2, y - y2, RED);
        putpixel(x + y2, y + x2, RED);
        putpixel(x + y2, y - x2, RED);
        putpixel(x - y2, y + x2, RED);
        putpixel(x - y2, y - x2, RED);

        if (decisionParam < 0)
        {
            decisionParam = decisionParam + 2 * x2 + 3;
            x2++;
        }
        else
        {
            decisionParam = decisionParam + 2 * (x2 - y2) + 5;
            x2++;
            y2--;
        }
    }
}

int main()
{
    int x = 200, y = 200, radius = 70;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    drawCircle(x, y, radius);

    getch();
    closegraph();

    return 0;
}
