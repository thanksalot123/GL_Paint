#pragma once
extern int x1, y01, x2, y2;

extern bool l_b;
extern int a;
extern int b;

extern int c;
extern int d;

extern float R;
extern float G;
extern float B;

extern int counter;

extern bool hollow;

extern int size_brush;


extern bool lbuttonDown;
extern bool rbuttonDown;

enum menu_type : unsigned char
{
    circle, square, triangle, line, eraser
};

extern int shape[];

extern int option;