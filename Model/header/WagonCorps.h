#ifndef WAGONCORPS_H_
#define WAGONCORPS_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"
#include "../header/Cube.h"
#include "../header/Scale3D.h"
#include "../header/Difference3D.h"
#include "../header/Translation3D.h"

class WagonCorps : public Figure3D{
public:
    WagonCorps();
    bool dedans(float x, float y, float z);

private:
    Figure3D* figWagCorps;
};

#endif