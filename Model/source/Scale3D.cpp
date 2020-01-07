//
// Created by Schirmann on 01/10/2019.
//

#include "../header/Scale3D.h"

Scale3D::Scale3D(Figure3D *f, float x, float y, float z){
    this->fig = f;
    this->tx = x;
    this->ty = y;
    this->tz = z;
}

bool Scale3D::dedans(float x, float y, float z){
    return (fig->dedans(x/tx, y/ty, z/tz));
}
