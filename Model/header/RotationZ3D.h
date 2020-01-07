//
// Created by Schirmann on 01/10/2019.
//

#ifndef ROTATIONZ3D_H_
#define ROTATIONZ3D_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"

class RotationZ3D : public Figure3D{
public:
    Figure3D *f;
    float angle;

    RotationZ3D(Figure3D *fig, float teta);

    bool dedans(float x, float y, float z);
};

#endif