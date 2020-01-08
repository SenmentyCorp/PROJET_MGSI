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

    glEnable(GL_DEPTH_TEST);
    
    glPushMatrix();
        glRotatef(M_PI, 0, 1, 0); 

        //ROUE 1
        glPushMatrix();
            glColor3f(0.43f, 0.34f, 0.35f);
            glTranslatef(this->longueurTrain*(-0.7f/2.0f), 0, this->largeurTrain*(-0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 2
        glPushMatrix();
            glColor3f(0.43f, 0.34f, 0.35f);
            glTranslatef(this->longueurTrain*(-0.7f/2.0f), 0, this->largeurTrain*(0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 3
        glPushMatrix();
            glColor3f(0.43f, 0.34f, 0.35f);
            glTranslatef(this->longueurTrain*(0.7f/2.0f), 0, this->largeurTrain*(-0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 4
        glPushMatrix();
            glColor3f(0.43f, 0.34f, 0.35f);
            glTranslatef(this->longueurTrain*(0.7f/2.0f), 0, this->largeurTrain*(0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //PORTE 1
        glPushMatrix();
            glColor3f(0.46f, 0.27f, 0.21f);
            glTranslatef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(5.2f/10.0f), this->largeurTrain*(5.2f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //PORTE 2
        glPushMatrix();
            glColor3f(0.46f, 0.27f, 0.21f);
            glTranslatef(this->longueurTrain*(-1.5f/10.0f), this->hauteurTrain*(5.2f/10.0f), this->largeurTrain*(5.2f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //CORPS
        glPushMatrix();
            glColor3f(0.45f, 0.17f, 0.05f);
            glTranslatef(0, this->hauteurTrain*(5.0f/10.0f), 0);
            glScalef(this->longueurTrain, this->hauteurTrain*(9.0f/10.0f), this->largeurTrain);
            glutSolidCube(1);
        glPopMatrix();   
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