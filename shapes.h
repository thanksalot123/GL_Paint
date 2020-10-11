#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void dda_circle (int x,int y,int R)
{
    float x1,x2,y1,y2,epsilon,sx,sy;
    int value,i = 0;
    x1 = R; y1 = 0; sx = x1; sy = y1;

    do{
            value = pow(2,i);
            i++;
    } while ( value < R );

    epsilon = 1/pow(2,i-1);

    do{
      x2 = x1 + y1*epsilon;
      y2 = y1 - epsilon*x2;

      glBegin(GL_POINTS);
      glVertex2i(x + x2, y + y2);
      glEnd();
      glFlush();

      x1 = x2;
      y1 = y2;

     } while ( (y1 - sy) < epsilon || ( sx - x1 ) > epsilon );
     glFlush();
}
