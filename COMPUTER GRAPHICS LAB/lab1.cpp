#include <graphics.h>
// #include <cmath>
#include <conio.h>
#include <direct.h>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    int
        x1 = 100,
        y1 = 100, x2 = 50, y2 = 50,
        dx, dy, steps, xincr, yincr;
    char driver[] = " ";
    initgraph(&gd, &gm, driver);
    // cout << "Enter the coordinates of the starting point (x1, y1): ";
    // cin >> x1 >> y1;
    // cout << "Enter the coordinates of the starting point (x2, y2): ";
    // cin >> x2 >> y2;
    dx = x2 - x1;
    dy = y2 - y1;
    steps = max(abs(dx), abs(dy));
    xincr = dx / steps;
    yincr = dy / steps;
    for (int i = 0; i < steps; i++)
    {
        putpixel(x1, y1, WHITE);
        x1 = x1 + xincr;
        y1 = y1 + yincr;
    }
    getch();
    closegraph();
    return 0;
}