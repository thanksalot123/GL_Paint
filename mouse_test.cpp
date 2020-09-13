/*
 * =====================================================================================
 *
 *       Filename:  some_shape.cpp
 *
 *    Description:  Assignment1
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
#include <GL/glut.h>
#include <iostream>

// Initialize global variables;
int x1, y01, x2, y2;

// Initialize function
void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

// Function to draw pixels
void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Function to draw lines
void draw_line(int x1, int x2, int y01, int y2) {
    int dx, dy;
    int incx, incy;
	int step;

    dx = x2-x1;
    dy = y2-y01;
	
	if (abs(dx) > abs(dy)){
		step = abs(dx);
	}else{
		step = abs(dy);
	}
	incx = dx / (float) step;
	incy = dy / (float) step;
	
	int X = x1;
	int Y = y01;

	for (int i = 0; i <= step; i++)
	{
	    draw_pixel(X,Y);
	    X += incx;
	    Y += incy;
	}
}

// Define the lines to be drawn to make the pattern
void drawshape(){
    draw_line(200, 200, 200, 240); 
    draw_line(200, 240, 240, 240);
    draw_line(240, 240, 240, 200);
    draw_line(240, 200, 200, 200);
    draw_line(200, 220, 220, 240);
    draw_line(220, 240, 240, 220);
    draw_line(240, 220, 220, 200);
    draw_line(220, 200, 200, 220);

}

// Display function
void myDisplay() {
    drawshape();
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
    glutMainLoop();
}

