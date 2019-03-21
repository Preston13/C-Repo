#include <iostream>
#include <windows.h> //for MS windows only
#include <GL/glut.h>

class screenPt
{
private:
	GLint x, y;

public:
	screenPt(){
		x = y = 0;
	}

	void setCoords(GLint xCoordValue, GLint yCoordValue){
		x = xCoordValue;
		y = yCoordValue;
	}

	GLint getx() const{
		return x;
	}

	GLint gety() const{
		return y;
	}
	void incrementx(){
		x++;
	}

	void decrementy(){
		y--;
	}
};

void setPixel(GLint xCoord, GLint yCoord){
	glBegin(GL_POINTS);
	glVertex2i(xCoord, yCoord);
	glEnd();
}

void circleMidpoint(GLint xc, GLint yc, GLint radius){
	screenPt circPt;

	GLint p = 1 - radius;

	circPt.setCoords(0, radius);

	void circlePlotPoints(GLint, GLint, screenPt);

	circlePlotPoints(xc, yc, circPt);

	while(circPt.getx() < circPt.gety()){
		circPt.incrementx();
		if(p < 0){
			p += 2 * (circPt.getx()) + 1;
		}
		else{
			circPt.decrementy();
			p += 2 * (circPt.getx() - circPt.gety()) + 1;
		}
		circlePlotPoints(xc, yc, circPt);
	}
}

void circlePlotPoints(GLint xc, GLint yc, screenPt circPt){
	setPixel(xc + circPt.getx(), yc + circPt.gety());
	setPixel(xc - circPt.getx(), yc + circPt.gety());
	setPixel(xc + circPt.getx(), yc - circPt.gety());
	setPixel(xc - circPt.getx(), yc - circPt.gety());
	setPixel(xc + circPt.gety(), yc + circPt.getx());
	setPixel(xc - circPt.gety(), yc + circPt.getx());
	setPixel(xc + circPt.gety(), yc - circPt.getx());
	setPixel(xc - circPt.gety(), yc - circPt.getx());
}

inline int round(const float a)
{
	return int (a + 0.5);
}

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry)
{
	int Rx2 = Rx * Rx;
	int Ry2 = Ry * Ry;
	int twoRx2 = 2 * Rx2;
	int twoRy2 = 2 * Ry2;
	int p;
	int x = 0;
	int y = Ry;
	int px = 0;
	int py = twoRx2 * y;

	void ellipsePlotPoints(int, int, int, int);

	ellipsePlotPoints(xCenter, yCenter, x, y);

	p = round(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));

	while(px < py)
	{
		x++;
		px += twoRy2;
		if(p < 0){
			p += Ry2 + px;
		}
		else{
			y--;
			py -= twoRx2;
			p += Ry2 + px - py;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}

	p = round(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);

	while (y > 0){
		y--;
		py -= twoRx2;
		if(p > 0){
			p += Rx2 - py;
		}
		else{
			x++;
			px += twoRx2;
			p += Rx2 - py + px;
		}
		ellipsePlotPoints(xCenter, yCenter, x, y);
	}

}

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y)
{
	setPixel(xCenter + x, yCenter + y);
	setPixel(xCenter - x, yCenter + y);
	setPixel(xCenter + x, yCenter - y);
	setPixel(xCenter - x, yCenter - y);
}



void drawCirclePoints(){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);
	circleMidpoint(50, 100, 25);

	glColor3f(0.0, 0.0, 0.0);
	circleMidpoint(105, 100, 25);

	glColor3f(1.0, 0.0, 0.0);
	circleMidpoint(160, 100, 25);

	glColor3f(1.0, 1.0, 0.0);
	circleMidpoint(80, 75, 25);

	glColor3f(0.0, 1.0, 0.0);
	circleMidpoint(135, 75, 25);

	glFlush();
}

void drawEllipsePoints(){
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);
	ellipseMidpoint(50, 100, 25, 20);

	glColor3f(0.0, 0.0, 0.0);
	ellipseMidpoint(105, 100, 25, 20);

	glColor3f(1.0, 0.0, 0.0);
	ellipseMidpoint(160, 100, 25, 20);

	glColor3f(1.0, 1.0, 0.0);
	ellipseMidpoint(80, 75, 25, 20);

	glColor3f(0.0, 1.0, 0.0);
	ellipseMidpoint(135, 75, 25, 20);

	glFlush();
}




void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,300.0,0.0,150.0);
}


int main(int argc, char ** argv) {
glutInit(&argc, argv);							//initialize glut
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set display mode
glutInitWindowPosition(50,100);					//set top-left display-window
glutInitWindowSize(300,150);
glutCreateWindow("Olympic Rings");
init();
glutDisplayFunc(drawCirclePoints);
glutMainLoop();
}
