//
// Created by Schirmann on 01/10/2019.
//

#ifndef ROTATIONY3D_H_
#define ROTATIONY3D_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"

class RotationY3D : public Figure3D{
public:
    Figure3D *f;
    float angle;

    RotationY3D(Figure3D *fig, float teta);

    bool dedans(float x, float y, float z);
};

#endif