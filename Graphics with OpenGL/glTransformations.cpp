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

	glMatrixMode(GL_MODELVIEW);

	float theta = (5 * M_PI) / 3;
	glColor3f(1.0, 0.0, 0.0);
	/*glRotatef(-theta, 0.0, 0.0, 1.0);
	glRotatef(-theta, 0.0, 0.0, 1.0);
	glRotatef(-theta, 0.0, 0.0, 1.0);
	glRotatef(-theta, 0.0, 0.0, 1.0);
	glRotatef(-theta, 0.0, 0.0, 1.0);
	glRotatef(-theta, 0.0, 0.0, 1.0); */
	glTranslatef(15.0, 50.0, 0.0);
	glRotatef(-11.5 * theta, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(0, 100);
	glVertex2i(50, 150);
	glVertex2i(100, 100);
	glVertex2i(50, 25);

	glEnd();
	glFlush();

	glLoadIdentity();
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.0, 100.0, 0.0);
	glTranslatef(15.0, 50.0, 0.0);
	glRotatef(-11.5 * theta, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(0, 100);
	glVertex2i(50, 150);
	glVertex2i(100, 100);
	glVertex2i(50, 25);

	glEnd();
	glFlush();

	glLoadIdentity();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(100.0, 100.0, 0.0);
	glScalef(0.5, 0.5, 1.0);
	glTranslatef(0.0, 100.0, 0.0);
	glTranslatef(15.0, 50.0, 0.0);
	glRotatef(-11.5 * theta, 0.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(0, 100);
	glVertex2i(50, 150);
	glVertex2i(100, 100);
	glVertex2i(50, 25);

	glEnd();
	glFlush();

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
