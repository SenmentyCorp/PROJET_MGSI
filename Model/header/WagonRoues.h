#ifndef WAGONROUES_H_
#define WAGONROUES_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Figure3D.h"
#include "../header/Sphere.h"
#include "../header/Cube.h"
#include "../header/Scale3D.h"
#include "../header/Difference3D.h"
#include "../header/Translation3D.h"
#include "../header/Intersection3D.h"
#include "../header/Union3D.h"

class WagonRoues : public Figure3D{
public:
    WagonRoues();
    bool dedans(float x, float y, float z);

private:
    Figure3D* figWagRoues;
};

#endif