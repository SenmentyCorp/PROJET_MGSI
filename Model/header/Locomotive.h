#ifndef LOCOMOTIVE_H_
#define LOCOMOTIVE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Vecteur.h"

class Locomotive{

    public:
        Locomotive();
        void assembler();
        void dessiner();
        void deplacer(float x, float y, float z);
        void orienter(float x, float y, float z);
        Vecteur getMilieuRouesAvant();
        Vecteur getMilieuRouesArriere();
        float getLongueurRouePrevRoueSuiv();
        float getLongueurTrain();
        float getLargeurTrain();
        
        Vecteur direction;

        Vecteur position;

    private:
        const float largeurTrain=80;
        const float longueurTrain=250;
        const float hauteurTrain=100;
        Vecteur positionRoueAvant;
        Vecteur positionRoueArriere;
};

#endif