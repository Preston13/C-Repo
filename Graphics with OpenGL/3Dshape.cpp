#include <GL/glut.h>
#include<windows.h>
GLint winWidth = 600, winHeight = 600; // Initial display-window size.
GLdouble x0 = 150.0, ya = 150.0, z0 = 100.0; // Viewing-coordinate origin.
GLdouble xref = 0.0, yref = 0.0, zref = -100.0; // Look-at point.
GLdouble Vx = 0.0, Vy = 1.0, Vz = 0.0; // View-up vector.
/* Set coordinate limits for the clipping window: */
GLfloat xwMin = -200.0, ywMin = -200.0, xwMax = 200.0, ywMax = 200.0;
/* Set positions for near and far clipping planes: */
GLfloat dnear = 25.0, dfar = 300.0;

void init (void)
{
glClearColor (1.0, 1.0, 1.0, 0.0);
glMatrixMode (GL_MODELVIEW);
gluLookAt (x0, ya, z0, xref, yref, zref, Vx, Vy, Vz);
glMatrixMode (GL_PROJECTION);
glOrtho (xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}
void displayFcn (void)
{
glClear (GL_COLOR_BUFFER_BIT);
/* Set parameters for a square fill area. */
glColor3f (0.0, 1.0, 0.0); // Set fill color to green.
glPolygonMode (GL_FRONT, GL_FILL);
glPolygonMode (GL_BACK, GL_LINE); // Wire-frame back face.
glPushMatrix();
glutSolidCube(100.0);
glPopMatrix();

glColor3f(1.0, 0.0, 0.0);
glPushMatrix();
glTranslated(150.0, 0.0, 0.0);
glutWireSphere(60.0, 40, 40);
glPopMatrix();

glColor3f(0.0, 0.0, 1.0);
glPushMatrix();
glTranslated(0.0, 150.0, 0.0);
glutWireCone(50.0, 75.0, 32, 32);
glPopMatrix();
glFlush ( );
}
void reshapeFcn (GLint newWidth, GLint newHeight)
{
glViewport (0, 0, newWidth, newHeight);
winWidth = newWidth;
winHeight = newHeight;
}
int main (int argc, char** argv)
{
glutInit (&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition (50, 50);
glutInitWindowSize (winWidth, winHeight);
glutCreateWindow ("Perspective View of A Square");
init ( );
glutDisplayFunc (displayFcn);
glutReshapeFunc (reshapeFcn);
glutMainLoop ( );
}




