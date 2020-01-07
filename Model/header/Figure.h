#ifndef FIGURE_H_
#define FIGURE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

class Figure{
    public:
        Figure();
        virtual bool dedans(float x, float y)=0;
        void trace();
};

#endif