//
// Created by Alex-PC on 23/09/2019.
//
#ifndef UNION_H_
#define UNION_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure.h"

class Union : public Figure{
public:
    Figure *f1, *f2;
    Union(Figure *a, Figure *b);
    
    bool dedans(float x, float y);
};

#endif