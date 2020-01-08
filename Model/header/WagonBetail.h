#ifndef WAGONBETAIL_H_
#define WAGONBETAIL_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Vecteur.h"

class WagonBetail{

    public:
        WagonBetail();
        void assembler();
        void deplacer(float x, float y, float z);
        void orienter(float x, float y, float z);
        Vecteur getMilieuRouesAvant();
        float getLongueurRouePrevRoueSuiv();
        
        Vecteur direction;

        Vecteur position;

    private:
        const float largeurTrain=80;
        const float longueurTrain=250;
        const float hauteurTrain=100;
        float decalageAttache;
        float coeffLongueurTrain;
        Vecteur positionRoueAvant;
        Vecteur positionRoueArriere;
};

#endif