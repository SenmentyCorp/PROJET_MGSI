//
// Created by Alex-PC on 23/09/2019.
//
#ifndef TRANSLATION3D_H_
#define TRANSLATION3D_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"

class Translation3D : public Figure3D{
public:
    Figure3D *fig;
    float tx, ty, tz;
    Translation3D(Figure3D *f, float x, float y, float z);
    
    bool dedans(float x, float y, float z);
};

#endif