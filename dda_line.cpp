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
float x1, y1, x2, y2;

void display(void)
{
    float dy, dx, steps, x, y, k, xinc, yinc;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
        steps = abs(dy);
    xinc = dx / steps;
    yinc = dy / steps;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    for (k = 1; k <= steps; k++)
    {
        x = x + xinc;
        y = y + yinc;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
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
    glutCreateWindow("DDA Line Algo");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}