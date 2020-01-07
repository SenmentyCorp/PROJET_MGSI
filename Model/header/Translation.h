//
// Created by Alex-PC on 23/09/2019.
//
#ifndef TRANSLATION_H_
#define TRANSLATION_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure.h"

class Translation : public Figure{
public:
    Figure *fig;
    float tx, ty;
    Translation(Figure *f, float x, float y);
    
    bool dedans(float x, float y);
};

#endif