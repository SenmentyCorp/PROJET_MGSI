//
// Created by Alex-PC on 23/09/2019.
//
#ifndef CERCLE_H_
#define CERCLE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure.h"

class Cercle : public Figure{
public:
    Cercle();
    bool dedans(float x, float y);
};

#endif