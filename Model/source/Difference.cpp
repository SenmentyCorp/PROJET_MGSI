#include "../header/Difference.h"

Difference::Difference(Figure *a, Figure *b){
    f1 = a;
    f2 = b;
}

bool Difference::dedans(float x, float y){
    return f1->dedans(x,y) && !f2->dedans(x,y);
}
