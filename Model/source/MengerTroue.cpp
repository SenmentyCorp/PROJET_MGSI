//
// Created by Schirmann on 01/10/2019.
//

#include "../header/MengerTroue.h"
#include "../header/Cube.h"
#include "../header/Translation3D.h"
#include "../header/Difference3D.h"
#include "../header/Scale3D.h"

MengerTroue::MengerTroue(){

    //Triangle Principal non troué
    Cube *cP = new Cube;
    Cube *cX = new Cube;
    Cube *cY = new Cube;
    Cube *cZ = new Cube;

    Scale3D *sX = new Scale3D(cX, 1, 0.33, 0.33);
    Scale3D *sY = new Scale3D(cY, 0.33, 1, 0.33);
    Scale3D *sZ = new Scale3D(cZ, 0.33, 0.33, 1);

    Translation3D *tX = new Translation3D(sX, 0, 0.33, 0.33);
    Translation3D *tY = new Translation3D(sY, 0.33, 0, 0.33);
    Translation3D *tZ = new Translation3D(sZ, 0.33, 0.33, 0);

    Difference3D *d1 = new Difference3D(cP, tX);
    Difference3D *d2 = new Difference3D(d1, tY);
    i2 = new Difference3D(d2, tZ);

}

bool MengerTroue::dedans(float x, float y, float z){
    return i2->dedans(x, y, z);
}

