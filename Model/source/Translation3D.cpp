#include "../header/Translation3D.h"

Translation3D::Translation3D(Figure3D *f, float x, float y, float z){
    this->fig = f;
    this->tx = x;
    this->ty = y;
    this->tz = z;
}

bool Translation3D::dedans(float x, float y, float z){
    return (fig->dedans(x-tx, y-ty, z-tz));
}
