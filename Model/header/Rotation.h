//
// Created by Alex-PC on 23/09/2019.
//
#ifndef ROTATION_H_
#define ROTATION_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure.h"

class Rotation : public Figure{
public:
    Figure *f;
    float angle;

    Rotation(Figure *fig, float teta);

    bool dedans(float x, float y);
};

#endif