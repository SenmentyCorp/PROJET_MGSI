//
// Created by Alex-PC on 01/10/2019.
//

#ifndef ANIMATIONGL2_TRIANGLERECURSIF_H
#define ANIMATIONGL2_TRIANGLERECURSIF_H


#include "Figure.h"
#include "TriangleTroue.h"
#include "Scale.h"

class TriangleRecursif : public Figure {
public:
    TriangleRecursif(float posX, float posY, float longueur, int degre);
    bool dedans(float x, float y);

private:
    Figure *t1;

    Figure* buildRecursif(float x, float y, float longueur, int degre);
};


#endif //ANIMATIONGL2_TRIANGLERECURSIF_H
