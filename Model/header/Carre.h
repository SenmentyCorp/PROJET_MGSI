//
// Created by Alex-PC on 23/09/2019.
//

#ifndef CARRE_H_
#define CARRE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure.h"

class Carre : public Figure{
public:
    Carre();
    bool dedans(float x, float y);
};

#endif