// Import libraries
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

#include "math_functions.h"
#include "brushes.h"
#include "shapes.h"
#include "buttons.h"

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


// Keyboard input functions
// {{{
void keyboard(unsigned char Key, int x, int y){
    if(Key=='x'){
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
        cout << "Clear Screen!" << endl;
    }
}
// }}}

// Mouse input functions
// {{{
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            rbuttonDown = true;
            glutPostRedisplay();

        }
        else if (state == GLUT_UP)
            rbuttonDown = false;
    }
    else if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN)
        {
            lbuttonDown = true;
            glutPostRedisplay();
        }
        else if (state == GLUT_UP)
            lbuttonDown = false;
    }
}

void motion(int x, int y)
{
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
/// }}}

// Function to draw pixels
void draw_pixel() {
    if (lbuttonDown){
        TriBrush(a, b, 50);
    }

    if (rbuttonDown){
        glClear(GL_COLOR_BUFFER_BIT);
    }
}


// Display function
void myDisplay() {
    draw_pixel();
    glFlush();
}


// The main function
int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutPassiveMotionFunc(motionPassive);
    myInit();
    glutMainLoop();
}

