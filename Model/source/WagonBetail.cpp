#include "../header/WagonBetail.h"

WagonBetail::WagonBetail(){
    this->direction.x=0;
    this->direction.y=0;
    this->direction.z=0;

    this->position.x=0;
    this->position.y=0;
    this->position.z=0;

    this->largeurTrain=10;
    this->longueurTrain=31.25;
    this->hauteurTrain=12.5;
}

void WagonBetail::assembler(){
    
    glPushMatrix();


        glTranslatef(this->position.x, this->position.y, this->position.z);
        glTranslatef(this->longueurTrain*(0.7f/2.0f), this->hauteurTrain*(1.5f/10.0f), 0);

        //glPushMatrix();
        glRotatef(this->direction.z, 0, 0, 1);
        glRotatef(this->direction.y, 0, 1, 0);
        glRotatef(this->direction.x, 1, 0, 0);


        //ROUE 1
        glPushMatrix();
            glColor3f(0.08f, 0.08f, 0.08f);
            glTranslatef(this->longueurTrain*(-0.7f/2.0f), 0, this->largeurTrain*(-0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 2
        glPushMatrix();
            glColor3f(0.08f, 0.08f, 0.08f);
            glTranslatef(this->longueurTrain*(-0.7f/2.0f), 0, this->largeurTrain*(0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 3
        glPushMatrix();
            glColor3f(0.08f, 0.08f, 0.08f);
            glTranslatef(this->longueurTrain*(0.7f/2.0f), 0, this->largeurTrain*(-0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 4
        glPushMatrix();
            glColor3f(0.08f, 0.08f, 0.08f);
            glTranslatef(this->longueurTrain*(0.7f/2.0f), 0, this->largeurTrain*(0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //PORTE 1
        glPushMatrix();
            glColor3f(0.30f, 0.0f, 0.0f);
            glTranslatef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(5.2f/10.0f), this->largeurTrain*(4.5f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //PORTE 2
        glPushMatrix();
            glColor3f(0.30f, 0.0f, 0.0f);
            glTranslatef(this->longueurTrain*(-1.5f/10.0f), this->hauteurTrain*(5.2f/10.0f), this->largeurTrain*(4.5f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //PORTE 3
        glPushMatrix();
            glColor3f(0.30f, 0.0f, 0.0f);
            glTranslatef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(5.2f/10.0f), this->largeurTrain*(-4.5f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //PORTE 4
        glPushMatrix();
            glColor3f(0.30f, 0.0f, 0.0f);
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
            glColor3f(0.04f, 0.04f, 0.04f);
            glTranslatef(0, this->hauteurTrain*(5.0f/10.0f), 0);
            glScalef(this->longueurTrain, this->hauteurTrain*(9.0f/10.0f), this->largeurTrain);
            glutSolidCube(1);
        glPopMatrix(); 
        //glPopMatrix();  

    glPopMatrix();
    
}

void WagonBetail::deplacer(float x, float y, float z){
    this->position.x=x;
    this->position.y=y;
    this->position.z=z;
}

void WagonBetail::orienter(float x, float y, float z){
    this->direction.x=x;
    this->direction.y=y;
    this->direction.z=z;
}

        
Vecteur WagonBetail::getMilieuRouesAvant(){
    return this->direction;
}

float WagonBetail::getLongueurRouePrevRoueSuiv(){
    return this->longueurTrain+this->longueurTrain*(1.5f/10.0f);
}
