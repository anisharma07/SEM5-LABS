#include <graphics.h>
#include <iostream>

void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void bresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

void bresenhamSemiCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (y >= x)
    {
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        x++;
        if (d > 0)
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
        else
        {
            d = d + 4 * x + 6;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    char driver[] = "";
    initgraph(&gd, &gm, driver);

    // line A
    bresenhamLine(40, 280, 100, 280);
    // line B
    bresenhamLine(200, 280, 300, 280);
    // line C
    bresenhamLine(400, 280, 500, 280);
    // line D
    bresenhamLine(500, 200, 500, 280);
    // vertical right
    bresenhamLine(450, 200, 500, 200);
    // vertical left
    bresenhamLine(40, 280, 40, 200);

    // slanting line left
    bresenhamLine(40, 200, 150, 100);
    // car top
    bresenhamLine(150, 100, 300, 100);
    // slanting line right
    bresenhamLine(300, 100, 450, 200);

    // window 1
    bresenhamLine(150, 150, 220, 150);
    bresenhamLine(150, 150, 150, 200);
    bresenhamLine(220, 150, 220, 200);
    bresenhamLine(150, 200, 220, 200);
    // window 2
    bresenhamLine(250, 150, 320, 150);
    bresenhamLine(250, 150, 250, 200);
    bresenhamLine(320, 150, 320, 200);
    bresenhamLine(250, 200, 320, 200);
    // wheel tops
    bresenhamSemiCircle(150, 280, 50);
    bresenhamSemiCircle(350, 280, 50);
    // wheels
    bresenhamCircle(150, 280, 38);
    bresenhamCircle(350, 280, 38);
    // wheel center
    bresenhamCircle(150, 280, 7);
    bresenhamCircle(350, 280, 7);

    getch();
    closegraph();
    return 0;
}