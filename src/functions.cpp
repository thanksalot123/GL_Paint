#include<GL/glut.h>
#include "shapes.h"
#include "variables.h"

//i sawed these functions in half!!!

void SetColor()
{
    glColor3f(0.0,0.0,0.0);
}

void pallete()
{
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(50, 0);
    glVertex2f(50, 50);
    glVertex2f(0, 50);
    glEnd();
}


void keyboard(unsigned char Key, int x, int y) {
    if (Key == 'x') {
        glClear(GL_COLOR_BUFFER_BIT);
        glutPostRedisplay();
    }
    else if (Key == '+' && size_brush > 0)
    {
        size_brush++;
        glutPostRedisplay();   
    }
    else if (Key == '-' && size_brush > 1)
    {
        size_brush--;
        glutPostRedisplay();
    }
    else if (Key == 'r' && R < 0.9)
    {
        R+=0.1;
        glColor3f(R, G, B);
        glutPostRedisplay();
    }
    else if (Key == 'b' && B < 0.9)
    {
        B+=0.1;
        glColor3f(R, G, B);
        glutPostRedisplay();
    }
    else if (Key == 'g' && G < 0.9)
    {
        G+=0.1;
        glColor3f(R, G, B);
        glutPostRedisplay();
    }
    else if (Key == '1')
    {
        R = 1;
        G = 0;
        B = 0;
        glColor3f(R, G, B);
        glutPostRedisplay();

    }
    else if (Key == '2')
    {
        R = 0;
        G = 0;
        B = 1;
        glColor3f(R, G, B);
        glutPostRedisplay();

    }
    else if (Key == '3')
    {
        R = 0;
        G = 1;
        B = 0;
        glColor3f(R, G, B);
        glutPostRedisplay();

    }
    else if (Key == '4')
    {
        R = 1;
        G = 0;
        B = 1;
        glColor3f(R, G, B);
        glutPostRedisplay();

    }
    else if (Key == '5')
    {
        R = 0;
        G = 1;
        B = 1;
        glColor3f(R, G, B);
        glutPostRedisplay();

    }
    else if (Key == '6')
    {
        R = 1;
        G = 1;
        B = 0;
        glColor3f(R, G, B);
        glutPostRedisplay();

    }
    else if (Key == '0')
    {
        R = 0;
        G = 0;
        B = 0;
        glColor3f(R, G, B);
        glutPostRedisplay();

    }
    else if (Key == 'R' && R > 0)
    {
        R -= 0.1;
        glColor3f(R, G, B);
        glutPostRedisplay();
    }
    else if (Key == 'B' && B > 0)
    {
        B -= 0.1;
        glColor3f(R, G, B);
        glutPostRedisplay();
    }
    else if (Key == 'G' && G > 0)
    {
        G -= 0.1;
        glColor3f(R, G, B);
        glutPostRedisplay();
    }
    else if (Key == 'h')
    {
        hollow = true;

    }
    else if (Key == 'f')
    {
        hollow = false;
    }

}

// Mouse input functions
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
    b = y;
    glutPostRedisplay();
}

void motionPassive(int x, int y)
{
    c = a;
    d = b;
    a = x;
    b = y;
    glutPostRedisplay();
}



// Function to draw pixels
void draw_pixel() {

    brushshapes* shapes = new circlebrush(a, b, 5);
    if (lbuttonDown) {
        if (option == shape[circle])
            shapes = new circlebrush(a, b, size_brush);
        else if (option == shape[square])
            shapes = new squarebrush(a, b, size_brush);
        else if (option == shape[triangle])
            shapes = new trianglebrush(a, b, size_brush);
        else if (option == shape[eraser])
        {
            glColor3f(1.0, 1.0, 1.0);
            shapes = new squarebrush(a, b, size_brush);
        }
        else
            shapes = new circlebrush(a, b, 5);       
        

        if (!hollow)
            shapes->drawShape();
        else shapes->drawHollow();
    }

    if (rbuttonDown) {
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

void menu(int value)
{
    option = value;
    value == shape[eraser] ? glColor3f(1.0, 1.0, 1.0) : glColor3f(R, G, B);
}

void gllmenu()
{
    glutCreateMenu(menu);

    glutAddMenuEntry("Circle", shape[circle]);
    glutAddMenuEntry("square", shape[square]);
    glutAddMenuEntry("triangle", shape[triangle]);
    glutAddMenuEntry("line", shape[line]);
    glutAddMenuEntry("eraser", shape[eraser]);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

}


