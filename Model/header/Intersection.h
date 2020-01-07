//
// Created by Alex-PC on 23/09/2019.
//
#ifndef INTERSECTION_H_
#define INTERSECTION_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure.h"

class Intersection : public Figure{
public:
    Figure *f1, *f2;
    Intersection(Figure *a, Figure *b);
    
    bool dedans(float x, float y);
};

#endif