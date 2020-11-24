#include <GL/glut.h>
#include "shapes.h"
#include "variables.h"

//i sawed these functions in half!!!

void drawPallete()
{
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(50, 0);
    glVertex2f(50, 50);
    glVertex2f(0, 50);
    glEnd();
}

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
        else if (hollow && option != shape[line])
            shapes->drawHollow();
        else shapes->drawShape();
    
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