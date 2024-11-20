#include <graphics.h>
#include <conio.h>

void drawHut()
{
    // Draw the base of the hut
    rectangle(100, 300, 300, 400);
    // Draw the roof of the hut
    line(100, 300, 200, 200);
    line(200, 200, 300, 300);
}

void drawFace()
{
    // Draw the face
    circle(500, 300, 50);
    // Draw the eyes
    circle(480, 280, 5);
    circle(520, 280, 5);
    // Draw the mouth
    ellipse(500, 320, 0, 180, 20, 10);
}

void drawKite()
{
    // Draw the kite
    line(400, 100, 450, 150);
    line(450, 150, 400, 200);
    line(400, 200, 350, 150);
    line(350, 150, 400, 100);
    // Draw the tail
    line(400, 200, 400, 300);
    line(400, 220, 410, 230);
    line(400, 240, 390, 250);
    line(400, 260, 410, 270);
    line(400, 280, 390, 290);
}

void drawFish()
{
    // Draw the body of the fish
    ellipse(300, 300, 0, 360, 50, 20);
    // Draw the tail
    line(350, 300, 380, 280);
    line(350, 300, 380, 320);
    line(380, 280, 380, 320);
    // Draw the eye
    circle(280, 290, 5);
}

int main()
{
    int gd = DETECT, gm;
    char driver[] = "C:\\Turboc3\\BGI";
    initgraph(&gd, &gm, driver);

    drawHut();
    drawFace();
    drawKite();
    drawFish();

    getch();
    closegraph();
    return 0;
}