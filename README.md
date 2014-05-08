me-arm-ik
=========

IK solver for phenoptix's Me Arm

This code is provided under the terms of the MIT license.  See the license section below for the full text.

Files
=====
ik.h      Prototypes for IK functions and extern defs for arm geometry

ik.cpp    Definition of IK functions and arm geometry defaults

main.cpp  Simple test program to verify operation

Functions
=========
void cart2polar(float a, float b, float& r, float& theta)

Convert 2D cartesian coordinates into polar coordinates.

This function always sets r, but will not set theta if r is zero.
r is in the same units as a and b;
theta is in radians and is set in the range -PI < theta <= PI

bool cosangle(float opp, float adj1, float adj2, float& theta)

Determine angle of a triangle using the cosine rule.
opp is the length of the opposite side; adj1 and adj2 are the lengths of the adjacent sides.

theta is set and the function returns true if successful

theta is not set and the function returns false if unsuccessful

bool solve(float x, float y, float z, float& a0, float& a1, float& a2)

Solve arm angles for given x, y, z position of grab centre.
x, y and z must be in the same units as the globals L1, L2 and L3.
a0, a1, a2 are in radians.
The origin is defined as a point directly above the rotating base,
at the height of the main shoulder pivot.
The x axis points directly to the right of the arm.
The y axis points directly forwards.
The z axis points directly upwards.
The coordinate system is therefore right handed.

Looking downwards, a0 is the angle clockwise from the y axis direction, and can be in the range -PI < a0 < PI

Looking at the right side of the arm, a1 is the angle of inclination of the first arm section, and
a2 is the angle of inclination of the second arm section.

a0, a1, a2 are all set and the function returns true if successful

None of a0, a1, a2 are set and the function returns false if unsuccessful

Globals
=======
extern float L1, L2, L3;

L1 is the length of the first arm section, from the bottom servo horn to the main elbow pivot.

L2 is the length of the second arm section, from the main elbow pivot to the wrist pivot.

L3 is the sum of two horizontal distances:
 - the distance between the centre of grab and the wrist pivot
 - the horizontal distance forward between the centre of rotation of the base and the lower pivot of the first arm
 
At present, the global settings are just guesses as I've not looked at the geometry.

License
=======
This code is provided under the terms of the MIT license.

The MIT License (MIT)

Copyright (c) 2014 Nick Moriarty

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
