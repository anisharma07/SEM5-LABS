#include <graphics.h>
#include <iostream>

void plotEllipsePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}
// Function to draw a line using Bresenham's algorithm
void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        putpixel(x1, y1, WHITE); // Plot the pixel
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

void bresenhamEllipse(int xc, int yc, int rx, int ry)
{
    int x = 0;
    int y = ry;
    int rxSq = rx * rx;
    int rySq = ry * ry;
    int rxSqTwo = 2 * rxSq;
    int rySqTwo = 2 * rySq;
    int p;
    int px = 0;
    int py = rxSqTwo * y;

    // Region 1
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
        plotEllipsePoints(xc, yc, x, y);
    }

    // Region 2
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
        plotEllipsePoints(xc, yc, x, y);
    }
}

void bresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;
    while (x <= y)
    {
        putpixel(xc + x, yc + y, RED);
        putpixel(xc - x, yc + y, GREEN);
        putpixel(xc + x, yc - y, BLUE);
        putpixel(xc - x, yc - y, YELLOW);
        putpixel(xc + y, yc + x, RED);
        putpixel(xc - y, yc + x, GREEN);
        putpixel(xc + y, yc - x, BLUE);
        putpixel(xc - y, yc - x, YELLOW);
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

int main()
{
    int gd = DETECT, gm;
    char driver[] = "";
    initgraph(&gd, &gm, driver);
    int xc, yc, rx, ry, x1, x2, y1, y2;

    // ellipse, circle
    xc = 200;
    yc = 200;
    ry = 100;
    rx = 150;
    // line
    x1 = 100,
    y1 = 200, x2 = 300, y2 = 400;

    bresenhamLine(x1, y1, x2, y2);
    // bresenhamEllipse(xc, yc, rx, ry);
    int x = 300, y = 300, r = 50;
    // bresenhamCircle(x, y, r);

    getch();
    closegraph();
    return 0;
}