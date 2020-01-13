#ifndef ARBRE_H_
#define ARBRE_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include "Vecteur.h"

class Arbre{

    public:
        Arbre();
        void assembler();
        void deplacer(float x, float y, float z);
        void orienter(float x, float y, float z);
        void modifierTaille(float sc);
        
        Vecteur direction;

        Vecteur position;

    private:
        float hauteurArbre;
        float rayonArbre;
        float ech;
};

#endif