#include "../header/Cercle.h"

Cercle::Cercle() : Figure(){

}

bool Cercle::dedans(float x, float y){
    return (1-pow(x,2)-pow(y,2) >= 0);
}
