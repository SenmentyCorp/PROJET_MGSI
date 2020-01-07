//
// Created by Alex-PC on 23/09/2019.
//

#ifndef CUBE_H_
#define CUBE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"

class Cube : public Figure3D{
public:
    Cube();
    bool dedans(float x, float y, float z);
};

#endif