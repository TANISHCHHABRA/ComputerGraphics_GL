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
    glVertex2i(x+200, y+200);
    glEnd();
}

void elipse(int rx, int ry, int xc, int yc) 
{
    float dx, dy, p1, p2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    glColor3f(0.0, 1.0, 0.0);

    // For region 1
    while (dx < dy)
    {
        draw_pixel(x + xc, y + yc);
        draw_pixel(-x + xc, y + yc);
        draw_pixel(x + xc, -y + yc);
        draw_pixel(-x + xc, -y + yc);

        if (p1 < 0)
        {
            dx = dx + (2 * ry * ry);
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            p1 = p1 + dx - dy + (ry * ry);
        }
        x++;

    }

    p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
        ((rx * rx) * ((y - 1) * (y - 1))) -
        (rx * rx * ry * ry);

    while (y >= 0)
    {
        draw_pixel(x + xc, y + yc);
        draw_pixel(-x + xc, y + yc);
        draw_pixel(x + xc, -y + yc);
        draw_pixel(-x + xc, -y + yc);
    
        if (p2 > 0)
        {
            dy = dy - (2 * rx * rx);
            p2 = p2 + (rx * rx) - dy;
        }
        else
        {
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            p2 = p2 + dx - dy + (rx * rx);
        }
        y--;
    }

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();
    //glPointSize(2.0);
    int a, b;
    a = 100;
    b = 50;
    elipse(a, b, 0, 0);
    glFlush();
}

void init() 
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0,500,0,500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 200);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Ellipse");
    glutDisplayFunc(display);
    init();

    glutMainLoop();
    return 0;
}