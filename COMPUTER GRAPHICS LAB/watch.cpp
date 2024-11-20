#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void drawCircle(int xc, int yc, int r)
{
    circle(xc, yc, r);
}
void drawLine(int x, int y, int x2, int y2)
{
    line(x, y, x2, y2);
}

void drawHand(int xc, int yc, int length, float angle, int color)
{
    int x = xc + length * cos(angle);
    int y = yc - length * sin(angle);
    setcolor(color);
    line(xc, yc, x, y);
}

void drawWatchFace(int xc, int yc, int r)
{
    drawCircle(xc, yc, r);
    for (int i = 0; i < 12; i++)
    {
        float angle = i * M_PI / 6;
        int x1 = xc + (r - 10) * cos(angle);
        int y1 = yc - (r - 10) * sin(angle);
        int x2 = xc + r * cos(angle);
        int y2 = yc - r * sin(angle);
        line(x1, y1, x2, y2);
    }
}

void drawWatch(int xc, int yc, int r)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int hour = ltm->tm_hour;
    int seconds = ltm->tm_sec;
    int minutes = ltm->tm_min;

    float secondAngle = -(seconds * M_PI / 30); // divide by 30 because 360/12 = 30
    float hourAngle = -((hour * M_PI / 6) + (minutes * M_PI / 360));
    float minuteAngle = -(minutes * M_PI / 30);

    drawWatchFace(xc, yc, r);

    // outer circle
    drawCircle(250, 250, 120);
    // circle for all watch hands
    drawCircle(250, 250, 5);
    drawCircle(250, 250, 2);
    drawCircle(250, 250, 1);
    drawCircle(250, 250, 4);
    drawCircle(250, 250, 3);
    // time dialer
    drawLine(385, 240, 385, 260);
    drawLine(385, 240, 370, 240);
    drawLine(385, 244, 370, 244);
    drawLine(385, 248, 370, 248);
    drawLine(385, 252, 370, 252);
    drawLine(385, 256, 370, 256);
    drawLine(385, 260, 370, 260);
    // up strips
    drawLine(210, 135, 210, 10);
    drawLine(290, 135, 290, 10);
    drawLine(210, 10, 290, 10);
    // down strips
    drawLine(210, 365, 210, 450);
    drawLine(290, 365, 290, 450);
    drawLine(210, 450, 290, 450);

    // tie
    drawLine(240, 470, 240, 430);
    drawLine(260, 470, 260, 430);
    drawLine(240, 470, 260, 470);
    drawLine(240, 430, 260, 430);

    drawHand(xc, yc, r - 50, hourAngle, WHITE);
    drawHand(xc, yc, r - 30, minuteAngle, WHITE);
    drawHand(xc, yc, r - 20, secondAngle, WHITE);
}

int main()
{
    int gd = DETECT, gm;
    char driver[] = "";
    initgraph(&gd, &gm, driver);

    int xc = 250, yc = 250, r = 100;

    while (true)
    {
        cleardevice();
        drawWatch(xc, yc, r);
        delay(1000);
    }

    getch();
    closegraph();
    return 0;
}