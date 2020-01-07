#include "../header/Union.h"

Union::Union(Figure *a, Figure *b){
    f1 = a;
    f2 = b;
}

bool Union::dedans(float x, float y){
    return f1->dedans(x,y) || f2->dedans(x,y);
}
