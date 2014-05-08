#include <cmath>
#include "fk.h"
#include "ik.h"

void polar2cart(float r, float theta, float& a, float& b)
{
    a = r * cos(theta);
    b = r * sin(theta);
}

void unsolve(float a0, float a1, float a2, float& x, float& y, float& z)
{
    // Calculate u,v coords for arm
    float u01, v01, u12, v12;
    polar2cart(L1, a1, u01, v01);
    polar2cart(L2, a2, u12, v12);

    // Add vectors
    float u, v;
    u = u01 + u12 + L3;
    v = v01 + v12;

    // Calculate in 3D space - note x/y reversal!
    polar2cart(u, a0, y, x);
    z = v;
}

float distance(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float dx = x2-x1;
    float dy = y2-y1;
    float dz = z2-z1;

    return dx*dx + dy*dy + dz*dz;
}
