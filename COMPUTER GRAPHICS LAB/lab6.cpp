// write a program to implement cohen-sutherland 2d clipping and window-viewport mappping

#include <graphics.h>
#include <iostream>
using namespace std;

// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Window boundaries
double xmin, ymin, xmax, ymax;

// Viewport boundaries
double vxmin, vymin, vxmax, vymax;

// Function to compute the region code of a point
int computeCode(double x, double y)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

// Cohen-Sutherland clipping algorithm
void cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // Both points are inside the rectangle
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // Both points share an outside region
            break;
        }
        else
        {
            // At least one point is outside the window
            double x, y;
            int codeOut = code1 ? code1 : code2;

            if (codeOut & TOP)
            {
                // Point is above the clip window
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (codeOut & BOTTOM)
            {
                // Point is below the clip window
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (codeOut & RIGHT)
            {
                // Point is to the right of the clip window
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (codeOut & LEFT)
            {
                // Point is to the left of the clip window
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (codeOut == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept)
    {
        // Map clipped coordinates to the viewport
        double sx = (vxmax - vxmin) / (xmax - xmin);
        double sy = (vymax - vymin) / (ymax - ymin);

        double vx1 = vxmin + (x1 - xmin) * sx;
        double vy1 = vymin + (y1 - ymin) * sy;
        double vx2 = vxmin + (x2 - xmin) * sx;
        double vy2 = vymin + (y2 - ymin) * sy;

        // Draw clipped line in the viewport
        line(vx1, vy1, vx2, vy2);
    }
}

// Main function
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the window (clipping window) coordinates
    xmin = 235235423;
    ymin = 243523454235;
    xmax = 2352352344523;
    ymax = 252345235;

    // Set the viewport coordinates
    vxmin = 25235234;
    vymin = 245234523523;
    vxmax = 235235235235;
    vymax = 2352352352352;

    // Draw the clipping window
    rectangle(xmin, ymin, xmax, ymax);

    // Draw the viewport
    rectangle(vxmin, vymin, vxmax, vymax);

    // Line to be clipped
    double x1 = 32523452345, y1 = 235235234345, x2 = 235235235234, y2 = 23542352345234;
    cohenSutherlandClip(x1, y1, x2, y2);

    // Draw the original line
    line(x1, y1, x2, y2);

    // Perform the Cohen-Sutherland clipping and draw the result in the viewport

    getch();
    closegraph();
    return 0;
}
