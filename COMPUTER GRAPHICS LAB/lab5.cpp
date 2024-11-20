#include <graphics.h>
#include <conio.h>
#include <math.h>

void translate(int x, int y, int tx, int ty)
{
    setcolor(RED);
    rectangle(x, y, x + 100, y + 50);

    x = x + tx;
    y = y + ty;

    setcolor(GREEN);
    rectangle(x, y, x + 100, y + 50);
}

void rotate(int x, int y, int angle)
{
    setcolor(RED);
    rectangle(x, y, x + 100, y + 50);

    float rad = angle * M_PI / 180;

    // Center of the rectangle
    int xc = x + 50;
    int yc = y + 25;

    // Rotate each corner of the rectangle
    int x1 = x, y1 = y;
    int x2 = x + 100, y2 = y;
    int x3 = x + 100, y3 = y + 50;
    int x4 = x, y4 = y + 50;

    int newX1 = xc + (x1 - xc) * cos(rad) - (y1 - yc) * sin(rad);
    int newY1 = yc + (x1 - xc) * sin(rad) + (y1 - yc) * cos(rad);

    int newX2 = xc + (x2 - xc) * cos(rad) - (y2 - yc) * sin(rad);
    int newY2 = yc + (x2 - xc) * sin(rad) + (y2 - yc) * cos(rad);

    int newX3 = xc + (x3 - xc) * cos(rad) - (y3 - yc) * sin(rad);
    int newY3 = yc + (x3 - xc) * sin(rad) + (y3 - yc) * cos(rad);

    int newX4 = xc + (x4 - xc) * cos(rad) - (y4 - yc) * sin(rad);
    int newY4 = yc + (x4 - xc) * sin(rad) + (y4 - yc) * cos(rad);

    setcolor(GREEN);
    line(newX1, newY1, newX2, newY2);
    line(newX2, newY2, newX3, newY3);
    line(newX3, newY3, newX4, newY4);
    line(newX4, newY4, newX1, newY1);
}

void scale(int x, int y, float sx, float sy)
{
    setcolor(RED);
    rectangle(x, y, x + 100, y + 50);

    x = x * sx;
    y = y * sy;

    setcolor(GREEN);
    rectangle(x, y, x + 100 * sx, y + 50 * sy);
}

void reflect(int x, int y)
{
    setcolor(RED);
    rectangle(x, y, x + 100, y + 50);

    setcolor(GREEN);
    rectangle(getmaxx() - x - 100, y, getmaxx() - x, y + 50);
}

void shear(int x, int y, int shx, int shy)
{
    setcolor(RED);
    rectangle(x, y, x + 100, y + 50);

    int newX = x + shx * y;
    int newY = y + shy * x;

    setcolor(GREEN);
    rectangle(newX, newY, newX + 100 + shx * 50, newY + 50);
}

int main()
{
    int gd = DETECT, gm;
    char driver[] = " ";
    initgraph(&gd, &gm, driver);

    int x = 100, y = 100;
    // Translation by (50, 50)
    // translate(x, y, 60, 50);
    // delay(10000);
    // cleardevice();
    // Rotation by 45 degrees
    // rotate(x, y, 90);
    // delay(10000);
    // cleardevice();
    // Scaling by 1.5x in both directions
    // scale(x, y, 2, 2);
    // delay(100000);
    // cleardevice();
    // Reflection about the y-axis
    // reflect(x, y);
    // delay(10000);
    // cleardevice();
    // Shearing along the x-axis
    shear(x, y, 3, 0);

    getch();
    closegraph();
    return 0;
}
