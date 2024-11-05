//#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

int N = 0; double L=30 ;
vector<int> jnts;

void conect(double x , double y , double px , double py){
    glPointSize(1);
    glBegin(GL_LINE_STRIP);
        glVertex2i(x,y);
        glVertex2i(px,py);
    glEnd();
    glFlush();
}

void dela (long long int m){
    long long int  n0 = 1e7 , k = 0 ;  m *= n0 ;
    for(long long int i=0;i<m ; i++ ){
        k++; k--;
    }
}

double rev(double n){
    if(180==abs(n)){return 0;}
    if(n==0){return -180;}
    return -n ;
}


class hilbert{
public:
	double  x0,y0;
	hilbert()
	{
		x0= 100 ;
		y0= 100 ;
	}
	void process(int n) {
	    if(n<1) return;
	    vector <int> v ;
	    for(int i = 0 ; i < jnts.size(); i+=4 ){
            double an = 0 ;
            int b[3] = {jnts[i],jnts[i+1],jnts[i+2]} ;
            an  = b[1] ;   
            v.push_back(an) ;
            an  =  b[0] ;      
            v.push_back(an) ;
            an = rev(b[1]) ;      
            v.push_back(an) ;
            an = b[0] ;     
            v.push_back(an) ;
            v.push_back(an) ;
            an = b[1] ;   
            v.push_back(an) ;
            an = b[2] ;     
            v.push_back(an) ;
            an = b[1] ;    
            v.push_back(an) ;
            an = b[0] ;    
            v.push_back(an) ;
            an = b[1] ;    
            v.push_back(an) ;
            an = b[2] ;   
            v.push_back(an) ;
            v.push_back(an) ;
            an = rev(b[1]);   
            v.push_back(an) ;
            an = b[2] ;    
            v.push_back(an) ;
            an = b[1] ;  
            v.push_back(an) ;

             if (i+3<jnts.size()) {
                v.push_back(jnts[i+3]) ;
            }

	    }
	    L /= 2 ;
	    jnts = v;
	    draw() ;
	    dela (1) ;
        process(--n) ;
    }
    void draw(){
        glClearColor(1.0,0.0,0.0,0.0);
        glClear (GL_COLOR_BUFFER_BIT);
        x0 = 100 , y0 = 300 ;   double l = L ;
        double dir = 0 ;
        for(int i=0 ; i < jnts.size() ;i++){
            dir  = (0.0174533 * jnts[i]) ;
            double x1 = x0 + l * cos(dir);
            double y1 = y0 + l * sin(dir);
            conect(x0,y0,x1,y1) ;
            x0 = x1 ;
            y0 = y1 ;
            glFlush() ;
            dela (1) ;
        }
    }
} obj ;


void init()
{
	glClearColor(0.0,0.5,0.5,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500, 0,500) ;
	glFlush() ;
}

void display(){
    glColor3f(0.0,0.0,0.5);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1);
    jnts.push_back(-90) ;
    jnts.push_back(0) ;
    jnts.push_back(+90) ;
    obj.process(N);
    if(N==0)
    obj.draw() ;
    glFlush() ;
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
	glutInitWindowPosition(500,150);
	glutCreateWindow(" Hilbert Curve ");

    cout << "Enter number of iterations : ";
    cin >> N ;
    cout << "\nEnter length : ";
    cin >> L ;
	init();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;

}

