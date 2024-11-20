// program to implement mid point circle
#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
using namespace std;
void mid_point_circle(int x, int y, int r)
{
    int xc = 0, yc = r;
    int p = 1 - r;
    while (xc <= yc)
    {
        putpixel(x + xc, y + yc, GREEN);
        putpixel(x - xc, y + yc, GREEN);
        putpixel(x + xc, y - yc, GREEN);
        putpixel(x - xc, y - yc, GREEN);
        putpixel(x + yc, y + xc, GREEN);
        putpixel(x - yc, y + xc, GREEN);
        putpixel(x + yc, y - xc, GREEN);
        putpixel(x - yc, y - xc, GREEN);
        if (p < 0)
        {
            xc++;
            p += 2 * xc + 1;
        }
        else
        {
            xc++;
            yc--;
            p += 2 * (xc - yc) + 1;
        }
    }
}

void mid_point_ellipse(int xc, int yc, int rx, int ry)
{
    int x = 0, y = ry;
    int rxSq = rx * rx;
    int rySq = ry * ry;
    int rxSqTwo = 2 * rxSq;
    int rySqTwo = 2 * rySq;
    int p;
    int px = 0;
    int py = rxSqTwo * y;
    p = rySq - (rxSq * ry) + (0.25 * rxSq);
    while (px < py)
    {
        x++;
        px += rySqTwo;
        if (p < 0)
        {
            p += rySq + px;
        }
        else
        {
            y--;
            py -= rxSqTwo;
            p += rySq + px - py;
        }
        putpixel(xc + x, yc + y, GREEN);
        putpixel(xc - x, yc + y, GREEN);
        putpixel(xc + x, yc - y, GREEN);
        putpixel(xc - x, yc - y, GREEN);
    }
    p = rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq;
    while (y > 0)
    {
        y--;
        py -= rxSqTwo;
        if (p > 0)
        {
            p += rxSq - py;
        }
        else
        {
            x++;
            px += rySqTwo;
            p += rxSq - py + px;
        }
        putpixel(xc + x, yc + y, GREEN);
        putpixel(xc - x, yc + y, GREEN);
        putpixel(xc + x, yc - y, GREEN);
        putpixel(xc - x, yc - y, GREEN);
    }
}

int main()
{

    int gd = DETECT, gm;
    char driver[] = "";
    initgraph(&gd, &gm, driver);
    // mid_point_circle(210, 210, 200);
    mid_point_ellipse(200, 200, 150, 100);
    getch();
    closegraph();

    return 0;
}
