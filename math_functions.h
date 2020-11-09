#include <iostream>
#include <math.h>

using namespace std;

int dist(int a, int b, int x, int y){
    int r;
    a = a*a;
    b = b*b;
    x = x*x;
    y = y*y;

    r = (a + b) - (x + y);
    r = sqrt(r);
    return r;
}
