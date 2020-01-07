//
// Created by Alex-PC on 23/09/2019.
//
#ifndef DIFF3D_H_
#define DIFF3D_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"

class Difference3D : public Figure3D{
public:
    Figure3D *f1, *f2;
    Difference3D(Figure3D *a, Figure3D *b);
    
    bool dedans(float x, float y, float z);
};

#endif