#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

int main()
{
    int centerX = 250, centerY = 250, semiMajor = 170, semiMinor = 70;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int decisionParam1 = semiMinor * semiMinor + (semiMajor * semiMajor) / 4 - semiMajor * semiMajor * semiMinor;
    int xCoord = 0;
    int yCoord = semiMinor;

    while (xCoord * semiMinor * semiMinor < yCoord * semiMajor * semiMajor)
    {
        putpixel(centerX + xCoord, centerY + yCoord, RED);
        putpixel(centerX - xCoord, centerY + yCoord, RED);
        putpixel(centerX + xCoord, centerY - yCoord, RED);
        putpixel(centerX - xCoord, centerY - yCoord, RED);

        if (decisionParam1 < 0)
        {
            xCoord++;
            decisionParam1 = decisionParam1 + 2 * semiMinor * semiMinor * xCoord + semiMinor * semiMinor;
        }
        else
        {
            xCoord++;
            yCoord--;
            decisionParam1 = decisionParam1 + 2 * semiMinor * semiMinor * xCoord + semiMinor * semiMinor - 2 * semiMajor * semiMajor * yCoord;
        }
    }

    int decisionParam2 = pow(xCoord + 0.5, 2) * semiMinor * semiMinor + pow(yCoord - 1, 2) * semiMajor * semiMajor - semiMajor * semiMajor * semiMinor * semiMinor;

    while (yCoord >= 0)
    {
        putpixel(centerX + xCoord, centerY + yCoord, RED);
        putpixel(centerX - xCoord, centerY + yCoord, RED);
        putpixel(centerX + xCoord, centerY - yCoord, RED);
        putpixel(centerX - xCoord, centerY - yCoord, RED);

        if (decisionParam2 < 0)
        {
            xCoord++;
            yCoord--;
            decisionParam2 = decisionParam2 + 5 * semiMajor * semiMajor - 2 * semiMajor * semiMajor * yCoord + 2 * semiMinor * semiMinor * xCoord + 4 * semiMinor * semiMinor;
        }
        else
        {
            yCoord--;
            decisionParam2 = decisionParam2 + 5 * semiMajor * semiMajor - 2 * semiMajor * semiMajor * yCoord;
        }
    }

    getch();
    closegraph();
    return 0;
}
