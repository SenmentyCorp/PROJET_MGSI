//
// Created by Alex-PC on 23/09/2019.
//
#ifndef SCALE_H_
#define SCALE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure.h"

class Scale : public Figure{
public:
    Figure *fig;
    float tx, ty;
    Scale(Figure *f, float x, float y);
    bool dedans(float x, float y);
};

#endif