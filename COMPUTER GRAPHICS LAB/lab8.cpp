#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>

using namespace std;

// Define the points of a cube in 3D space
struct Point3D
{
    int x, y, z;
};

const int n = 8;
Point3D cube[n] = {
    {50, 50, 50}, {150, 50, 50}, {150, 150, 50}, {50, 150, 50}, {50, 50, 150}, {150, 50, 150}, {150, 150, 150}, {50, 150, 150}};

// Project 3D points to 2D (assuming a simple orthographic projection)
void project(Point3D p[], int x[], int y[])
{
    for (int i = 0; i < n; i++)
    {
        x[i] = p[i].x + p[i].z * 0.5; // simple perspective
        y[i] = p[i].y + p[i].z * 0.5;
    }
}

// Draw the edges of the cube
void drawCube(Point3D p[])
{
    int x[n], y[n];
    project(p, x, y);

    // Draw front face
    for (int i = 0; i < 4; i++)
    {
        line(x[i], y[i], x[(i + 1) % 4], y[(i + 1) % 4]);
    }
    // Draw back face
    for (int i = 4; i < 8; i++)
    {
        line(x[i], y[i], x[(i + 1) % 4 + 4], y[(i + 1) % 4 + 4]);
    }
    // Draw connecting lines
    for (int i = 0; i < 4; i++)
    {
        line(x[i], y[i], x[i + 4], y[i + 4]);
    }
}

// Translation function
void translate(Point3D p[], int tx, int ty, int tz)
{
    for (int i = 0; i < n; i++)
    {
        p[i].x += tx;
        p[i].y += ty;
        p[i].z += tz;
    }
}

// Rotation function (about the Y-axis)
void rotateY(Point3D p[], float angle)
{
    float rad = angle * M_PI / 180.0;
    for (int i = 0; i < n; i++)
    {
        int x = p[i].x;
        p[i].x = cos(rad) * x - sin(rad) * p[i].z;
        p[i].z = sin(rad) * x + cos(rad) * p[i].z;
    }
}

// Scaling function
void scale(Point3D p[], float sx, float sy, float sz)
{
    for (int i = 0; i < n; i++)
    {
        p[i].x = p[i].x * sx;
        p[i].y = p[i].y * sy;
        p[i].z = p[i].z * sz;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Initial drawing of cube
    // drawCube(cube);
    // getch();

    // delay(10000);

    // Test translation
    cleardevice();
    translate(cube, 150, 120, 0); // translate cube by 50 units in x and y
    drawCube(cube);
    getch();

    // delay(10000);

    // cleardevice();
    // rotateY(cube, 35); // rotate cube 45 degrees about Y-axis
    // drawCube(cube);
    // getch();

    // delay(10000);

    // cleardevice();
    // scale(cube, 2, 2, 2); // scale cube by 1.5 times in all directions
    // drawCube(cube);
    // getch();

    closegraph();
    return 0;
}
