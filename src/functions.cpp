#include <GL/glut.h>
#include "shapes.h"
#include "variables.h"

//i sawed these functions in half!!!
static brushshapes* shapes = new circlebrush();

void drawPallete()
{
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(50, 0);
    glVertex2f(50, 50);
    glVertex2f(0, 50);
    glEnd();
}

void draw_pixel() 
{
    if (lbuttonDown)
    {
        if (option == shape[line])
        {
            shapes->drawShape(a, b, 5);
        }
        else if (hollow && option != shape[eraser])
        {
            shapes->drawHollow(a, b, size_brush);
        }
        else
        {         
            shapes->drawShape(a, b, size_brush);
        }
    }
}

void setShape(brushshapes* object, int option)
{
    if (option == shape[square])
    {
        shapes = new squarebrush();
    }
    else if (option == shape[triangle])
    {
        shapes = new trianglebrush();
    }
    else if (option == shape[eraser])
    {
        shapes = new squarebrush();
    }
    else
    {
        shapes = new circlebrush();
    }
}

void menu(int value)
{
    option = value;
    value == shape[eraser] ? glColor3f(1.0, 1.0, 1.0) : glColor3f(R, G, B);
    //to delete the previos heap allocated memory
    delete shapes;
    shapes = nullptr;
    setShape(shapes, option);
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