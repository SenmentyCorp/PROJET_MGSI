//
// Created by Schirmann on 01/10/2019.
//

#include "../header/Difference3D.h"

Difference3D::Difference3D(Figure3D *a, Figure3D *b){
    f1 = a;
    f2 = b;
}

bool Difference3D::dedans(float x, float y, float z){
    return f1->dedans(x,y,z) && !f2->dedans(x,y,z);
}
