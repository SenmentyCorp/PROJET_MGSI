//
// Created by Schirmann on 01/10/2019.
//

#ifndef MENGERTROUE_H_
#define MENGERTROUE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"
#include "Difference3D.h"

#include "Translation3D.h"
#include "Scale3D.h"
#include "Union3D.h"

class MengerTroue : public Figure3D{
public:
    MengerTroue();
    bool dedans(float x, float y, float z);

private:
    Difference3D *i2;
};

#endif
