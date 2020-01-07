//
// Created by Alex-PC on 01/10/2019.
//

#ifndef ANIMATIONGL2_TRIANGLETROUE_H
#define ANIMATIONGL2_TRIANGLETROUE_H

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure.h"
#include "DemiPlan.h"
#include "Rotation.h"
#include "Translation.h"
#include "Intersection.h"
#include "Difference.h"
#include "Union.h"

class TriangleTroue : public Figure{
public:
    TriangleTroue();
    bool dedans(float x, float y);

private:
    DemiPlan *dp1, *dp2, *dp2Bis, *dp3, *dp4, *dp5;

    Rotation *r1, *r2, *r3, *r4;

    Translation *t1, *t2, *t3, *t4, *t5;

    Intersection *i1, *i2;

    Union *u1;
};

#endif //ANIMATIONGL2_TRIANGLETROUE_H
