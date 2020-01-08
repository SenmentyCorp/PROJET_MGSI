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

        glTranslatef(this->position.x, this->position.y, this->position.z);
        glTranslatef(this->longueurTrain*(0.7f/2.0f), this->hauteurTrain*(1.5f/10.0f), 0);
        //ROUE 1
        glPushMatrix();
            glColor3f(0.33f, 0.24f, 0.25f);
            glTranslatef(this->longueurTrain*(-0.7f/2.0f), 0, this->largeurTrain*(-0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 2
        glPushMatrix();
            glColor3f(0.33f, 0.24f, 0.25f);
            glTranslatef(this->longueurTrain*(-0.7f/2.0f), 0, this->largeurTrain*(0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 3
        glPushMatrix();
            glColor3f(0.33f, 0.24f, 0.25f);
            glTranslatef(this->longueurTrain*(0.7f/2.0f), 0, this->largeurTrain*(-0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 4
        glPushMatrix();
            glColor3f(0.33f, 0.24f, 0.25f);
            glTranslatef(this->longueurTrain*(0.7f/2.0f), 0, this->largeurTrain*(0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //PORTE 1
        glPushMatrix();
            glColor3f(0.46f, 0.27f, 0.21f);
            glTranslatef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(5.2f/10.0f), this->largeurTrain*(4.5f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //PORTE 2
        glPushMatrix();
            glColor3f(0.46f, 0.27f, 0.21f);
            glTranslatef(this->longueurTrain*(-1.5f/10.0f), this->hauteurTrain*(5.2f/10.0f), this->largeurTrain*(4.5f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //PORTE 3
        glPushMatrix();
            glColor3f(0.46f, 0.27f, 0.21f);
            glTranslatef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(5.2f/10.0f), this->largeurTrain*(-4.5f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //PORTE 4
        glPushMatrix();
            glColor3f(0.46f, 0.27f, 0.21f);
            glTranslatef(this->longueurTrain*(-1.5f/10.0f), this->hauteurTrain*(5.2f/10.0f), this->largeurTrain*(-4.5f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //ATTACHE 1 
        glPushMatrix();
            glColor3f(0.27f, 0.27f, 0.27f);
            glTranslatef(this->longueurTrain*(5.0f/10.0f), this->hauteurTrain*(3.0f/10.0f), this->largeurTrain*(-2.5f/10.0f));
            glScalef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //ATTACHE 2 
        glPushMatrix();
            glColor3f(0.27f, 0.27f, 0.27f);
            glTranslatef(this->longueurTrain*(5.0f/10.0f), this->hauteurTrain*(3.0f/10.0f), this->largeurTrain*(2.5f/10.0f));
            glScalef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //ATTACHE 3
        glPushMatrix();
            glColor3f(0.27f, 0.27f, 0.27f);
            glTranslatef(this->longueurTrain*(-5.0f/10.0f), this->hauteurTrain*(3.0f/10.0f), this->largeurTrain*(-2.5f/10.0f));
            glScalef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //ATTACHE 4
        glPushMatrix();
            glColor3f(0.27f, 0.27f, 0.27f);
            glTranslatef(this->longueurTrain*(-5.0f/10.0f), this->hauteurTrain*(3.0f/10.0f), this->largeurTrain*(2.5f/10.0f));
            glScalef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(2.0f/10.0f));
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

void WagonBetail::deplacer(float x, float y, float z){
    this->position.x=x;
    this->position.y=y;
    this->position.z=z;
}

void WagonBetail::orienter(float x, float y, float z){

}

        
Vecteur WagonBetail::getMilieuRouesAvant(){
    return this->direction;
}

float WagonBetail::getLongueurRouePrevRoueSuiv(){
    return this->longueurTrain+this->longueurTrain*(1.5f/10.0f);
}
