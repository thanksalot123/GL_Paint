/*
 * =====================================================================================
 *
 *       Filename:  some_shape.cpp
 *
 *    Description:  Mouse Input Test
 *
 *        Version:  1.0
 *        Created:  11/09/20 08:15:25 PM IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Parvesh Kumar
 *
 * =====================================================================================
 */

// Import libraries
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

// Initialize global variables;
int x1, y01, x2, y2;

int a = 250;
int b = 250;

int c = a;
int d = b;

int counter = 0;

bool lbuttonDown;

// Initialize function
void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
	glPointSize(3.0);
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
			cout << "Right button pressed"
			<< endl;
		else
			cout << "Right button lifted "
			<< "at (" << x << "," << y
			<< ")" << endl;
	}
	else if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
			lbuttonDown = true;
		else if (state == GLUT_UP)
			lbuttonDown = false;
	}
}

void motion(int x, int y)
{
	if (lbuttonDown)
		//cout << "Mouse dragged with left button at "
		//<< "(" << x << "," << y << ")" << endl;
	c = a;
	d = b;
	a = x;
	b = 500 - y;
	cout << c << " , " << d << " ; " << a << " , " << b << endl;
	glutPostRedisplay();
}

void motionPassive(int x, int y)
{
	c = a;
	d = b;
	a = x;
	b = 500 - y;
	glutPostRedisplay();
	//cout << "Mouse dragged at "
	//<< "(" << x << "," << y << ")" << endl;
}

void entry(int state)
{
	if (state == GLUT_ENTERED)
		cout << "Mouse Entered" << endl;
	else
		cout << "Mouse Left" << endl;
}

// Function to draw pixels
void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
		glVertex2i(250, 250);
	glEnd();
	if (lbuttonDown){
    	glBegin(GL_POINTS);
    		glVertex2i(x, y);
    	glEnd();
	}
}


// Display function
void myDisplay() {
	glBegin(GL_POINTS);
		glVertex2i(250, 250);
	glEnd();
	if (lbuttonDown){
    	glBegin(GL_LINES);
			glVertex2i(c, d);
    		glVertex2i(a, b);
    	glEnd();
	}
	glFlush();
}


// The main function
int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutPassiveMotionFunc(motionPassive);
	glutEntryFunc(entry);
    glutMainLoop();
}

