//
// Created by Schirmann on 01/10/2019.
//
#ifndef INTERSECTION3D_H_
#define INTERSECTION3D_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"

class Intersection3D : public Figure3D{
public:
    Figure3D *f1, *f2;
    Intersection3D(Figure3D *a, Figure3D *b);

    bool dedans(float x, float y, float z);
};

#endif