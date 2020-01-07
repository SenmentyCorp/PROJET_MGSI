#include "../header/Scale.h"

Scale::Scale(Figure *f, float x, float y){
    this->fig = f;
    this->tx = x;
    this->ty = y;
}

bool Scale::dedans(float x, float y){
    return (fig->dedans(x/tx, y/ty));
}
