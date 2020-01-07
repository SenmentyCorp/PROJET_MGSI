#include "../header/Union3D.h"

Union3D::Union3D(Figure3D *a, Figure3D *b){
    f1 = a;
    f2 = b;
}

bool Union3D::dedans(float x, float y, float z){
    return f1->dedans(x,y,z) || f2->dedans(x,y,z);
}
