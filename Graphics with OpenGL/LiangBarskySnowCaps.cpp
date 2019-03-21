#include <iostream>
#include <math.h>
#include <windows.h> //for MS windows only
#include <GL/glut.h>

class wcPt2D
{
public:
	GLfloat x, y;

public:
	void wcPt3D(){
		x = y = 0.0;
	}

	void setCoords(GLfloat xCoord, GLfloat yCoord){
		x = xCoord;
		y = yCoord;
	}

	GLfloat getx() const{
		return x;
	}

	GLfloat gety() const{
		return y;
	}
};

inline GLint round(const GLfloat a) {
	return GLint (a + 0.5);
}

void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 300.0, 0.0, 300.0);
}

void setPixel(int x, int y)
{

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

GLint clipTest(GLfloat p, GLfloat q, GLfloat * u1, GLfloat * u2){
	GLfloat r;
	GLint returnValue = true;

	if(p < 0.0){
		r = q / p;
		if(r > *u2){
			returnValue = false;
		}
		else if(r > *u1){
			*u1 = r;
		}
	}
	else if(p > 0.0){
		r = q / p;
		if(r < *u1){
			returnValue = false;
		}
		else if(r < *u2){
			*u2 = r;
		}
	}
	else{
		if(q < 0.0){
			returnValue = false;
		}
	}

	return returnValue;
}

void lineBres(int x0, int y0, int xEnd, int yEnd)
{
	float m = (float) (y0 - yEnd) / (x0 - xEnd);

	if(fabs(m) < 1.0){
		int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
		int p = 2 * dy - dx;
		int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
		int x, y;

		if(x0 > xEnd){
			x = xEnd;
			y = yEnd;
			xEnd = x0;
			yEnd = y0;
		}
		else{
			x = x0;
			y = y0;
		}
		setPixel(x, y);


		if(y < yEnd){
			while(x < xEnd){
				x++;
				if(p < 0){
					p += twoDy;
				}
				else{
					y++;
					p += twoDyMinusDx;
				}
				setPixel(x, y);
			}
		}
		else{
			while(x < xEnd){
				x++;
				if(p < 0){
					p += twoDy;
				}
				else{
					y--;
					p += twoDyMinusDx;
				}
				setPixel(x, y);
			}
		}
	}
	else {
		int x1 = x0;
		int y1 = y0;

		int y2 = yEnd;
		int x2 = xEnd;


		if(x0 > xEnd){
			x1 = xEnd;
			y1 = yEnd;
			x2 = x0;
			y2 = y0;
		}
		else{
			x1 = x0;
			y1 = y0;
		}

		int dx = fabs(x2 - x1), dy = fabs(y2 - y1);
		int twoDx = 2 * dx, twoDxMinusDy = 2 * (dx - dy);
		int p = (2 * dx) - dy;
		int x, y;

		x = x1;
		y = y1;

		setPixel(x, y);

		if(y < y2){
			while(y < y2){
				y++;
				if(p < 0){
					p += twoDx;
				}
				else{
					x++;
					p += twoDxMinusDy;
				}
				setPixel(x, y);
			}
		}
		else{
			while(y > y2){
				y--;
				if(p < 0){
					p += twoDx;
				}
				else{
					x++;
					p+= twoDxMinusDy;
				}
				setPixel(x, y);
			}
		}
	}
}

void lineClipLiangBarsk(wcPt2D winMin, wcPt2D winMax, wcPt2D p1, wcPt2D p2){
	GLfloat u1 = 0.0, u2 = 1.0, dx = p2.getx() - p1.getx(), dy;

	if(clipTest(-dx, p1.getx() - winMin.getx(), &u1, &u2)){
		if(clipTest(dx, winMax.getx() - p1.getx(), &u1, &u2)){
			dy = p2.gety() - p1.gety();
			if(clipTest(-dy, p1.gety() - winMin.gety(), &u1, &u2)){
				if(clipTest(dy, winMax.gety() - p1.gety(), &u1, &u2)){
					if(u2 < 1.0){
						p2.setCoords(p1.getx() + u2 * dx, p1.gety() + u2 * dy);
					}
					if(u1 > 0.0){
						p1.setCoords(p1.getx() + u1 * dx, p1.gety() + u1 * dy);
					}
					lineBres(round(p1.getx()), round(p1.gety()), round(p2.getx()), round(p2.gety()));
				}
			}
		}
	}
}

void draw()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-51, 51, -5, 21);
	glViewport(0, 0, 200, 200);

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(-35, -50);
	glVertex2i(-20, 30);

	glVertex2i(-20, 30);
	glVertex2i(-12, -10);

	glVertex2i(-12, -10);
	glVertex2i(-5,50);

	glVertex2i(-5, 50);
	glVertex2i(12, -10);

	glVertex2i(12, -10);
	glVertex2i(25, 30);

	glVertex2i(25, 30);
	glVertex2i(40, -50);

	glVertex2i(-35, -50);
	glVertex2i(40, -50);

	glVertex2i(-25, 0);
	glVertex2i(-20, -10);

	glVertex2i(-20, -10);
	glVertex2i(-15, 0);

	glVertex2i(-10, 0);
	glVertex2i(-5, -10);

	glVertex2i(-5, -10);
	glVertex2i(5, 0);

	glVertex2i(5, 0);
	glVertex2i(7, -10);

	glVertex2i(7, -10);
	glVertex2i(10, 0);

	glVertex2i(15, 0);
	glVertex2i(20, -10);

	glVertex2i(20, -10);
	glVertex2i(30, 0);

	glEnd();
	glFlush();




}

void drawLiangBarsk()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);

	wcPt2D winMin;
	winMin.x = 0.0;
	winMin.y = 45.0;
	wcPt2D winMax;
	winMax.x = 100.0;
	winMax.y = 100.0;

	wcPt2D p1;
	p1.x = 15;
	p1.y = 0;
	wcPt2D p2;
	p2.x = 30;
	p2.y = 80;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 30;
	p1.y = 80;

	p2.x = 38;
	p2.y = 40;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 38;
	p1.y = 40;

	p2.x = 55;
	p2.y = 100;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 55;
	p1.y = 100;

	p2.x = 62;
	p2.y = 40;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 62;
	p1.y = 40;

	p2.x = 75;
	p2.y = 80;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 75;
	p1.y = 80;

	p2.x = 90;
	p2.y = 0;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 25;
	p1.y = 50;

	p2.x = 30;
	p2.y = 40;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 30;
	p1.y = 40;

	p2.x = 35;
	p2.y = 50;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 40;
	p1.y = 50;

	p2.x = 45;
	p2.y = 40;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 45;
	p1.y = 40;

	p2.x = 55;
	p2.y = 50;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 55;
	p1.y = 50;

	p2.x = 57;
	p2.y = 40;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 57;
	p1.y = 40;

	p2.x = 60;
	p2.y = 50;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 65;
	p1.y = 50;

	p2.x = 70;
	p2.y = 40;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 70;
	p1.y = 40;

	p2.x = 80;
	p2.y = 50;

	lineClipLiangBarsk(winMin, winMax, p1, p2);

	p1.x = 15;
	p1.y = 0;

	p2.x = 90;
	p2.y = 0;

	lineClipLiangBarsk(winMin, winMax, p1, p2);



	glFlush();

}


int main(int argc, char ** argv) {
glutInit(&argc, argv);							//initialize glut
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//set display mode
glutInitWindowPosition(50,100);					//set top-left display-window
glutInitWindowSize(400,300);
glutCreateWindow("Snow Cap");
init();
glutDisplayFunc(drawLiangBarsk);
glutMainLoop();
}
