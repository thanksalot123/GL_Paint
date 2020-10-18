
// Import libraries
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

#include "shapes.h"

using namespace std;

// Initialize global variables;
int x1, y01, x2, y2;

int a = 250;
int b = 250;

int c = a;
int d = b;

int counter = 0;

bool lbuttonDown;
bool rbuttonDown;

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
            rbuttonDown = true;
        else if (state == GLUT_UP)
            rbuttonDown = false;
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
    c = a;
    d = b;
    a = x;
    b = 500 - y;
    glutPostRedisplay();
}

void motionPassive(int x, int y)
{
    c = a;
    d = b;
    a = x;
    b = 500 - y;
    glutPostRedisplay();
}

// Function to draw pixels
void draw_pixel(int x, int y) {
    if (lbuttonDown){
        SquareBrush(a, b, 10);
    }

    if (rbuttonDown){
        glClear(GL_COLOR_BUFFER_BIT);
    }
}


// Display function
void myDisplay() {
    draw_pixel(a, b);
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
    glutMainLoop();
}

