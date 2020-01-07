//
// Created by Schirmann on 01/10/2019.
//

#include "../header/RotationY3D.h"

RotationY3D::RotationY3D(Figure3D *fig, float teta) : Figure3D(){
    this->f = fig;
    this->angle = teta;
}

bool RotationY3D::dedans(float x, float y, float z){
    return this->f->dedans(x*cos(angle) + y*sin(angle), y, y*cos(angle) - x*sin(angle));
}