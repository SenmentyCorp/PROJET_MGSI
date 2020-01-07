//
// Created by Alex-PC on 23/09/2019.
//
#ifndef DEMI_PLAN_H_
#define DEMI_PLAN_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure.h"

class DemiPlan : public Figure{
public:
    DemiPlan();
    bool dedans(float x, float y);
};

#endif