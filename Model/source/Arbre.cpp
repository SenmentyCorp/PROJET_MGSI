#include "../header/Arbre.h"

Arbre::Arbre(){
    this->direction.x=0;
    this->direction.y=0;
    this->direction.z=0;

    this->position.x=0;
    this->position.y=0;
    this->position.z=0;

    this->hauteurArbre=60;
    this->rayonArbre=25;
    this->ech=1;
}

void Arbre::assembler(){
    
    glPushMatrix();


        glTranslatef(this->position.x, this->position.y, this->position.z);
        glTranslatef(this->rayonArbre*(0.5f/1.0f), 0, this->rayonArbre*(0.5f/1.0f));

        glRotatef(this->direction.z, 0, 0, 1);
        glRotatef(this->direction.y, 0, 1, 0);
        glRotatef(this->direction.x, 1, 0, 0);

        glScalef(this->ech, this->ech, this->ech);


        //PREMIER CONE
        glPushMatrix();
            glColor3f(0.1f, 0.4f, 0.1f);
            glTranslatef(0, this->hauteurArbre*(0.2f/1.0f)*this->hauteurArbre*(1.0f/5.0f), 0);
            glScalef(this->rayonArbre*(0.9f/5.0f), this->hauteurArbre*(0.5f/5.0f), this->rayonArbre*(0.9f/5.0f));
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(this->rayonArbre, this->hauteurArbre*(0.4f/1.0f), 24, 24);
        glPopMatrix();

        //DEUXIEME CONE
        glPushMatrix();
            glColor3f(0.05f, 0.2f, 0.05f);
            glTranslatef(0, this->hauteurArbre*(0.27f/1.0f)*this->hauteurArbre*(1.0f/5.0f), 0);
            glScalef(this->rayonArbre*(0.8f/5.0f), this->hauteurArbre*(0.5f/5.0f), this->rayonArbre*(0.8f/5.0f));
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(this->rayonArbre, this->hauteurArbre*(0.4f/1.0f), 24, 24);
        glPopMatrix();

        //TROISIEME CONE
        glPushMatrix();
            glColor3f(0.1f, 0.4f, 0.1f);
            glTranslatef(0, this->hauteurArbre*(0.34f/1.0f)*this->hauteurArbre*(1.0f/5.0f), 0);
            glScalef(this->rayonArbre*(0.7f/5.0f), this->hauteurArbre*(0.45f/5.0f), this->rayonArbre*(0.7f/5.0f));
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(this->rayonArbre, this->hauteurArbre*(0.4f/1.0f), 24, 24);
        glPopMatrix();

        //QUATRIEME CONE
        glPushMatrix();
            glColor3f(0.05f, 0.2f, 0.05f);
            glTranslatef(0, this->hauteurArbre*(0.41f/1.0f)*this->hauteurArbre*(1.0f/5.0f), 0);
            glScalef(this->rayonArbre*(0.6f/5.0f), this->hauteurArbre*(0.45f/5.0f), this->rayonArbre*(0.6f/5.0f));
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(this->rayonArbre, this->hauteurArbre*(0.4f/1.0f), 24, 24);
        glPopMatrix();

        //CINQUIEME CONE
        glPushMatrix();
            glColor3f(0.1f, 0.4f, 0.1f);
            glTranslatef(0, this->hauteurArbre*(0.48f/1.0f)*this->hauteurArbre*(1.0f/5.0f), 0);
            glScalef(this->rayonArbre*(0.5f/5.0f), this->hauteurArbre*(0.4f/5.0f), this->rayonArbre*(0.5f/5.0f));
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(this->rayonArbre, this->hauteurArbre*(0.4f/1.0f), 24, 24);
        glPopMatrix();

        //TRONC
        glPushMatrix();
            glColor3f(0.25f, 0.12f, 0.05f);
            glTranslatef(0, this->rayonArbre*(0.5f/2.0f)*this->hauteurArbre*(3.0f/5.0f), 0);
            glScalef(this->rayonArbre*(1.0f/5.0f), this->hauteurArbre*(3.0f/5.0f), this->rayonArbre*(1.0f/5.0f));
            glutSolidSphere(this->rayonArbre*(0.5f/2.0f), 24, 5);
        glPopMatrix();
          

    glPopMatrix();
    
}

void Arbre::deplacer(float x, float y, float z){
    this->position.x=x;
    this->position.y=y;
    this->position.z=z;
}

void Arbre::orienter(float x, float y, float z){
    this->direction.x=x;
    this->direction.y=y;
    this->direction.z=z;
}

void Arbre::modifierTaille(float sc){
    this->ech = sc;
}