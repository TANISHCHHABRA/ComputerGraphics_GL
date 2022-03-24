/*
Tanish Chhabra
101916038
CS10
*/

#include<iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;
int x1, y1, x2, y2;

void draw_pixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int x2, int y1, int y2)
{
    int dx, dy, i, e;
    int xinc, yinc, inc1, inc2;
    int x, y;
    dx = x2 - x1;
    dy = y2 - y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;

    xinc = 1;
    if (x2 < x1)
        xinc = -1;
    yinc = 1;
    if (y2 < y1)
        yinc = -1;
    x = x1; y = y1;

    if (dx > dy)
    {
        draw_pixel(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            if (e >= 0)
            {
                y += yinc;
                e += inc1;
            }
            else
                e += inc2;
            x += xinc;
            draw_pixel(x, y);
        }
    }
    else
    {
        draw_pixel(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            if (e >= 0)
            {
                x += xinc;
                e += inc1;
            }
            else
                e += inc2;
            y += yinc;
            draw_pixel(x, y);
        }
    }
}

void display()
{
    draw_line(x1, x2, y1, y2);
    glFlush();
}

void myInit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);

    glOrtho(0, 300, 0, 300, -1, 1);
}

int main(int argc, char** argv)
{
    cout << "Enter the value of x1: ";
    cin >> x1;
    cout << "Enter the value of x2: ";
    cin >> x2;
    cout << "Enter the value of y1: ";
    cin >> y1;
    cout << "Enter the value of y2: ";
    cin >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}