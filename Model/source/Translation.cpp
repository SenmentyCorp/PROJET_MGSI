#include "../header/Translation.h"

Translation::Translation(Figure *f, float x, float y){
    this->fig = f;
    this->tx = x;
    this->ty = y;
}

bool Translation::dedans(float x, float y){
    return (fig->dedans(x-tx, y-ty));
}
