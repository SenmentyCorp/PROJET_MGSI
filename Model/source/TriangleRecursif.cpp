//
// Created by Alex-PC on 01/10/2019.
//

#include "../header/TriangleRecursif.h"

TriangleRecursif::TriangleRecursif(float x, float y, float longueur, int degre) {
    t1 = this->buildRecursif(x, y, longueur, degre);
}

bool TriangleRecursif::dedans(float x, float y) {
    return t1->dedans(x, y);
}

Figure* TriangleRecursif::buildRecursif(float x, float y, float longueur, int degre) {
    if(degre == 0){
        Translation *trPremier = new Translation(new Scale(new TriangleTroue, longueur, longueur), x, y);

        Translation *tr1 = new Translation(new Scale(new TriangleTroue, longueur/2, longueur/2), x, y);
        Translation *tr2 = new Translation(new Scale(new TriangleTroue, longueur/2, longueur/2), x+(longueur/2), y);
        Translation *tr3 = new Translation(new Scale(new TriangleTroue, longueur/2, longueur/2), x+(longueur/4), y+sinf(M_PI/3)/(1/longueur*2));

        //Figure *res = new Intersection(trPremier, new Intersection(tr1, tr2) );

        return new Union(new Intersection(trPremier, tr1), new Union(new Intersection(trPremier,tr2), new Intersection(trPremier, tr3)));
    }else{
        Figure *trPremier = buildRecursif(x, y, longueur, 0);

        Figure *t1 = buildRecursif(x, y, longueur/2, degre-1);
        Figure *t2 = buildRecursif(x+(longueur/2), y, longueur/2, degre-1);
        Figure *t3 = buildRecursif(x+(longueur/4), y+sinf(M_PI/3)/(1/longueur*2), longueur/2, degre-1);

        return new Union(new Intersection(trPremier, t1), new Union(new Intersection(trPremier,t2), new Intersection(trPremier, t3)));
    }
}