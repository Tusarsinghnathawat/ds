#include<bits/stdc++.h> 
#include <GL/gl.h> // Header File For The OpenGL32 Library
#include<GL/glut.h> // Header File For The GLut Library
using namespace std;



GLint n; //number of iterations
class kcurve{
	private:
	int width = 640, height = 480; // window size
	GLfloat oldx=-0.25,oldy=0.25; // initial points
public:
    void display(void); // display function
    void koch(GLfloat ,GLfloat ,GLint ) ; // koch function
}k; // object of class kcurve

void kcurve::koch(GLfloat dir,GLfloat len,GLint n) { 
	GLdouble dirRad = 0.0174533 * dir; 
	GLfloat nX = oldx + len * cos(dirRad); 
	GLfloat nY = oldy + len * sin(dirRad); 
	if (n==0) { // draw the line for the last iteration
		glVertex2f(oldx, oldy); // draw the line
		glVertex2f(nX, nY); // draw the line
		oldx = nX; // save new position
		oldy = nY; // save new position
	}
	else {
		n--; // decrease number of iterations
		koch(dir, len, n); // call koch function
		dir += 60.0; // add 60 degrees
		koch(dir, len, n); // call koch function
		dir -= 120.0; // subtract 120 degrees
		koch(dir, len, n); // call koch function
		dir += 60.0; // add 60 degrees
		koch(dir, len, n); // call koch function
	}
	glutPostRedisplay(); // redisplay everything
} 

void kcurve::display(){
	 glClear( GL_COLOR_BUFFER_BIT ); // clear the screen
	 glBegin(GL_LINES); // draw lines
	 glColor3f(0.0, 1.0, 0.5); // set line color
	 GLfloat len = (1.0)/pow(2, 1.75*n);  // length of the line
	 k.koch(0.0, len, n); 
	 k.koch(-120.0, len, n);
	 k.koch(120.0, len, n);
	 glEnd(); // end drawing lines
	 glFlush(); // flush everything
}
void Display(){
	kcurve object; // create object of class kcurve
	object.display();
}

int main(int argc,char** argv){ //argc is the number of arguments passed to the program and argv is the array of arguments
    cout<<" Enter number iterations : ";
    cin>>n;
    glutInit(&argc,argv); // initialize glut
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); // initialize display mode
	glutInitWindowSize(500,500); // initialize window size
	glutInitWindowPosition(0,0); // initialize window position
	glutCreateWindow("Koch Snowflake Generation"); // create window
	glutDisplayFunc(Display); // call display function
	glutMainLoop(); // event processing loop 
	return 0;
}