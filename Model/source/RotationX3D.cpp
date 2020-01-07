//
// Created by Schirmann on 01/10/2019.
//

#include "../header/RotationX3D.h"

RotationX3D::RotationX3D(Figure3D *fig, float teta) : Figure3D(){
    this->f = fig;
    this->angle = teta;
}

bool RotationX3D::dedans(float x, float y, float z){
    return this->f->dedans(x, x*cos(angle) + y*sin(angle) , y*cos(angle) - x*sin(angle));
}