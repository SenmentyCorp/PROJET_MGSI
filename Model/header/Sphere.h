//
// Created by Alex-PC on 23/09/2019.
//
#ifndef SPHERE_H_
#define SPHERE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"

class Sphere : public Figure3D{
public:
    Sphere();
    bool dedans(float x, float y, float z);
};

#endif