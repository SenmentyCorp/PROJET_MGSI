#ifndef FIGURE3D_H_
#define FIGURE3D_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

class Figure3D{
    public:
        Figure3D();
        virtual bool dedans(float x, float y, float z)=0;
        void trace();
        void trace(float r, float g, float b);
};

#endif