
// Created by Schirmann on 01/10/2019.
//

#include "../header/Menger.h"
#include "../header/Translation3D.h"
#include "../header/Scale3D.h"
#include "../header/MengerTroue.h"


Menger::Menger(float posX, float posY, float posZ, float longueur, int degre) : Figure3D(){
}

bool Menger::dedans(float x, float y, float z){
    return (1-pow(x,2)-pow(y,2)-pow(z,2) >= 0);
}