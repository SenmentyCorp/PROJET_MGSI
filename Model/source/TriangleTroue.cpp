#include "../header/TriangleTroue.h"
#include "../header/DemiPlan.h"
#include "../header/Intersection.h"
#include "../header/Rotation.h"
#include "../header/Translation.h"

TriangleTroue::TriangleTroue(){

    //Triangle Principal non troué
    dp1 = new DemiPlan;
    dp2 = new DemiPlan;
    dp2Bis = new DemiPlan;

    r1 = new Rotation(dp1,2*M_PI/3);
    r2 = new Rotation(dp2,-2*M_PI/3);

    t2 = new Translation(r2, 0, 0);
    t1 = new Translation(r1, 1, 0);

    i1 = new Intersection(new Intersection(dp2Bis, t2), t1);

    //Dessin des demi-plans du milieu
    dp3 = new DemiPlan;
    dp4 = new DemiPlan;
    dp5 = new DemiPlan;

    r3 = new Rotation(dp3,2*M_PI/3);
    r4 = new Rotation(dp4,-2*M_PI/3);

    t3 = new Translation(r3, 0.5, 0);
    t4 = new Translation(r4, 0.5, 0);
    t5 = new Translation(dp5, 0, sinf(M_PI/3)/2);

    u1 = new Union(t3, new Union(t4, t5));

    i2 = new Intersection(i1, u1);

}

bool TriangleTroue::dedans(float x, float y){
    return i2->dedans(x, y);
}

