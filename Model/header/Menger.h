//
// Created by Schirmann on 01/10/2019.
//

#ifndef MENGER_H_
#define MENGER_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"

class Menger : public Figure3D {
public:
    Menger(float posX, float posY, float posZ, float longueur, int degre);
    bool dedans(float x, float y, float z);

private:
    Figure3D *t1;

};

#endif
