#include <iostream>
#include <math.h>
#include <windows.h> //for MS windows only
#include <GL/glut.h>

void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,400.0,0.0,300.0);
}

void scale(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
	int x1P, x2P, x3P, x4P, y1P, y2P, y3P, y4P;
	float sx = 0.5;
	float sy = 0.5;
	float xf = 200 * (1 - sx);
	float yf = 200 * (1 - sy);

	x1P = (x1 * sx) + 0 + xf;
	y1P = (y1 * sy) + yf;

	x2P = (x2 * sx) + xf;
	y2P = (y2 * sy) + yf;

	x3P = (x3 * sx) + 0 + xf;
	y3P = (y3 * sy) + yf;

	x4P = (x4 * sx) + 0 + xf;
	y4P = (y4 * sy) + yf;

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(x1P, y1P);
	glVertex2i(x2P, y2P);
	glVertex2i(x3P, y3P);
	glVertex2i(x4P, y4P);

	glEnd();
	glFlush();
}

void translate(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
	int x1P, x2P, x3P, x4P, y1P, y2P, y3P, y4P;
	int tx = 0;
	int ty = 100;

	x1P = x1 + 0 + tx;
	y1P = 0 + y1 + ty;

	x2P = x2 + 0 + tx;
	y2P = 0 + y2 + ty;

	x3P = x3 + 0 + tx;
	y3P = 0 + y3 + ty;

	x4P = x4 + 0 + tx;
	y4P = 0 + y4 + ty;

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(x1P, y1P);
	glVertex2i(x2P, y2P);
	glVertex2i(x3P, y3P);
	glVertex2i(x4P, y4P);

	glEnd();
	glFlush();

	scale(x1P, x2P, x3P, x4P, y1P, y2P, y3P, y4P);
}

void rotate()
{
	int x1, x2, x3, x4, y1, y2, y3, y4;
	float angle = ((5 * M_PI) / 3);
	//First set of points (0, 100) pivot point (50, 62)??
	x1 = (0 * cos(angle)) + (100 * (-sin(angle))) + (50 * (1 - cos(angle)) + 10 * sin(angle));
	y1 = (0 * sin(angle)) + (100 * (cos(angle))) + (10 * (1 - cos(angle)) - 50 * sin(angle));

	//Second set of points (50, 150)
	x2 = (50 * cos(angle)) + (150 * (-sin(angle))) + (50 * (1 - cos(angle)) + 10 * sin(angle));
	y2 = (50 * sin(angle)) + (150 * (cos(angle))) + (10 * (1 - cos(angle)) - 50 * sin(angle));

	//Third set of points (100, 100)
	x3 = (100 * cos(angle)) + (100 * (-sin(angle))) + (50 * (1 - cos(angle)) + 10 * sin(angle));
	y3 = (100 * sin(angle)) + (100 * (cos(angle))) + (10 * (1 - cos(angle)) - 50 * sin(angle));

	//Fourth set of points (50, 25)
	x4 = (50 * cos(angle)) + (25 * (-sin(angle))) + (50 * (1 - cos(angle)) + 10 * sin(angle));
	y4 = (50 * sin(angle)) + (25 * (cos(angle))) + (10 * (1 - cos(angle)) - 50 * sin(angle));

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glVertex2i(x4, y4);

	glEnd();
	glFlush();

	translate(x1, x2, x3, x4, y1, y2, y3, y4);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(0, 100);
	glVertex2i(50, 150);
	glVertex2i(100, 100);
	glVertex2i(50, 25);

	glEnd();
	glFlush();

	rotate();
}


int main(int argc, char ** argv) {
glutInit(&argc, argv);							//initialize glut
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set display mode
glutInitWindowPosition(50,100);					//set top-left display-window
glutInitWindowSize(400,300);
glutCreateWindow("Transformation Sequence");
init();
glutDisplayFunc(draw);
glutMainLoop();
}
