#include <graphics.h>
#include <iostream>
using namespace std;

// Defining the clipping window structure
struct Window
{
    double xmin, xmax, ymin, ymax;
};

// Function to calculate the Liang-Barsky algorithm
bool liangBarsky(double x0, double y0, double x1, double y1, Window window, double &newX0, double &newY0, double &newX1, double &newY1)
{
    double t0 = 0.0, t1 = 1.0;
    double dx = x1 - x0;
    double dy = y1 - y0;

    double p[] = {-dx, dx, -dy, dy};
    double q[] = {x0 - window.xmin, window.xmax - x0, y0 - window.ymin, window.ymax - y0};

    for (int i = 0; i < 4; i++)
    {
        if (p[i] == 0)
        { // Line is parallel to this boundary
            if (q[i] < 0)
                return false; // Line is outside
        }
        else
        {
            double t = q[i] / p[i];
            if (p[i] < 0)
            {
                t0 = max(t0, t);
            }
            else
            {
                t1 = min(t1, t);
            }
        }
    }

    if (t0 > t1)
        return false; // Line is outside

    newX0 = x0 + t0 * dx;
    newY0 = y0 + t0 * dy;
    newX1 = x0 + t1 * dx;
    newY1 = y0 + t1 * dy;
    return true;
}

// Function to draw the clipping window
void drawWindow(Window window)
{
    rectangle(window.xmin, window.ymin, window.xmax, window.ymax);
}

// Main function
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Window window = {120, 400, 120, 300}; // Define the clipping window

    // Draw the clipping window
    drawWindow(window);

    // Line to be clipped
    double x0 = 20, y0 = 100, x1 = 220, y1 = 220;
    line(x0, y0, x1, y1); // Draw the original line (before clipping)

    double newX0, newY0, newX1, newY1;
    // Apply Liang-Barsky line clipping
    if (liangBarsky(x0, y0, x1, y1, window, newX0, newY0, newX1, newY1))
    {
        setcolor(RED);                    // Set the color to red for the clipped line
        line(newX0, newY0, newX1, newY1); // Draw the clipped line
    }
    else
    {
        cout << "Line is outside the window!" << endl;
    }

    getch();
    closegraph();
    return 0;
}
