//
// Created by Schirmann on 01/10/2019.
//

#include "../header/RotationZ3D.h"

RotationZ3D::RotationZ3D(Figure3D *fig, float teta) : Figure3D(){
    this->f = fig;
    this->angle = teta;
}

bool RotationZ3D::dedans(float x, float y, float z){
    return this->f->dedans(x*cos(angle) + y*sin(angle) , y*cos(angle) - x*sin(angle), z);
}