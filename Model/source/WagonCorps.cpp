#include "../header/WagonCorps.h"


WagonCorps::WagonCorps() : Figure3D(){
    this->figWagCorps = new Cube;
    this->figWagCorps = new Scale3D(this->figWagCorps, 0.56, 0.31, 0.21);
    
    Figure3D* trouCorps = new Cube;
    trouCorps = new Scale3D(trouCorps, 0.50, 0.25, 0.15);
    trouCorps = new Translation3D(trouCorps, 0.03, 0.07, 0.03);

    this->figWagCorps = new Difference3D(this->figWagCorps, trouCorps);
}

bool WagonCorps::dedans(float x, float y, float z){
    return this->figWagCorps->dedans(x,y,z);
}
