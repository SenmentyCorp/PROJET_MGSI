#include "../header/WagonRoues.h"


WagonRoues::WagonRoues() : Figure3D(){
    this->figWagRoues = new Sphere;

    Figure3D* coupe = new Cube;
    coupe = new Scale3D(coupe, 2.5, 2.5, 1.0);
    coupe = new Translation3D(coupe, 0.0, 0.0, 1.3);
    this->figWagRoues = new Translation3D(this->figWagRoues, 1.0, 1.0, 1.0);
    
    this->figWagRoues = new Difference3D(this->figWagRoues, coupe);

    this->figWagRoues = new Scale3D(this->figWagRoues, 0.2, 0.2, 0.2);
}

bool WagonRoues::dedans(float x, float y, float z){
    return this->figWagRoues->dedans(x,y,z);
}