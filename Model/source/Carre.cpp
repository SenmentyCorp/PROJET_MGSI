#include "../header/Carre.h"

Carre::Carre() : Figure(){

}

bool Carre::dedans(float x, float y){
    return (0.<=x && x<=1. && 0.<=y && y<=1.);
}