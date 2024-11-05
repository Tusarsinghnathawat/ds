#include <GL/glut.h> // GLUT, include glu.h and gl.h used for the GLU & GL libraries 
#include <iostream>
#include <math.h> // Needed to use sin, cos, etc.

using namespace std;

class line {
	
	public :
		float X1, X2, Y1, Y2;
		int XX1, XX2, YY1, YY2;
		
		
		void getPointsBresenham();
		void getPointsDDA();
		
		void drawLine(int X1, int X2, int Y1, int Y2);
		void drawLine(float X1, float X2, float Y1, float Y2);
};
void line :: getPointsBresenham(){  
	cout << "Enter the Coordinates : \n";
	cout << "x1, y1 : "; cin >>  this->XX1 >>  this->YY1;
	cout << "x2, y2 : "; cin >>  this->XX2 >>  this->YY2;
	cout << "-------------------------------\n";
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	drawLine(this->XX1,this->XX2, this->YY1, this->YY2);
	glFlush();
}

void line :: getPointsDDA(){
	cout << "Enter the Coordinates : \n";
	cout << "x1, y1 : "; cin >>  this->X1 >>  this->Y1;
	cout << "x2, y2 : "; cin >>  this->X2 >>  this->Y2;
	cout << "-------------------------------\n";
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	drawLine(this->X1,this->X2, this->Y1, this->Y2);
	glFlush();
}

void line :: drawLine(int X1, int X2, int Y1, int Y2){ //DDA
	
	float dx, dy, step, xInc, yInc, x = X1, y = Y1;

	dx = X2 - X1;
	dy = Y2 - Y1;
	
	(abs(dx) > abs(dy))? step = abs(dx) : step = abs(dy);
	xInc = dx/step;
	yInc = dy/step;

	for (int i = 0; i <= step ; i++){
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
		x += xInc;
		y += yInc;
	}
}

void line :: drawLine(float X1, float X2, float Y1, float Y2){ //Bresenham
	
	int dx, dy, xInc, yInc, d, i1, i2, x, y;
		
	x = X1;
	y = Y1;

	dx = abs(X2 - X1);
	dy = abs(Y2 - Y1);

	(X1 > X2) ? xInc = -1 : xInc = 1;
	(Y1 > Y2) ? yInc = -1 : yInc = 1;

	if (dx > dy){
		i1 = 2 * dy;
		i2 = 2 * (dy - dx);
		d = i1 - dx;
		for (int i = 0; i <= dx; i++){
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd(); 
			glFlush();
			x += xInc;
			if (d < 0)
				d += i1;
			else{
				y += yInc;
				d += i2;
			}
		}
	}
	else { 
		i1 = 2 * dx;
		i2 = 2 * (dx - dy);
		d = i1 - dy;
		for (int i = 0; i < dy; i++){
			glBegin(GL_POINTS);
			glVertex2i(x,y);
			glEnd();
			glFlush();
			y += yInc;
			if (d < 0)
				d += i1;
			else{
				x += xInc;
				d += i2;
			}
		}
	}
}


void myInit(){
	glClearColor(0,0,0,0); // Set background color to black and opaque
	glColor3f(1,1,1); // Set drawing color to white
	glMatrixMode(GL_PROJECTION); // To operate on the model-view matrix
	glLoadIdentity(); // Reset the model-view matrix
	gluOrtho2D(-500,500,-500,500); // Set the world coordinates.
}

void keyboard (unsigned char key, int x, int y) {
	if (key == 'b'||key=='B') {line l;l.getPointsBresenham();}
	if (key == 'd'||key=='D') {line l;l.getPointsDDA(); }
	if(key==27||key==32||key==13)  exit (0);
}

int main(int argc, char** argv){ //argc - argument count, argv - argument vector (array of character pointers) 

	cout << "---MENU---\n";
	cout << "1. D or d - DDA Algorithm \n";
	cout << "2. B or b- Simple Bresenham Algorithm \n";
	cout << "\n";
	
		
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB); // Set the display mode
	glutInitWindowSize(400,400); // Set the width and height of the window
	glutInitWindowPosition(50,50); // Set the position of the window's initial top-left corner
	glutCreateWindow("Line Drawing Algorithm"); // Create a window with the given title
	glutKeyboardFunc(keyboard); // Register callback handler for special-key event
	myInit(); // Call initialization routines

	glutMainLoop(); // Enter the event-processing loop 

	return 0;
}
