/*
Tanish Chhabra
101916038
CS10
*/

#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>
#include<iostream>

using namespace std;

void draw_pixel(int x, int y) 
{
    glBegin(GL_POINTS);
    glVertex2i(x + 200, y + 200);
    glEnd();
}

void init() 
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);

}


void circle(int r) {
    int x, y;
    float decision = 5.0 / 4 - r;
    x = 0;
    y = r;

    while (x != y) 
    {
        if (decision < 0)
        {
            x++;
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            decision += 2 * (x - y) + 1;
        }

        draw_pixel(x, y);
        draw_pixel(x, -y);
        draw_pixel(-x, y);
        draw_pixel(-x, -y);
        draw_pixel(y, x);
        draw_pixel(-y, x);
        draw_pixel(y, -x);
        draw_pixel(-y, -x);
        
    }

}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(3);

    circle(30);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle");
    glutDisplayFunc(display);
    init();

    glutMainLoop();
    return 0;
}