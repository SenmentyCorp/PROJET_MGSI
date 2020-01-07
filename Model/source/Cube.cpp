//
// Created by Schirmann on 01/10/2019.
//

#include "../header/Cube.h"

Cube::Cube() : Figure3D(){

}

bool Cube::dedans(float x, float y, float z){
    return (0.<=x && x<=1. && 0.<=y && y<=1. && 0.<=z && z<=1.);
}