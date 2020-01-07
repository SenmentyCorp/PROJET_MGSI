//
// Created by Alex-PC on 23/09/2019.
//
#ifndef ROTATIONX3D_H_
#define ROTATIONX3D_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"

class RotationX3D : public Figure3D{
public:
    Figure3D *f;
    float angle;

    RotationX3D(Figure3D *fig, float teta);

    bool dedans(float x, float y, float z);
};

#endif