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

void display()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	gluOrtho2D(0,100,0,100);

	glBegin(GL_TRIANGLES);
	glVertex2f(10, 50);
	glVertex2f(40, 50);
	glVertex2f(25, 90);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(25, 90);
	glVertex2f(75, 90);
	glVertex2f(90, 50);
	glVertex2f(40, 50);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(10, 50);
	glVertex2f(40, 50);
	glVertex2f(40, 20);
	glVertex2f(10, 20);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("Line");
	glutInitWindowSize(200, 100);
	glutDisplayFunc(display);
	glutMainLoop();


	return 0;
}