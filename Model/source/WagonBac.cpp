#include "../header/WagonBac.h"


WagonBac::WagonBac() : Figure3D(){
    this->figWagBac = new Cube;
    this->figWagBac = new Scale3D(this->figWagBac, 0.50, 0.25, 0.15);
    this->figWagBac = new Translation3D(this->figWagBac, 0.03, 0.07, 0.03);

    Figure3D* trouBenne = new Cube;
    trouBenne = new Scale3D(trouBenne, 0.46, 0.21, 0.11);
    trouBenne = new Translation3D(trouBenne, 0.05f, 0.09f, 0.05f);

    this->figWagBac = new Difference3D(this->figWagBac, trouBenne);
}

bool WagonBac::dedans(float x, float y, float z){
    return this->figWagBac->dedans(x,y,z);
}