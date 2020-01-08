#include "../header/WagonBetail.h"

WagonBetail::WagonBetail(){
    this->direction.x=0;
    this->direction.y=0;
    this->direction.z=0;

    this->position.x=0;
    this->position.y=0;
    this->position.z=0;
}

void WagonBetail::assembler(){
    
    glPushMatrix();
        glColor3f(0.5f, 0.17f, 0.05f);
        glScalef(this->longueurTrain, this->hauteurTrain*(9.0f/10.0f), this->largeurTrain);
        glTranslatef(0, this->hauteurTrain*(0.5f/10.0f), 0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.43f, 0.34f, 0.35f);
        glScalef(this->hauteurTrain*(1.0f/10.0f), this->hauteurTrain*(1.0f/10.0f), 0.4);
        glTranslatef(this->largeurTrain, 0, this->longueurTrain*(0.5f/10.0f));
        glutSolidSphere(1, 24, 24);
    glPopMatrix();
    
}

void WagonBetail::dessiner(){
    
}

void WagonBetail::deplacer(float x, float y, float z){

}

void WagonBetail::orienter(float x, float y, float z){

}

        
Vecteur WagonBetail::getMilieuRouesAvant(){
    return this->direction;
}

Vecteur WagonBetail::getMilieuRouesArriere(){
    return this->direction;
}

float WagonBetail::getLongueurTrain(){

}

float WagonBetail::getLargeurTrain(){

}