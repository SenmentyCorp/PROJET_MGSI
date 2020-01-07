#include "../header/Rotation.h"

Rotation::Rotation(Figure *fig, float teta) : Figure(){
    this->f = fig;
    this->angle = teta;
}

bool Rotation::dedans(float x, float y){
    return this->f->dedans(x*cos(angle) + y*sin(angle) , y*cos(angle) - x*sin(angle));
}