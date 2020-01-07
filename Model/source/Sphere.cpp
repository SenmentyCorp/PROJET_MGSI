//
// Created by Schirmann on 01/10/2019.
//

#include "../header/Sphere.h"

Sphere::Sphere() : Figure3D(){

}

bool Sphere::dedans(float x, float y, float z){
    return (1-pow(x,2)-pow(y,2)-pow(z,2) >= 0);
}
