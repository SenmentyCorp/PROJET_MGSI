#include "../header/Locomotive.h"

Locomotive::Locomotive(){
    this->direction.x=0;
    this->direction.y=0;
    this->direction.z=0;

    this->position.x=0;
    this->position.y=0;
    this->position.z=0;
}

void Locomotive::assembler(){

    //glEnable(GL_DEPTH_TEST);
    
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
            glTranslatef(this->longueurTrain*(-0.85f/2.0f), this->hauteurTrain*(1.0f/10.0f), this->largeurTrain*(-0.7f/2.0f));
            glScalef(this->hauteurTrain*(2.5f/10.0f), this->hauteurTrain*(2.5f/10.0f), this->largeurTrain*(2.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 2
        glPushMatrix();
            glColor3f(0.08f, 0.08f, 0.08f);
            glTranslatef(this->longueurTrain*(-0.85f/2.0f), this->hauteurTrain*(1.0f/10.0f), this->largeurTrain*(0.7f/2.0f));
            glScalef(this->hauteurTrain*(2.5f/10.0f), this->hauteurTrain*(2.5f/10.0f), this->largeurTrain*(2.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 3
        glPushMatrix();
            glColor3f(0.08f, 0.08f, 0.08f);
            glTranslatef(this->longueurTrain*(-0.4f/2.0f), this->hauteurTrain*(1.0f/10.0f), this->largeurTrain*(-0.7f/2.0f));
            glScalef(this->hauteurTrain*(2.5f/10.0f), this->hauteurTrain*(2.5f/10.0f), this->largeurTrain*(2.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 4
        glPushMatrix();
            glColor3f(0.08f, 0.08f, 0.08f);
            glTranslatef(this->longueurTrain*(-0.4f/2.0f), this->hauteurTrain*(1.0f/10.0f), this->largeurTrain*(0.7f/2.0f));
            glScalef(this->hauteurTrain*(2.5f/10.0f), this->hauteurTrain*(2.5f/10.0f), this->largeurTrain*(2.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 5
        glPushMatrix();
            glColor3f(0.08f, 0.08f, 0.08f);
            glTranslatef(this->longueurTrain*(0.7f/2.0f), 0, this->largeurTrain*(-0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();

        //ROUE 6
        glPushMatrix();
            glColor3f(0.08f, 0.08f, 0.08f);
            glTranslatef(this->longueurTrain*(0.7f/2.0f), 0, this->largeurTrain*(0.7f/2.0f));
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1, 24, 24);
        glPopMatrix();
 
        //CORPS
        glPushMatrix();
            glColor3f(0.04f, 0.04f, 0.04f);
            glTranslatef(0, this->hauteurTrain*(2.0f/10.0f), 0);
            glScalef(this->longueurTrain, this->hauteurTrain*(1.0f/10.0f), this->largeurTrain*(9.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();   

        //Moteur
        glPushMatrix();
            glColor3f(0.30f, 0.0f, 0.0f);
            glTranslatef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(5.0f/10.0f), 0);
            glScalef(this->longueurTrain*(5.5f/10.0f), this->hauteurTrain*(5.0f/10.0f), this->largeurTrain*(4.5f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //cheminee1
        glPushMatrix();
            glColor3f(0.04f, 0.04f, 0.04f);
            glTranslatef(this->longueurTrain*(2.75f/10.0f), this->hauteurTrain, 0);
            glScalef(this->longueurTrain*(1.0f/10.0f), this->hauteurTrain*(7.0f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //cheminee2
        glPushMatrix();
            glColor3f(0.30f, 0.0f, 0.0f);
            glTranslatef(this->longueurTrain*(2.75f/10.0f), this->hauteurTrain*(13.0f/10.0f), 0);
            glScalef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(2.0f/10.0f), this->largeurTrain*(3.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();


        //Déco
        glPushMatrix();
            glColor3f(1.0f, 0.84f, 0.0f);
            glTranslatef(this->longueurTrain*(1.0f/10.0f), this->hauteurTrain*(6.0f/10.0f), 0);
            glScalef(this->longueurTrain*(4.0f/10.0f), this->hauteurTrain*(1.0f/10.0f), this->largeurTrain*(6.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();


        //Déco2
        glPushMatrix();
            glColor3f(0.04f, 0.04f, 0.04f);
            glTranslatef(this->longueurTrain*(4.0f/10.0f), this->hauteurTrain*(5.35f/10.0f), this->largeurTrain*(4.0f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(5.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //Déco3
        glPushMatrix();
            glColor3f(0.04f, 0.04f, 0.04f);
            glTranslatef(this->longueurTrain*(4.0f/10.0f), this->hauteurTrain*(5.35f/10.0f), -this->largeurTrain*(4.0f/10.0f));
            glScalef(this->longueurTrain*(2.0f/10.0f), this->hauteurTrain*(5.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //Déco moteur
        glPushMatrix();
            glColor3f(0.04f, 0.04f, 0.04f);
            glTranslatef(this->longueurTrain*(0.35f/10.0f), this->hauteurTrain*(7.5f/10.0f), 0);
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1,24,24);
        glPopMatrix();

        //Déco avant
        glPushMatrix();
            glColor3f(1.0f, 0.84f, 0.0f);
            glTranslatef(this->longueurTrain*(4.0f/10.0f), this->hauteurTrain*(5.35f/10.0f), 0);
            glScalef(this->hauteurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidSphere(1,24,24);
        glPopMatrix();

        //Cabine1
        glPushMatrix();
            glColor3f(0.04f, 0.04f, 0.04f);
            glTranslatef(-this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(6.0f/10.0f), this->largeurTrain*(3.5f/10.0f));
            glScalef(this->longueurTrain*(1.0f/10.0f), this->hauteurTrain*(8.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidCube(1);
        glPopMatrix();
   
        //Cabine2
        glPushMatrix();
            glColor3f(0.04f, 0.04f, 0.04f);
            glTranslatef(-this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(6.0f/10.0f), -this->largeurTrain*(3.5f/10.0f));
            glScalef(this->longueurTrain*(1.0f/10.0f), this->hauteurTrain*(8.5f/10.0f), this->largeurTrain*(1.5f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //Cabine3
        glPushMatrix();
            glColor3f(0.30f, 0.0f, 0.0f);
            glTranslatef(-this->longueurTrain*(3.5f/10.0f), this->hauteurTrain*(4.0f/10.0f), -this->largeurTrain*(3.5f/10.0f));
            glScalef(this->longueurTrain*(3.0f/10.0f), this->hauteurTrain*(3.0f/10.0f), this->largeurTrain*(3.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //Cabine4
        glPushMatrix();
            glColor3f(0.30f, 0.0f, 0.0f);
            glTranslatef(-this->longueurTrain*(3.5f/10.0f), this->hauteurTrain*(4.0f/10.0f), this->largeurTrain*(3.5f/10.0f));
            glScalef(this->longueurTrain*(3.0f/10.0f), this->hauteurTrain*(3.0f/10.0f), this->largeurTrain*(3.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //Toit
        glPushMatrix();
            glColor3f(0.04f, 0.04f, 0.04f);
            glTranslatef(-this->longueurTrain*(3.0f/10.0f), this->hauteurTrain, 0);
            glScalef(this->longueurTrain*(4.0f/10.0f), this->hauteurTrain*(1.0f/10.0f), this->largeurTrain*(9.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //ATTACHE 1
        glPushMatrix();
            glColor3f(0.27f, 0.27f, 0.27f);
            glTranslatef(this->longueurTrain*(-5.0f/10.0f), this->hauteurTrain*(3.0f/10.0f), this->largeurTrain*(-2.5f/10.0f));
            glScalef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();

        //ATTACHE 2
        glPushMatrix();
            glColor3f(0.27f, 0.27f, 0.27f);
            glTranslatef(this->longueurTrain*(-5.0f/10.0f), this->hauteurTrain*(3.0f/10.0f), this->largeurTrain*(2.5f/10.0f));
            glScalef(this->longueurTrain*(1.5f/10.0f), this->hauteurTrain*(1.5f/10.0f), this->largeurTrain*(2.0f/10.0f));
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
    
}

void Locomotive::dessiner(){
    
}

void Locomotive::deplacer(float x, float y, float z){
    this->position.x=x;
    this->position.y=y;
    this->position.z=z;
}

void Locomotive::orienter(float x, float y, float z){
    this->direction.x=x;
    this->direction.y=y;
    this->direction.z=z;
}

Vecteur Locomotive::getMilieuRouesAvant(){
    return this->direction;
}

float Locomotive::getLongueurRouePrevRoueSuiv(){
    return this->longueurTrain+this->longueurTrain*(1.5f/10.0f);
}