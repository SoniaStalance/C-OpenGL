#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using  namespace std;

//variable declarations
int pntX1 = 300, pntY1 = 300, radius = 100; //circle variables

//function declarations
void plot(int, int);
void midPointCircleAlgo();

//drawing circle using MidPoint Circle Algorithm
void plot(int x, int y)
{
	//plot point
	glColor3f(1, 1, 0);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glVertex2i(x + pntX1, y + pntY1);
	glEnd();

	//draw a line from centre to plotted point
	glColor3f(1, 1, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2i(pntX1, pntY1);
	glVertex2i(x + pntX1, y + pntY1);
	glEnd();
}

void midPointCircleAlgo()
{
	int x = 0;
	int y = radius;
	float decision = 5 / 4 - radius;
	plot(x, y);

	while (y > x)
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
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

void myDisplay(void)
{
		midPointCircleAlgo();
		glFlush();
		glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MidPoint Circle Algorithm -Colored");
	glutDisplayFunc(myDisplay);
	init();
	glutMainLoop();
}
